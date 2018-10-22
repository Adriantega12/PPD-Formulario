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

    public:
        explicit FootDialog(QWidget *parent = 0);
        ~FootDialog();

        void setup(QGraphicsScene* gs, QString label);

    private:
        Ui::FootDialog *ui;
    };

#endif // FOOTDIALOG_H
