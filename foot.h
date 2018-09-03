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
        static const int NUMBER_OF_ATTRIBUTES = 15;
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
            OTHERS,
            ANHIDROSIS,
            TILIAS,
            INFECTIVE_PROCESS
            };

        Foot();
        ~Foot();

        void setId( int );
        void setOwnerId( int );
        void setDermatologicalValue( int, DermatologicalLabel );

        int getId() const;
        int getOwnerId() const;
        int getDermatologicalValue( DermatologicalLabel );
    };

#endif // FOOT_H
