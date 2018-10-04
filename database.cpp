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

bool Database::insertPatient( Patient& p ) {
    bool success =Database::db.insertPatient( p.getFileNum(), p.getName(), p.getAge(), p.getGender(), p.getPatology(),
                                             p.getDate(), p.getImgPath() );
    return success;
    }

bool  Database::insertFoot( Foot& f ) {
    bool success = Database::db.insertFoot( f.getOwnerId(),
                                            f.getDermatologicalValue( FeetExam::PLANTAR ),
                                            f.getDermatologicalValue( FeetExam::DORSAL ),
                                            f.getDermatologicalValue( FeetExam::TALAR ),
                                            f.getDermatologicalValue( FeetExam::ONYCHOCRYPTOSIS ),
                                            f.getDermatologicalValue( FeetExam::ONYCHOMYCOSIS ),
                                            f.getDermatologicalValue( FeetExam::ONYCHOGYPHOSIS ),
                                            f.getDermatologicalValue( FeetExam::BULLOSIS ),
                                            f.getDermatologicalValue( FeetExam::ULCER ),
                                            f.getDermatologicalValue( FeetExam::NECROSIS ),
                                            f.getDermatologicalValue( FeetExam::CRACKS_AND_FISSURES ),
                                            f.getDermatologicalValue( FeetExam::SUPERFICIAL_INJURY ),
                                            f.getDermatologicalValue( FeetExam::ANHIDROSIS ),
                                            f.getDermatologicalValue( FeetExam::TILIAS ),
                                            f.getDermatologicalValue( FeetExam::INFECTIVE_PROCESS ));

    return success;
    }

Patient* Database::getPatientById( int id ) {
    return Database::db.getPatientById( id );
    }

Patient* Database::getPatientByFileNumber( int num ) {
    return nullptr;
    }

std::vector<Patient*> Database::getAllPatients() {
    return Database::db.getAllPatients();
    }
