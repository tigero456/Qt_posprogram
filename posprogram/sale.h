#ifndef SALE_H
#define SALE_H

#include <QDialog>

namespace Ui {
class sale;
}

class sale : public QDialog
{
    Q_OBJECT

public:
    explicit sale(QWidget *parent = nullptr);
    ~sale();


private slots:
    void on_menubtn_clicked();

private:
    Ui::sale *ui;
};

#endif // SALE_H
