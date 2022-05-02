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
#include "p_delete.h"
#include "trash.h"
#include "ggraph.h"
#include "graph_month.h"
#include "graph_year.h"

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
    void on_p_searchbtn_clicked();
    void on_iv_searchbtn_clicked();
    void on_journalbtn_clicked();
    void on_graphbtn_clicked();
    void on_graph_weekbtn_clicked();
    void on_graph_monthbtn_clicked();
    void on_graph_yearbtn_clicked();
    void on_journal_cal_btn_clicked();
    void on_calendarWidget_clicked(const QDate &date);

    void on_journal_lookbtn_clicked();

    void on_journalLeftbar_cellClicked(int row, int column);

signals:
    void Send(QString data);

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
    p_delete *pd;
    ggraph *g;
    graph_month *gm;
    graph_year *gy;
    QList<QString> p_code;
    QList<QString> p_name;
    QList<QString> p_sale;
    QList<QString> p_cartegory;
    QList<QString> p_i_name;
    QList<QString> p_i_num;
    QList<QString> iv_code;
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
    QList<QString> t_name;
    QList<QString> t_life;
    QList<QString> t_num;
    QList<QString> t_sale;
    QList<QString> t_date;
    QList<QString> s_p_code;
    QList<QString> s_p_name;
    QList<QString> s_p_sale;
    QList<QString> s_p_cartegory;
    QList<QString> s_iv_code;
    QList<QString> s_iv_name;
    QList<QString> s_iv_sale;
    QList<QString> s_iv_life;
    QList<QString> s_iv_num;
    QList<QString> s_iv_cartegory;
    QList<int> check;
    QString tr_code;
    QList<int> num;
    QString check_date;
    int paylist=0;
};
#endif // MAINWINDOW_H
