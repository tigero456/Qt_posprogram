#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QComboBox>
#include <QDebug>
#include "sale.h"
#include "look.h"
#include "change.h"
#include "inventory_add.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_salebtn_clicked();

    void on_lookbtn_clicked();

    void on_paybtn_clicked();

    void on_iv_lookbtn_clicked();

    void on_product_addbtn_clicked();

    void on_product_deletebtn_clicked();

    void on_product_changebtn_clicked();

    void Onlistbtn_sensor_click();

    void on_combobox_activated(int index);

    void on_inventory_addbtn_clicked();

    void on_p_lookbtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel  *model;
    QPushButton *btn;
    QSqlDatabase db;
    sale *s;
    look *l;
    change *c;
    inventory_add *ia;
    QList<QString> p_name;
    QList<QString> p_sale;
    QList<QString> iv_name;
    QList<QString> iv_sale;
    QList<QString> iv_life;
    QList<QString> iv_number;
    int j=0;
    int paylist=0;
};
#endif // MAINWINDOW_H
