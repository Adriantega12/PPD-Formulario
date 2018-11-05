#ifndef FOOTDIALOG_H
#define FOOTDIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <fstream>

namespace Ui {
    class FootDialog;
    }

class FootDialog : public QDialog {
    Q_OBJECT

    private:
        Ui::FootDialog *ui;
        int angle;

    public:
        explicit FootDialog(QWidget *parent = 0);
        ~FootDialog();

        void setup(QGraphicsScene* gs, QString label);
private slots:
        void on_angleSlider_sliderMoved(int position);
};

#endif // FOOTDIALOG_H
