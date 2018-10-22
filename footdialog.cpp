#include "footdialog.h"
#include "ui_footdialog.h"

FootDialog::FootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FootDialog) {
    ui->setupUi(this);
    }

FootDialog::~FootDialog() {
    delete ui;
    }

void FootDialog::setup(QGraphicsScene* gs, QString label) {
    ui->footGV->setScene(gs);

    std::string fileName;
    if (label == "right") {
        fileName = "rData.txt";
        }
    else if (label == "left") {
        fileName = "lData.txt";
        }

    std::ifstream file(fileName, std::ios::in);
    double percent;
    QString labelValue;

    file >> percent;

    if ( percent < 35.0 ) {
        labelValue = "Plano";
        }
    else if ( percent < 40.0 ) {
        labelValue = "Plano - Normal";
        }
    else if ( percent < 55.0 ) {
        labelValue = "Normal";
        }
    else if ( percent < 60.0 ) {
        labelValue = "Normal - Cavo";
        }
    else if ( percent < 75.0 ) {
        labelValue = "Cavo";
        }
    else if ( percent < 85.0 ) {
        labelValue = "Cavo fuerte";
        }
    else if ( percent <= 100.0 ) {
        labelValue = "Cavo extremo";
        }

    ui->footTypeVal->setText(labelValue);
    ui->percentVal->setText(QString::number(percent));
    }
