#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setupPatientInfoLayout() {
    QGridLayout* layout = ui->patientFormLO;
    layout->columnStretch(6);
    // Nombre
    layout->addWidget( ui->nameLbl, 0, 0, 1, 5 );
    layout->addWidget( ui->nameLE, 1, 0, 1, 5 );
    // Num. Expediente
    layout->addWidget( ui->fileNumLbl, 0, 5, 1, 2 );
    layout->addWidget( ui->fileNumLE, 1, 5, 1, 2 );
    // Género
    layout->addWidget( ui->genderLbl, 2, 0, 1, 1 );
    layout->addWidget( ui->genderCB, 3, 0, 1, 1 );
    // Edad
    layout->addWidget( ui->ageLbl, 2, 1, 1, 1 );
    layout->addWidget( ui->ageSB, 3, 1, 1, 1 );
    // Patología
    layout->addWidget( ui->patologyLbl, 2, 2, 1, 3 );
    layout->addWidget( ui->patologyLE, 3, 2, 1, 3 );
    // Fecha
    layout->addWidget( ui->dateLbl, 2, 5, 1, 2 );
    layout->addWidget( ui->visitDE, 3, 5, 1, 2 );
    }

void MainWindow::setupDermatologicalExamLayout() {
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
    setupPatientInfoLayout();
    setupDermatologicalExamLayout();
    }

MainWindow::~MainWindow() {
    delete ui;
    }
