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

FeetExam::FeetExam() {

    }
