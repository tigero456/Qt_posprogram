#include "month_graph.h"
#include "ui_month_graph.h"

month_graph::month_graph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::month_graph)
{
    ui->setupUi(this);
}

month_graph::~month_graph()
{
    delete ui;
}
