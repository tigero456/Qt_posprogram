#ifndef GRAPH_YEAR_H
#define GRAPH_YEAR_H

#include <QMainWindow>

namespace Ui {
class graph_year;
}

class graph_year : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph_year(QWidget *parent = nullptr);
    ~graph_year();

private:
    Ui::graph_year *ui;
};

#endif // GRAPH_YEAR_H
