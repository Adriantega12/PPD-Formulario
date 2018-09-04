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
                                            f.getDermatologicalValue( Foot::PLANTAR ),
                                            f.getDermatologicalValue( Foot::DORSAL ),
                                            f.getDermatologicalValue( Foot::TALAR ),
                                            f.getDermatologicalValue( Foot::ONYCHOCRYPTOSIS ),
                                            f.getDermatologicalValue( Foot::ONYCHOMYCOSIS ),
                                            f.getDermatologicalValue( Foot::ONYCHOGYPHOSIS ),
                                            f.getDermatologicalValue( Foot::BULLOSIS ),
                                            f.getDermatologicalValue( Foot::ULCER ),
                                            f.getDermatologicalValue( Foot::NECROSIS ),
                                            f.getDermatologicalValue( Foot::CRACKS_AND_FISSURES ),
                                            f.getDermatologicalValue( Foot::SUPERFICIAL_INJURY ),
                                            f.getDermatologicalValue( Foot::ANHIDROSIS ),
                                            f.getDermatologicalValue( Foot::TILIAS ),
                                            f.getDermatologicalValue( Foot::INFECTIVE_PROCESS ));

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
