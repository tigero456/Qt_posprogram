#ifndef CALCULATE_H
#define CALCULATE_H

#include <QDialog>

namespace Ui {
class calculate;
}

class calculate : public QDialog
{
    Q_OBJECT

public:
    explicit calculate(QWidget *parent = nullptr);
    ~calculate();

private:
    Ui::calculate *ui;
};

#endif // CALCULATE_H
