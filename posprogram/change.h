#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QComboBox>

namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr);
    ~change();

private slots:
    void on_addbtn_clicked();

    void on_cartagory_comboBox_activated(int index);

private:
    Ui::change *ui;
    QSqlTableModel  *model;
};

#endif // CHANGE_H
