#include "footdialog.h"
#include "ui_footdialog.h"

FootDialog::FootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FootDialog),
    angle(0) {
    ui->setupUi(this);
    }

FootDialog::~FootDialog() {
    delete ui;
    }

void FootDialog::setup(QGraphicsScene* gs, QString footLbl, QString filePath) {
    std::vector<int> pixelCount;
    int count, totalCount = 0;
    ui->footGV->setScene(gs);

    path = filePath;
    label = footLbl;

    // Scale colors
    QImage scale("./scale.jpg");
    QGraphicsScene* scaleScene = new QGraphicsScene();
    scaleScene->addPixmap(QPixmap::fromImage(scale));
    ui->thermalScaleGV->setScene(scaleScene);

    // Load data
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

    // Percent
    file >> percent;

    // Pixel count
    while (file >> count) {
        pixelCount.push_back(count);
        totalCount += count;
        }

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

    QLabel* lbl;
    for ( unsigned int i = 0; i < pixelCount.size(); ++i) {
        lbl = new QLabel(QString::number(pixelCount[i] * 100.0 / totalCount, 'g', 3) + "%", this);
        lbl->move( ui->thermalScaleGV->x() + ui->thermalScaleGV->width() + 20,
                   ui->thermalScaleGV->y() + i * ( (ui->thermalScaleGV->height() - 15 ) / pixelCount.size() ) + 20 );
        }
    }

void FootDialog::on_angleSlider_sliderMoved(int position) {
   /* ui->footGV->rotate(qreal(position - angle));

    angle = position;

    qDebug() << angle;
    ui->angleVal->setText(QString::number(angle) + "º");*/
    }

void FootDialog::on_calculateBttn_clicked() {
    QStringList args = (QStringList() << path << "-hc" << "-r" << QString::number(angle) << "-pc");
    QProcess::execute( "./IP-Module-PPD", args );
    QString fileName = (label == "left" ? "lHC.jpg" : "rHC.jpg");
    QGraphicsScene* scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(QImage(fileName)));
    ui->footGV->setScene(scene);
    ui->angleSlider->setValue(0);

    // Load data
    std::string name;
    if (label == "right") {
        name = "rData.txt";
        }
    else if (label == "left") {
        name = "lData.txt";
        }
    std::ifstream file(name, std::ios::in);
    double percent;
    QString labelValue;

    // Percent
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

    ui->calculateBttn->setEnabled(false;
    }

void FootDialog::on_angleSlider_valueChanged(int value) {
    ui->footGV->rotate(qreal(value - angle));

    angle = value;

    qDebug() << angle;
    ui->angleVal->setText(QString::number(angle) + "º");
    }
