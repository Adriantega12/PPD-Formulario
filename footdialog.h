#ifndef FOOTDIALOG_H
#define FOOTDIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
    class FootDialog;
    }

class FootDialog : public QDialog {
    Q_OBJECT

    public:
        explicit FootDialog(QWidget *parent = 0);
        ~FootDialog();

        void setup(QGraphicsScene*);

    private:
        Ui::FootDialog *ui;
    };

#endif // FOOTDIALOG_H
