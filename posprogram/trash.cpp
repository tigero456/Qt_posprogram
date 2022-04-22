#include "trash.h"
#include "ui_trash.h"

trash::trash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trash)
{
    ui->setupUi(this);
}

trash::~trash()
{
    delete ui;
}
