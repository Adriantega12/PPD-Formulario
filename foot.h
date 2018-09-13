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
        std::vector<int> dermatologicalValues;

    public:
        Foot( int );
        ~Foot();

        void setId( int );
        void setOwnerId( int );
        void setDermatologicalValue( int, int );

        int getId() const;
        int getOwnerId() const;
        int getDermatologicalValue( FeetExam::Dermatological );

        void insertDermatologicalValue( int );
    };

#endif // FOOT_H
