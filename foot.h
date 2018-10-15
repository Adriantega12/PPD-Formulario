#ifndef FOOT_H
#define FOOT_H

#include <QString>
#include <QDebug>

#include <vector>

#include "feetexam.h"

class Foot {
    private:
        int id;
        int ownerId;
        std::vector<int> examValues;

    public:
        Foot( int );
        ~Foot();

        void setId( int );
        void setOwnerId( int );
        void setExamValue( int, int );

        int getId() const;
        int getOwnerId() const;
        int getExamValue( int );

        void insertDermatologicalValue( int );
    };

#endif // FOOT_H
