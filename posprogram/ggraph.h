#ifndef GGRAPH_H
#define GGRAPH_H

#include <QMainWindow>

namespace Ui {
class ggraph;
}

class ggraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit ggraph(QWidget *parent = nullptr);
    ~ggraph();

private slots:
    void on_pushButton_2_clicked();
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::ggraph *ui;
    QString check_date;
};

#endif // GGRAPH_H
