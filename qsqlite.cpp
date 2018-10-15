#include "qsqlite.h"

QSQLite::QSQLite() {

    }

bool QSQLite::initializeSQLiteDB( QString name ) {
    bool success;
    dbName = name;

    if ( (success = openDB()) ) {
        qDebug() << "Database connection: Ok";
        }
    else {
        qDebug() << "Error: Connection with database failed.";
        }

    // Inicializar base de datos
    createPatientTable();
    createFootTable();

    return success;
    }

bool QSQLite::openDB() {
    // Encontrar el controlador de SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Establecer nombre de la base de datos
    db.setDatabaseName(dbName);

    // Abrir base de datos
    return db.open();
    }

void QSQLite::closeDB() {
    db.close();
    }

bool QSQLite::deleteDB() {
    return true;
    }

QSqlError QSQLite::lastError() {
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
    }

int QSQLite::getNumberOfPatients() {
    QSqlQuery query;
    int count = -1;

    query.prepare( QString("SELECT COUNT(*) FROM Paciente") );

    if ( query.exec() ) {

        // Existe
        if ( query.next() ) {
            count = query.value(0).toInt();
            }
        }

    return count;
    }

bool QSQLite::createPatientTable() {
    bool success = false;
    QSqlQuery query;

    query.prepare( "CREATE TABLE IF NOT EXISTS paciente ("
                   "id INTEGER PRIMARY KEY,"
                   "file_num INTEGER,"
                   "name VARCHAR(50),"
                   "age INTEGER,"
                   "gender VARCHAR(2),"
                   "patology VARCHAR(50),"
                   "date TEXT,"
                   "img_path VARCHAR(50)"
                   ");" );

    if ( !(success = query.exec()) ) {
        qDebug() << "Error: Patient table might already exists.";
        }

    return success;
    }

bool QSQLite::createFootTable() {
    bool success = false;
    QSqlQuery query;

    query.prepare( "CREATE TABLE IF NOT EXISTS pie ("
                   "id INTEGER PRIMARY KEY,"
                   "owner_id INTEGER,"
                   "plantar INTEGER,"
                   "dorsal INTEGER,"
                   "talar INTEGER,"
                   "onychocryptosis INTEGER,"
                   "onychomycosis INTEGER,"
                   "onychogyphosis INTEGER,"
                   "bullosis INTEGER,"
                   "ulcer INTEGER,"
                   "necrosis INTEGER,"
                   "cracks_and_fissures INTEGER,"
                   "superficial_injury INTEGER,"
                   "anhidrosis INTEGER,"
                   "tilias INTEGER,"
                   "infective_process INTEGER,"
                   "claw_fingers INTEGER,"
                   "hallux_valgus INTEGER,"
                   "hammer_toes INTEGER,"
                   "infraduct INTEGER,"
                   "supraduct INTEGER,"
                   "metatarsal INTEGER,"
                   "charcot INTEGER,"
                   "pedio INTEGER,"
                   "capillary INTEGER,"
                   "varicose INTEGER,"
                   "edema INTEGER,"
                   "tactile INTEGER,"
                   "vibratory INTEGER,"
                   "reflex INTEGER,"
                   "dorsiflexion INTEGER,"
                   "ortejos INTEGER,"
                   "FOREIGN KEY (owner_id) REFERENCES Paciente(id)"
                   ");" );

    if ( !(success = query.exec()) ) {
        qDebug() << "Error: Patient table might already exists.";
        }

    return success;
    }

bool QSQLite::insertPatient( int fileNum, QString name, int age, QString genre, QString patology, QString date, QString imgPath ) {
    bool success;
    QSqlQuery query;

    if ( db.isOpen() ) {
        query.prepare( QString("INSERT INTO paciente VALUES(NULL, %1, '%2', %3, '%4', '%5', '%6', '%7');")
                       .arg(fileNum).arg(name).arg(age).arg(genre).arg(patology).arg(date).arg(imgPath) );

        if ( !( success = query.exec() ) ) {
            qDebug() << query.lastError();
            }
        }

    return success;
    }

bool QSQLite::insertFoot( int ownerId, QVector<unsigned int> attribs ) {
    bool success;
    QSqlQuery query;
    QString queryString = "INSERT INTO pie VALUES(NULL," + QString::number(ownerId) + ",";

    for ( unsigned int i = 0; i < attribs.length(); ++i ) {
        queryString += QString::number(attribs[i]) + (i + 1 != attribs.length() ? "," : ");");
        }

    if ( db.isOpen() ) {
        query.prepare( queryString );

        if ( !( success = query.exec() ) ) {
            qDebug() << query.lastError();
            }
        }

    return success;
    }

Patient* QSQLite::getPatientById( int id ) {
    Patient* patientPtr = nullptr;
    QSqlQuery query;

    query.prepare(QString("SELECT * FROM paciente WHERE id = %1").arg(id));

    if ( query.exec() ) {

        // Existe
        if ( query.next() ) {
            patientPtr = new Patient( query.value("id").toInt(),
                                      query.value("file_num").toInt(),
                                      query.value("name").toString(),
                                      query.value("age").toInt(),
                                      query.value("gender").toString(),
                                      query.value("patology").toString(),
                                      query.value("date").toString(),
                                      query.value("img_path").toString() );
            }
        }

    return patientPtr;
    }

Patient* QSQLite::getPatientByFileNumber( int ) {
    return nullptr;
    }

std::vector<Foot*> QSQLite::getFeetByPatientId( int patientId ) {
    std::vector<Foot*> feet;
    Foot* footPtr = nullptr;
    QString queryString = "SELECT * FROM pie WHERE owner_id = %1;";
    qDebug() << queryString.arg(patientId);
    QSqlQuery query(queryString);

    qDebug() << query.size();

    //query.prepare(QString("SELECT * FROM pie WHERE owner_id = %1").arg(patientId));
    if (query.exec())
        while ( query.next() ) {
            footPtr = new Foot(patientId);
            footPtr->setId( query.value("id").toInt() );
            for (int i = 2; i < FeetExam::TOTAL_ATTRIBS + 2; ++i) {
                footPtr->setExamValue(query.value(i).toInt(), i - 2);
                }
            feet.push_back(footPtr);
            }

    return feet;
    }

std::vector<Patient*> QSQLite::getAllPatients() {
    std::vector<Patient*> patients;
    QSqlQuery query("SELECT * FROM Paciente;");

    int id;
    int fileNumber;
    QString name;
    int age;
    QString gender;
    QString patology;
    QString date;
    QString imgPath;

    while ( query.next() ) {
        id = query.value("id").toInt();
        fileNumber = query.value("file_num").toInt();
        name = query.value("name").toString();
        age = query.value("age").toInt();
        gender = query.value("gender").toString();
        patology = query.value("patology").toString();
        date = query.value("date").toString();
        imgPath = query.value("img_path").toString();
        patients.push_back( new Patient( id, fileNumber, name, age, gender, patology, date, imgPath ) );
        }

    return patients;
    }
