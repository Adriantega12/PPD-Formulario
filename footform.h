#ifndef FOOTFORM_H
#define FOOTFORM_H

#include <QWidget>

namespace Ui {
class FootForm;
}

class FootForm : public QWidget
{
    Q_OBJECT

public:
    explicit FootForm(QWidget *parent = 0);
    ~FootForm();

private:
    Ui::FootForm *ui;
};

#endif // FOOTFORM_H
