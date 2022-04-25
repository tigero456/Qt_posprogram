#ifndef DELETE_H
#define DELETE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QComboBox>

namespace Ui {
class delete;
}

class delete : public QDialog
{
    Q_OBJECT

public:
    explicit delete(QWidget *parent = nullptr);
    ~delete();

private:
    Ui::delete *ui;
    QSqlTableModel  *model;
};

#endif // DELETE_H
