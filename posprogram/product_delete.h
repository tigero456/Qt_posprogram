#ifndef PRODUCT_DELETE_H
#define PRODUCT_DELETE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QComboBox>

namespace Ui {
class product_delete;
}

class product_delete : public QDialog
{
    Q_OBJECT

public:
    explicit product_delete(QWidget *parent = nullptr);
    ~product_delete();

private slots:
    void on_delbtn_clicked();

    void on_cartagory_comboBox_activated(int index);

    void on_product_comboBox_activated(int index);

private:
    Ui::product_delete *ui;
    QSqlTableModel  *model;
};

#endif // PRODUCT_DELETE_H
