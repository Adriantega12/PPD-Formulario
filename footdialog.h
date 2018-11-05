#ifndef FOOTDIALOG_H
#define FOOTDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QProcess>

#include <fstream>

namespace Ui {
    class FootDialog;
    }

class FootDialog : public QDialog {
    Q_OBJECT

    private:
        Ui::FootDialog *ui;
        int angle;
        QString path;
        QString label;

    public:
        explicit FootDialog(QWidget *parent = 0);
        ~FootDialog();

        void setup(QGraphicsScene* gs, QString label, QString filePath);

    private slots:
        void on_angleSlider_sliderMoved(int position);
        void on_calculateBttn_clicked();
        void on_angleSlider_valueChanged(int value);
};

#endif // FOOTDIALOG_H
