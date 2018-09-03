#include <QApplication>

#include "mainwindow.h"

#include "database.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    int returnStatus;
    w.show();

    Database::openDatabase();
    returnStatus = a.exec();
    Database::closeDatabase();

    return returnStatus;
    }
