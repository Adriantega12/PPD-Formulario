#include "feetexam.h"

const QString FeetExam::DERMATOLOGICAL_LABELS[FeetExam::NUM_DERMA] = {
    "Plantar",
    "Dorsal",
    "Talar",
    "Onicocriptosis",
    "Onicomicosis",
    "Onicogrifosis",
    "Bullosis",
    "Úlcera",
    "Necrosis",
    "Grietas y fisuras",
    "Lesión superficial",
    "Anhidrosis",
    "Tilias",
    "Proceso infeccioso"
    };

const QString FeetExam::BONE_LABELS[FeetExam::NUM_BONE] = {
    "Dedos en garra",
    "Hallux Valgus",
    "Dedos en martillo",
    "Infraducto",
    "Supraducto",
    "Hipercargas bajo metatarsianos",
    "Pie de Charcot"
    };

const QString FeetExam::VASCULAR_LABELS[FeetExam::NUM_VASCULAR] = {
    "Pulso pedio",
    "Llenado capilar",
    "Varices",
    "Edema"
    };

const QString FeetExam::NEUROLOGICAL_LABELS[FeetExam::NUM_NEURO] = {
    "Sensibilidad tactil",
    "Sensibilidad vibratoria",
    "Reflejo rotuliano",
    "Dorsiflexión del pie",
    "Apertura ortejos en abanico"
    };

void FeetExam::setupExam(QWidget* tab, const QString labels[], int numLabels,
                         std::function<void(int, QFormLayout*, QFormLayout*)> func,
                         std::vector<int>* data) {
    QHBoxLayout* lo = new QHBoxLayout;
    QFormLayout* rightLO = new QFormLayout;
    QFormLayout* leftLO = new QFormLayout;
    QStringList items = (QStringList() << "0" << "1" << "2");
    QComboBox* cbL;
    QComboBox* cbR;

    lo->addLayout( rightLO );
    lo->addLayout( leftLO );

    tab->setLayout( lo );

    for ( int i = 0; i < numLabels; ++i ) {
        cbL = cbR = nullptr;

        cbL = new QComboBox();
        cbR = new QComboBox();
        cbL->addItems(items);
        cbR->addItems(items);
        /*
        rightFoot.push_back( cbR );
        leftFoot.push_back( cbL );
        */

        rightLO->addRow( new QLabel(labels[i]), cbR );
        leftLO->addRow( new QLabel(labels[i]), cbL );

        func(i, rightLO, leftLO);
        }
    }

FeetExam::FeetExam() {

    }

void FeetExam::setupDermatologicalExam(QWidget* tab, std::vector<int>* data ) {
    setupExam(tab, DERMATOLOGICAL_LABELS, NUM_DERMA, [](int index, QFormLayout* rightLO, QFormLayout* leftLO) {
        if ( index == Dermatological::SUPERFICIAL_INJURY ) {
            rightLO->addRow( new QLabel("Otras difusas: ") );
            leftLO->addRow( new QLabel("Otras difusas: ") );
            }
        }, data);
    }

void FeetExam::setupBoneStructureExam(QWidget* tab, std::vector<int>* data ) {
    setupExam(tab, BONE_LABELS, NUM_BONE, [](int, QFormLayout*, QFormLayout*) { }, data);
    }

void FeetExam::setupVascularExam(QWidget* tab, std::vector<int>* data) {
    setupExam(tab, VASCULAR_LABELS, NUM_VASCULAR, [](int, QFormLayout*, QFormLayout*) { }, data);
    }

void FeetExam::setupNeurologicalExam(QWidget* tab, std::vector<int>* data) {
    setupExam(tab, NEUROLOGICAL_LABELS, NUM_NEURO, [](int, QFormLayout*, QFormLayout*) { }, data);
    }
