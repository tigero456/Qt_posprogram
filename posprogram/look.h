#ifndef LOOK_H
#define LOOK_H

#include <QDialog>
#include <QSqlTableModel>
#include <QComboBox>

namespace Ui {
class look;
}

class look : public QDialog
{
    Q_OBJECT

public:
    explicit look(QWidget *parent = nullptr);
    ~look();

private slots:
    void on_addbtn_clicked();

private:
    Ui::look *ui;
    QSqlTableModel  *model;
};

#endif // LOOK_H
