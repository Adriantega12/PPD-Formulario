#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

#include "foot.h"

class Patient {
    private:
        int id;
        int fileNum;
        QString name;
        int age;
        QString gender;
        QString patology;
        QString date;
        QString imgPath;

        Foot* right;
        Foot* left;

    public:
        Patient(int _id = 0, int _fileNum = 0, QString _name = "", int _age = 0, QString _gender = "", QString _patology = "", QString _date = "", QString _imgPath = "" );
        ~Patient();

        // Setters
        void setId(int value);
        void setName(const QString &value);
        void setAge(int value);
        void setGender(const QString &value);
        void setPatology(const QString &value);
        void setDate(const QString &value);
        void setImgPath(const QString &value);
        void setRightFoot( Foot* );
        void setLeftFoot( Foot* );

        // Getters
        int getId() const;
        QString getName() const;
        int getAge() const;
        QString getGender() const;
        QString getPatology() const;
        QString getDate() const;
        QString getImgPath() const;
        Foot* getRightFoot() const;
        Foot* getLeftFoot() const;
        int getFileNum() const;
        void setFileNum(int value);
};

#endif // PATIENT_H
