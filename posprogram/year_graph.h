#ifndef YEAR_GRAPH_H
#define YEAR_GRAPH_H

#include <QMainWindow>

namespace Ui {
class year_graph;
}

class year_graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit year_graph(QWidget *parent = nullptr);
    ~year_graph();

private:
    Ui::year_graph *ui;
};

#endif // YEAR_GRAPH_H
