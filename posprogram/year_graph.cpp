#include "year_graph.h"
#include "ui_year_graph.h"

year_graph::year_graph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::year_graph)
{
    ui->setupUi(this);
}

year_graph::~year_graph()
{
    delete ui;
}
