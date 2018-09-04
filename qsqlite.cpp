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

    query.prepare( "CREATE TABLE IF NOT EXISTS Paciente ("
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

    query.prepare( "CREATE TABLE IF NOT EXISTS Pie ("
                   "id INTEGER PRIMARY KEY,"
                   "owner_id INTEGER,"
                   "plantar_grade INTEGER,"
                   "dorsal_grade INTEGER,"
                   "talar_grade INTEGER,"
                   "onychocryptosis_grade INTEGER,"
                   "onychomycosis_grade INTEGER,"
                   "onychogeilosis_grade INTEGER,"
                   "bullosis_grade INTEGER,"
                   "ulcer_grade INTEGER,"
                   "necrosis_grade INTEGER,"
                   "cAndF_grade INTEGER,"
                   "injury_grade INTEGER,"
                   "anhidrosis_grade INTEGER,"
                   "tilias_grade INTEGER,"
                   "infectiveProcess_grade INTEGER,"
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
        query.prepare( QString("INSERT INTO Paciente VALUES(NULL, %1, '%2', %3, '%4', '%5', '%6', '%7');")
                       .arg(fileNum).arg(name).arg(age).arg(genre).arg(patology).arg(date).arg(imgPath) );

        if ( !( success = query.exec() ) ) {
            qDebug() << query.lastError();
            }
        }

    return success;
    }

bool QSQLite::insertFoot( int ownerId, int pG, int dG, int tG, int onychocryptG, int onychomyG, int onychogeG,
                          int bG, int uG, int nG, int cFG, int iG, int aG, int tiG, int iPG ) {
    bool success;
    QSqlQuery query;

    if ( db.isOpen() ) {
        query.prepare( QString( "INSERT INTO Pie VALUES(NULL, %1, %2, %3, %4, %5, %6, %7, %8,"
                               "%9, %10, %11, %12, %13, %14, %15);" )
                                .arg(ownerId).arg(pG).arg(dG).arg(tG).arg(onychocryptG)
                                .arg(onychomyG).arg(onychogeG).arg(bG).arg(uG).arg(nG)
                                .arg(cFG).arg(iG).arg(aG).arg(tiG).arg(iPG) );

        if ( !( success = query.exec() ) ) {
            qDebug() << query.lastError();
            }
        }

    return success;
    }

Patient* QSQLite::getPatientById( int id ) {
    Patient* patientPtr = nullptr;
    QSqlQuery query;

    query.prepare(QString("SELECT * FROM Paciente WHERE id = %1").arg(id));

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
