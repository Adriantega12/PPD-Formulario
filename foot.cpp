#include "foot.h"

const QString Foot::LABEL[Foot::NUMBER_OF_ATTRIBUTES] = {
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
    "Otras difusas",
    "Anhidrosis",
    "Tilias",
    "Proceso infeccioso"
    };

Foot::Foot() {
    dermatologicalValues.reserve( NUMBER_OF_ATTRIBUTES - 1 );
    }

Foot::~Foot() {
    dermatologicalValues.clear();
    }

void Foot::setId( int _id ) {
    id = _id;
    }

void Foot::setOwnerId( int _oId ) {
    ownerId = _oId;
    }

void Foot::setDermatologicalValue( int val, DermatologicalLabel index ) {
    if ( index < 0 or index == DermatologicalLabel::OTHERS or index >= NUMBER_OF_ATTRIBUTES ) {
        qDebug() << "Error: Can't overwrite at asked index.";
        return;
        }

    dermatologicalValues[(index < DermatologicalLabel::OTHERS ?
                              index : index - 1)] = val;
    }

int Foot::getId() const {
    return id;
    }

int Foot::getOwnerId() const {
    return ownerId;
    }

int Foot::getDermatologicalValue( DermatologicalLabel index ) {
    if ( index < 0 or index == DermatologicalLabel::OTHERS or index >= NUMBER_OF_ATTRIBUTES ) {
        qDebug() << "Error: Can't read from that index.";
        return -1;
        }

    return dermatologicalValues.at((index < DermatologicalLabel::OTHERS ? index : index - 1));
    }
