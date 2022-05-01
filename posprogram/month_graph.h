#ifndef MONTH_GRAPH_H
#define MONTH_GRAPH_H

#include <QMainWindow>

namespace Ui {
class month_graph;
}

class month_graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit month_graph(QWidget *parent = nullptr);
    ~month_graph();

private:
    Ui::month_graph *ui;
};

#endif // MONTH_GRAPH_H
