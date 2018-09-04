#ifndef FOOT_H
#define FOOT_H

#include <QString>
#include <QDebug>

#include <vector>

class Foot {
    private:
        int id;
        int ownerId;
        std::vector<int> dermatologicalValues;

    public:
        static const int NUMBER_OF_ATTRIBUTES = 14;
        static const QString LABEL[NUMBER_OF_ATTRIBUTES];
        enum DermatologicalLabel {
            PLANTAR = 0,
            DORSAL,
            TALAR,
            ONYCHOCRYPTOSIS,
            ONYCHOMYCOSIS,
            ONYCHOGYPHOSIS,
            BULLOSIS,
            ULCER,
            NECROSIS,
            CRACKS_AND_FISSURES,
            SUPERFICIAL_INJURY,
            //OTHERS,
            ANHIDROSIS,
            TILIAS,
            INFECTIVE_PROCESS
            };

        Foot( int );
        ~Foot();

        void setId( int );
        void setOwnerId( int );
        void setDermatologicalValue( int, int );

        int getId() const;
        int getOwnerId() const;
        int getDermatologicalValue( DermatologicalLabel );

        void insertDermatologicalValue( int );
    };

#endif // FOOT_H
