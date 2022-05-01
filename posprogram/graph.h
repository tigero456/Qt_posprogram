#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();

private:
    Ui::graph *ui;
};

#endif // GRAPH_H
