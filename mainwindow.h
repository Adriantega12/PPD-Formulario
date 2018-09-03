#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QFormLayout>

#include "foot.h"
#include "database.h"

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        Ui::MainWindow *ui;
        void setupPatientInfoLayout();
        void setupDermatologicalExamLayout();

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
private slots:
        void on_actionNuevo_triggered();
        void on_actionAbrir_triggered();
        void on_actionGuardar_triggered();
};

#endif // MAINWINDOW_H
