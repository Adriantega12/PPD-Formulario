#include "loadpatientdialog.h"
#include "ui_loadpatientdialog.h"

LoadPatientDialog::LoadPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadPatientDialog) {
    ui->setupUi(this);
    setupPatientListView();
    }

LoadPatientDialog::~LoadPatientDialog() {
    for ( std::vector<Patient*>::iterator p = patients.begin(); p != patients.end(); ++p ) {
        delete (*p);
        }
    delete ui;
    }


void LoadPatientDialog::setupPatientListView() {
    patients = Database::getAllPatients();

    for ( std::vector<Patient*>::iterator p = patients.begin(); p != patients.end(); ++p ) {
        ui->patientLW->addItem( QString( QString::number((*p)->getId()) + " " +
                                         QString::number( (*p)->getFileNum() ) + " " +
                                         (*p)->getName() ) );
    }
}

int LoadPatientDialog::getSelectedPatientId() {
    return selectedId;
    }

void LoadPatientDialog::on_buttonBox_accepted() {
    selectedId = ui->patientLW->currentRow() + 1;
    }
