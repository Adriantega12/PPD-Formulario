#ifndef DATABASE_H
#define DATABASE_H

#include <QString>

// La intención es que la base de datos sea lo más modular posible para que se pueda migrar de ser necesario
#include "qsqlite.h"

#include "patient.h"

class Database {
    private:
        static QString dbName;
        static QSQLite db;

    public:
        Database();

        static bool openDatabase();
        static void closeDatabase();

        static bool insertPatient( Patient& );
        static bool insertFoot();

        static Patient* getPatientById( int );
    };

#endif // DATABASE_H
