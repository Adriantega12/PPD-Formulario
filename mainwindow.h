#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QFormLayout>

#include "foot.h"

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        Ui::MainWindow *ui;
        void setupDermatologicalExam();

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    };

#endif // MAINWINDOW_H
