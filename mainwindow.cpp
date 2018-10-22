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

void MainWindow::loadPatient(int patientId) {
    const int RIGHT_FOOT = 0;
    const int LEFT_FOOT = 1;

    Patient* loadedPatient = Database::getPatientById(patientId);
    std::vector<Foot*> loadedFeet = Database::getFeetByPatientId(patientId);

    // Load patient info
    ui->fileNumLE->setText(QString::number(loadedPatient->getFileNum()));
    ui->nameLE->setText(loadedPatient->getName());
    ui->ageSB->setValue(loadedPatient->getAge());
    ui->genderCB->setCurrentIndex(ui->genderCB->findText(loadedPatient->getGender()));
    ui->patologyLE->setText(loadedPatient->getPatology());
    ui->visitDE->setDate(QDate::fromString(loadedPatient->getDate()));

    // Load feet info
    for (int i = 0; i < FeetExam::TOTAL_ATTRIBS; ++i) {
        rightFoot[i]->setCurrentIndex(loadedFeet[RIGHT_FOOT]->getExamValue(i));
        leftFoot[i]->setCurrentIndex(loadedFeet[LEFT_FOOT]->getExamValue(i));
    }

    // Load graphics
    loadFeetImage(loadedPatient->getImgPath());

    // Cleanup
    delete loadedPatient;
    delete loadedFeet[RIGHT_FOOT];
    delete loadedFeet[LEFT_FOOT];
}

void MainWindow::loadFeetImage(QString path) {
    QStringList args = (QStringList() << path << "-s" << "-hc");
    /*QProcess* algorithm = new QProcess(this);
    algorithm->startDetached( "./IP-Module-PPD", args );*/
    QProcess::execute( "./IP-Module-PPD", args );
    QImage left( "./left.jpg" ), right( "./right.jpg" );
    QGraphicsScene* lScene = new QGraphicsScene(),
                    *rScene = new QGraphicsScene();
    lScene->addPixmap(QPixmap::fromImage(left));
    rScene->addPixmap(QPixmap::fromImage(right));

    ui->rightFootGV->setScene(rScene);
    ui->leftFootGV->setScene(lScene);
    ui->rightFootGV->updateScene(rScene);
    ui->leftFootGV->updateScene(lScene);
    ui->rightFootGV->setLabel("right");
    ui->leftFootGV->setLabel("left");
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
        left.setExamValue(leftFoot[i]->currentText().toInt(), i);
        }


    try {
        Database::insertPatient(p);
        Database::insertFoot(right);
        Database::insertFoot(left);
        }
    catch (const char* msg) {
        qDebug() << msg;
        }

    QMessageBox mb;
    mb.setText("El paciente ha sido guardado correctamente.");
    mb.exec();
    }

void MainWindow::on_actionImagen_triggered() {
    filePath = QFileDialog::getOpenFileName( this, QString("Buscar imagen"), QDir::homePath() );
    loadFeetImage(filePath);
    }
