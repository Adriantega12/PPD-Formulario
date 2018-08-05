#ifndef FOOT_H
#define FOOT_H

#include <QString>

class Foot {
    public:
        static const int NUMBER_OF_ATTRIBUTES = 15;
        static const QString LABEL[NUMBER_OF_ATTRIBUTES];
        enum DermatologicalLabels {
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
    };

#endif // FOOT_H
