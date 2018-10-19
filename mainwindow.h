#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QFormLayout>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>

#include <vector>

#include "foot.h"
#include "database.h"
#include "loadpatientdialog.h"
#include "feetexam.h"

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        Ui::MainWindow *ui;
        void setupPatientInfoLayout();
        void setupExamLayout();

        // Modify this later
        QVector<QComboBox*> leftFoot;
        QVector<QComboBox*> rightFoot;

        QString filePath;

        void loadPatient(int patientId);
        void loadFeetImage(QString path);

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_actionNuevo_triggered();
        void on_actionAbrir_triggered();
        void on_actionGuardar_triggered();
        void on_actionImagen_triggered();
};

#endif // MAINWINDOW_H
