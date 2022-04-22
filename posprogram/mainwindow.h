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
#include "trash.h"

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

    void Onlistaddbtn_sensor_click();

    void Onlistdelbtn_sensor_click();

    void Onlisttrashbtn_sensor_click();

    void on_combobox_activated(int index);

    void on_inventory_addbtn_clicked();

    void on_p_lookbtn_clicked();

    void on_soon_trashbtn_clicked();

    void on_trashbtn_clicked();

    void on_now_trashbtn_clicked();

    void on_t_btn_clicked();


private:
    Ui::MainWindow *ui;
    QSqlTableModel  *model;
    QPushButton *addbtn;
    QPushButton *delbtn;
    QPushButton *trashbtn;
    QSqlDatabase db;
    sale *s;
    look *l;
    change *c;
    trash *t;
    inventory_add *ia;
    QList<QString> p_name;
    QList<QString> p_sale;
    QList<QString> iv_name;
    QList<QString> iv_sale;
    QList<QString> iv_life;
    QList<QString> iv_number;
    QList<QString> s_t_name;
    QList<QString> s_t_sale;
    QList<QString> s_t_date;
    QList<QString> s_t_num;
    QList<QString> n_t_code;
    QList<QString> n_t_date;
    QList<QString> n_t_sale;
    QList<QString> n_t_num;
    QList<QString> t_code;
    QList<QString> t_date;
    QList<int> num;
    int paylist=0;
};
#endif // MAINWINDOW_H
