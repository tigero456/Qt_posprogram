#include "calculate.h"
#include "ui_calculate.h"

calculate::calculate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculate)
{
    ui->setupUi(this);
}

calculate::~calculate()
{
    delete ui;
}
