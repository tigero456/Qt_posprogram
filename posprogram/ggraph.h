#ifndef GGRAPH_H
#define GGRAPH_H

#include <QMainWindow>

namespace Ui {
class ggraph;
}

class ggraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit ggraph(QWidget *parent = nullptr);
    ~ggraph();

private:
    Ui::ggraph *ui;
};

#endif // GGRAPH_H
