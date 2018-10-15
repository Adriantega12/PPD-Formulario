#include "database.h"

QString Database::dbName = "";
QSQLite Database::db;

Database::Database() {

    }

bool Database::openDatabase() {
    Database::dbName = "ppd.db";
    return Database::db.initializeSQLiteDB( dbName );
    }

void Database::closeDatabase() {
    Database::db.closeDB();
    }

int Database::getNumberOfPatients() {
    return Database::db.getNumberOfPatients();
    }

int Database::getNumberOfFeet() {
    return 1;//Database::db.getNumberOfFeet();
    }

bool Database::insertPatient( Patient& p ) {
    bool success =Database::db.insertPatient( p.getFileNum(), p.getName(), p.getAge(), p.getGender(), p.getPatology(),
                                             p.getDate(), p.getImgPath() );
    return success;
    }

bool  Database::insertFoot( Foot& f ) {
    QVector<unsigned int> values;
    bool success;

    for (int i = 0; i < FeetExam::TOTAL_ATTRIBS; ++i) {
        values.push_back(f.getExamValue(i));
        }

    success = Database::db.insertFoot(f.getOwnerId(), values);

    return success;
    }

Patient* Database::getPatientById( int id ) {
    return Database::db.getPatientById( id );
    }

Patient* Database::getPatientByFileNumber( int num ) {
    return nullptr;
    }

std::vector<Foot*> Database::getFeetByPatientId(int id) {
    return Database::db.getFeetByPatientId(id);
    }

std::vector<Patient*> Database::getAllPatients() {
    return Database::db.getAllPatients();
    }
