#ifndef DATABASE_H
#define DATABASE_H

#include <QString>

// La intención es que la base de datos sea lo más modular posible para que se pueda migrar de ser necesario
#include "qsqlite.h"
#include "patient.h"

/*class QSQLite;
class Patient;
class Foot;*/

class Database {
    private:
        static QString dbName;
        static QSQLite db;

    public:
        Database();

        static bool openDatabase();
        static void closeDatabase();

        static int getNumberOfPatients();

        static bool insertPatient( Patient& );
        static bool insertFoot( Foot& );

        static Patient* getPatientById( int );
        static Patient* getPatientByFileNumber( int );
        static std::vector<Patient*> getAllPatients();
    };

#endif // DATABASE_H
