#include "patient.h"

Patient::Patient( int _id, int _fileNum, QString _name, int _age, QString _gender,
                 QString _patology, QString _date, QString _imgPath ) :
                  id(_id), fileNum(_fileNum), name(_name), age(_age), gender(_gender),
                  patology(_patology), date(_date), imgPath(_imgPath),
                  right(nullptr), left(nullptr) { }

Patient::~Patient() {
    if ( left != nullptr ) delete left;
    if ( right != nullptr ) delete right;
    }

int Patient::getId() const {
    return id;
    }

int Patient::getFileNum() const {
    return fileNum;
    }

QString Patient::getName() const {
    return name;
    }

int Patient::getAge() const {
    return age;
    }

QString Patient::getGender() const {
    return gender;
    }

QString Patient::getPatology() const {
    return patology;
    }

QString Patient::getDate() const {
    return date;
    }

QString Patient::getImgPath() const {
    return imgPath;
    }

Foot* Patient::getRightFoot() const {
    return right;
    }

Foot* Patient::getLeftFoot() const {
    return left;
    }

void Patient::setId(int value) {
    id = value;
    }

void Patient::setFileNum(int value) {
    fileNum = value;
    }

void Patient::setName(const QString &value) {
    name = value;
    }

void Patient::setAge(int value) {
    age = value;
    }

void Patient::setGender(const QString &value) {
    gender = value;
    }

void Patient::setPatology(const QString &value) {
    patology = value;
    }

void Patient::setDate(const QString &value) {
    date = value;
    }

void Patient::setImgPath(const QString &value) {
    imgPath = value;
    }

void Patient::setRightFoot( Foot* r ) {
    right = r;
    }

void Patient::setLeftFoot( Foot* l ) {
    left = l;
    }
