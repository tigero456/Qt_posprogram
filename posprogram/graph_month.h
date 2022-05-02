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

private slots:
    void on_pushButton_clicked();
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::graph_month *ui;
    QString check_date;
};

#endif // GRAPH_MONTH_H
