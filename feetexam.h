#ifndef FEETEXAM_H
#define FEETEXAM_H

#include <QString>

class FeetExam {
    private:


    public:
        enum Dermatological {
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
            ANHIDROSIS,
            TILIAS,
            INFECTIVE_PROCESS
            };

        enum Bone {
            CLAW_FINGERS = 0,
            HALLUX_VALGUS,
            HAMMER_TOES,
            INFRADUCT,
            SUPRADUCT,
            METATARSAL,
            CHARCOT
            };

        enum Vascular {
            PEDIO,
            CAPILLARY,
            VARICOSE,
            EDEMA
            };

        enum Neurological {
            TACTILE,
            VIBRATORY,
            REFLEX,
            DORSIFLEXION,
            ORTEJOS
            };

        static const int NUM_DERMA = Dermatological::INFECTIVE_PROCESS + 1;
        static const int NUM_BONE = Bone::CHARCOT + 1;
        static const int NUM_VASCULAR = Vascular::EDEMA + 1;
        static const int NUM_NEURO = Neurological::ORTEJOS + 1;

        static const QString DERMATOLOGICAL_LABELS[NUM_DERMA];
        static const QString BONE_LABELS[NUM_BONE];
        static const QString VASCULAR_LABELS[NUM_VASCULAR];
        static const QString NEUROLOGICAL_LABELS[NUM_NEURO];

        FeetExam();
    };

#endif // FEETEXAM_H
