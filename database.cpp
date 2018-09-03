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

// int fileNum, QString name, int age, QString genre, QString patology, QString date, QString imgPath
bool Database::insertPatient( Patient& p ) {
    bool success =Database::db.insertPatient( p.getFileNum(), p.getName(), p.getAge(), p.getGender(), p.getPatology(),
                                             p.getDate(), p.getImgPath() );
    return success;
    }

bool  Database::insertFoot() {
    return true;
    }

Patient* Database::getPatientById( int id ) {
    return Database::db.getPatientById( id );
    }
