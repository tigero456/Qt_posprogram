#ifndef TRASH_H
#define TRASH_H

#include <QDialog>

namespace Ui {
class trash;
}

class trash : public QDialog
{
    Q_OBJECT

public:
    explicit trash(QWidget *parent = nullptr);
    ~trash();

private:
    Ui::trash *ui;
};

#endif // TRASH_H
