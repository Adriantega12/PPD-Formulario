#ifndef FEETEXAM_H
#define FEETEXAM_H

#include <QString>
#include <QWidget>
#include <QFormLayout>
#include <QComboBox>
#include <QLabel>
#include <QVector>

#include <functional>

class FeetExam {
    private:
        static void setupExam(QWidget*,
                              QVector<QComboBox*>&,
                              QVector<QComboBox*>&,
                              const QString[],
                              int,
                              std::function<void(int, QFormLayout*, QFormLayout*)>,
                              std::vector<int>* = nullptr);

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
            CLAW_FINGERS = INFECTIVE_PROCESS + 1,
            HALLUX_VALGUS,
            HAMMER_TOES,
            INFRADUCT,
            SUPRADUCT,
            METATARSAL,
            CHARCOT
            };

        enum Vascular {
            PEDIO = CHARCOT + 1,
            CAPILLARY,
            VARICOSE,
            EDEMA
            };

        enum Neurological {
            TACTILE = EDEMA + 1,
            VIBRATORY,
            REFLEX,
            DORSIFLEXION,
            ORTEJOS
            };


        static const int NUM_DERMA = Dermatological::INFECTIVE_PROCESS + 1;
        static const int NUM_BONE = Bone::CHARCOT - Dermatological::INFECTIVE_PROCESS;
        static const int NUM_VASCULAR = Vascular::EDEMA - Bone::CHARCOT;
        static const int NUM_NEURO = Neurological::ORTEJOS - Vascular::EDEMA;

        static const int TOTAL_ATTRIBS = Neurological::ORTEJOS + 1;


        static const QString DERMATOLOGICAL_LABELS[NUM_DERMA];
        static const QString BONE_LABELS[NUM_BONE];
        static const QString VASCULAR_LABELS[NUM_VASCULAR];
        static const QString NEUROLOGICAL_LABELS[NUM_NEURO];

        FeetExam();

        static void setupDermatologicalExam( QWidget*, QVector<QComboBox*>&, QVector<QComboBox*>&, std::vector<int>* = nullptr );
        static void setupBoneStructureExam(QWidget*, QVector<QComboBox*>&, QVector<QComboBox*>&, std::vector<int>* = nullptr );
        static void setupVascularExam(QWidget*, QVector<QComboBox*>&, QVector<QComboBox*>&, std::vector<int>* = nullptr );
        static void setupNeurologicalExam(QWidget*, QVector<QComboBox*>&, QVector<QComboBox*>&, std::vector<int>* = nullptr );


    };

#endif // FEETEXAM_H
