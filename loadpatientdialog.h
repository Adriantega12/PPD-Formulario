#ifndef LOADPATIENTDIALOG_H
#define LOADPATIENTDIALOG_H

#include <QDialog>

#include <vector>

#include "patient.h"
#include "database.h"

namespace Ui {
    class LoadPatientDialog;
    }

class LoadPatientDialog : public QDialog {
    Q_OBJECT

    public:
        explicit LoadPatientDialog(QWidget *parent = 0);
        ~LoadPatientDialog();

        void setupPatientListView();

        int getSelectedPatientId();


    private slots:
        void on_buttonBox_accepted();

    private:
        Ui::LoadPatientDialog *ui;
        std::vector<Patient*> patients;

        int selectedId;
    };

#endif // LOADPATIENTDIALOG_H
