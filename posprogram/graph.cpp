#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
}

graph::~graph()
{
    delete ui;
}
