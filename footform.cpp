#include "footform.h"
#include "ui_footform.h"

FootForm::FootForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FootForm)
{
    ui->setupUi(this);
}

FootForm::~FootForm()
{
    delete ui;
}
