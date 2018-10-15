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

void MainWindow::setupExamLayout() {
    QStringList items = (QStringList() << "0" << "1" << "2");
    QComboBox* cbL;
    QComboBox* cbR;

    FeetExam::setupDermatologicalExam(ui->dermatologicalTab, rightFoot, leftFoot);
    FeetExam::setupBoneStructureExam(ui->boneTab, rightFoot, leftFoot);
    FeetExam::setupVascularExam(ui->vascularTab, rightFoot, leftFoot);
    FeetExam::setupNeurologicalExam(ui->neurologicalTab, rightFoot, leftFoot);
}

void MainWindow::loadPatient(int id) {
    /*Patient* loadedPatient = Database::getPatientById(id);
    ui->fileNumLE->setText(loadedPatient->getFileNum());
    ui->nameLE->setText(loadedPatient->getName());
    ui->ageSB->setValue(loadedPatient->getAge());,
    ui->genderCB->,
    ui->patologyLE->text(),
    ui->visitDE->text()*/
    }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupPatientInfoLayout();
    setupExamLayout();
    ui->visitDE->setDate(QDate::currentDate());
    }

MainWindow::~MainWindow() {
    delete ui;
    }

void MainWindow::on_actionNuevo_triggered() {

    }

void MainWindow::on_actionAbrir_triggered() {
    LoadPatientDialog dialog;
    dialog.exec();
    dialog.show();
    loadPatient(dialog.getSelectedPatientId());
    }

void MainWindow::on_actionGuardar_triggered() {
    Patient p( Database::getNumberOfPatients() + 1,
               ui->fileNumLE->text().toInt(),
               ui->nameLE->text(),
               ui->ageSB->value(),
               ui->genderCB->currentText(),
               ui->patologyLE->text(),
               ui->visitDE->text(),
               filePath
               );
    Foot left(p.getId()), right(p.getId());

    for (int i = 0; i < FeetExam::TOTAL_ATTRIBS; ++i) {
        right.setExamValue(rightFoot[i]->currentText().toInt(), i);
        left.setExamValue(rightFoot[i]->currentText().toInt(), i);
        }

    Database::insertPatient(p);
    Database::insertFoot(right);
    Database::insertFoot(left);

    QMessageBox mb;
    mb.setText("El paciente ha sido guardado correctamente.");
    mb.exec();
    }

void MainWindow::on_actionImagen_triggered() {
    filePath = QFileDialog::getOpenFileName( this, QString("Buscar imagen"), QDir::homePath() );

    QStringList args = (QStringList() << filePath << "-s");
    QProcess* algorithm = new QProcess(this);
    algorithm->startDetached( "./IP-Module-PPD", args );
    QImage left( "./left.jpg" ), right( "./right.jpg" );
    QGraphicsScene* lScene = new QGraphicsScene(),
                    *rScene = new QGraphicsScene();
    lScene->addPixmap(QPixmap::fromImage(left));
    rScene->addPixmap(QPixmap::fromImage(right));
    // NO OLVIDES QUE ESTÁN AL REVÉS
    ui->leftFootGV->setScene(rScene);
    ui->rightFootGV->setScene(lScene);
    }
