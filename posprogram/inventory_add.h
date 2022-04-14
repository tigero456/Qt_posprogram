#ifndef INVENTORY_ADD_H
#define INVENTORY_ADD_H

#include <QDialog>
#include <QSqlTableModel>
#include <QComboBox>

namespace Ui {
class inventory_add;
}

class inventory_add : public QDialog
{
    Q_OBJECT

public:
    explicit inventory_add(QWidget *parent = nullptr);
    ~inventory_add();

private slots:
    void on_addbtn_clicked();

    void on_cartagory_comboBox_activated(int index);

private:
    Ui::inventory_add *ui;
    QSqlTableModel  *model;
};

#endif // INVENTORY_ADD_H
