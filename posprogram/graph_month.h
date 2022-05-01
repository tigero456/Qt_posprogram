#ifndef GRAPH_MONTH_H
#define GRAPH_MONTH_H

#include <QMainWindow>

namespace Ui {
class graph_month;
}

class graph_month : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph_month(QWidget *parent = nullptr);
    ~graph_month();

private:
    Ui::graph_month *ui;
};

#endif // GRAPH_MONTH_H
