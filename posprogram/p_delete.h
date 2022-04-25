#ifndef P_DELETE_H
#define P_DELETE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QComboBox>

namespace Ui {
class p_delete;
}

class p_delete : public QDialog
{
    Q_OBJECT

public:
    explicit p_delete(QWidget *parent = nullptr);
    ~p_delete();

private slots:
    void on_cartagory_comboBox_activated(int index);

    void on_delbtn_clicked();

private:
    Ui::p_delete *ui;
    QSqlTableModel  *model;
};

#endif // P_DELETE_H
