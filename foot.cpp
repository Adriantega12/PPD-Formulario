#include "foot.h"

Foot::Foot( int oId ) :
    ownerId(oId) {
    }

Foot::~Foot() {
    examValues.clear();
    }

void Foot::setId( int _id ) {
    id = _id;
    }

void Foot::setOwnerId( int _oId ) {
    ownerId = _oId;
    }

void Foot::setExamValue( int val, int index ) {
    if (index < examValues.size())
        examValues[index] = val;
    else
        examValues.push_back(val);
    }

int Foot::getId() const {
    return id;
    }

int Foot::getOwnerId() const {
    return ownerId;
    }

int Foot::getExamValue( int index ) {
    return examValues.at(index);
    }

void Foot::insertDermatologicalValue( int val ) {
    examValues.push_back( val );
    }
