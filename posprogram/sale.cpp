#include "sale.h"
#include "ui_sale.h"

sale::sale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sale)
{
    ui->setupUi(this);
}

sale::~sale()
{
    delete ui;
}


void sale::on_menubtn_clicked()
{
}

