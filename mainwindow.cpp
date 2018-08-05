#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::setupDermatologicalExam() {
    QFormLayout* leftLO = ui->leftFootLO;
    QFormLayout* rightLO = ui->rightFootLO;
    QStringList items = (QStringList() << "0" << "1" << "2");
    QComboBox* cbL;
    QComboBox* cbR;

    for ( int i = 0; i < Foot::NUMBER_OF_ATTRIBUTES; ++i ) {
        cbL = cbR = nullptr;
        if ( i != Foot::OTHERS ) {
            cbL = new QComboBox();
            cbR = new QComboBox();
            cbL->addItems(items);
            cbR->addItems(items);
            }

        leftLO->addRow( new QLabel(Foot::LABEL[i]), cbL );
        rightLO->addRow( new QLabel(Foot::LABEL[i]), cbR );
        }
    }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupDermatologicalExam();
    }

MainWindow::~MainWindow() {
    delete ui;
    }
