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

void FootDialog::setup(QGraphicsScene* gs) {
    ui->footGV->setScene(gs);
    }
