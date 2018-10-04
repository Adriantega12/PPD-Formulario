#include "foot.h"

Foot::Foot( int oId ) :
    ownerId(oId) {
    //dermatologicalValues.reserve(Foot::NUMBER_OF_ATTRIBUTES - 1);
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

void Foot::setDermatologicalValue( int val, int index ) {
    dermatologicalValues[index] = val;
    }

int Foot::getId() const {
    return id;
    }

int Foot::getOwnerId() const {
    return ownerId;
    }

int Foot::getDermatologicalValue( FeetExam::Dermatological index ) {
    return dermatologicalValues.at(index);
    }

void Foot::insertDermatologicalValue( int val ) {
    dermatologicalValues.push_back( val );
    }
