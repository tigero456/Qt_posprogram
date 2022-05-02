#include "graph_month.h"
#include "ui_graph_month.h"
#include <QtCharts>
#include <QtGui>
#include <QPainter>
#include <QWidget>
#include <QChartView>

graph_month::graph_month(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graph_month)
{
    ui->setupUi(this);
}

graph_month::~graph_month()
{
    delete ui;
}

void graph_month::on_pushButton_clicked()
{
    setWindowTitle("2022년 월 매출");
    setGeometry(780, 290, 400, 450);

    QBarSet *set0 = new QBarSet("라면");
    QBarSet *set1 = new QBarSet("과자");
    QBarSet *set2 = new QBarSet("음료");
    QBarSet *set3 = new QBarSet("빵");
    QBarSet *set4 = new QBarSet("주류");
    QBarSet *set5 = new QBarSet("냉동식품");
    QBarSet *set2_0 = new QBarSet("라면");
    QBarSet *set2_1 = new QBarSet("과자");
    QBarSet *set2_2 = new QBarSet("음료");
    QBarSet *set2_3 = new QBarSet("빵");
    QBarSet *set2_4 = new QBarSet("주류");
    QBarSet *set2_5 = new QBarSet("냉동식품");

    *set0 << 200000 << 300000 << 130000 << 40000 << 110000 << 30000 << 420000 << 100000 << 20000 << 90000 << 200000 << 48000;
    *set1 << 100000 << 200000 << 100000 << 20000 << 90000 << 200000 << 48000 << 60000 << 260000 << 400000 << 560000 << 120000;
    *set2 << 400000 << 40000 << 30000 << 240000 << 400000 << 500000 << 220000 << 100000 << 20000 << 90000 << 200000 << 48000;
    *set3 << 300000 << 100000 << 60000 << 260000 << 400000 << 560000 << 120000 << 50000 << 30000 << 540000 << 30000 << 40000;
    *set4 << 50000 << 300000 << 30000 << 10000 << 40000 << 240000 << 30000 << 30000 << 240000 << 400000 << 500000 << 220000;
    *set5 << 3000 << 500000 << 50000 << 30000 << 540000 << 30000 << 40000 << 130000 << 40000 << 110000 << 30000 << 420000;
    *set2_0 << 1000;
    *set2_1 << 2000;
    *set2_2 << 3000;
    *set2_3 << 4000;
    *set2_4 << 5000;
    *set2_5 << 6000;

    QStackedBarSeries *month = new QStackedBarSeries();
    month->append(set0);
    month->append(set1);
    month->append(set2);
    month->append(set3);
    month->append(set4);
    month->append(set5);
    QHorizontalPercentBarSeries *cartegory = new QHorizontalPercentBarSeries();
    cartegory->append(set2_0);
    cartegory->append(set2_1);
    cartegory->append(set2_2);
    cartegory->append(set2_3);
    cartegory->append(set2_4);
    cartegory->append(set2_5);

    QChart *monthchart = new QChart();
    monthchart->addSeries(month);
    monthchart->createDefaultAxes();
    monthchart->legend()->show();
    monthchart->setAnimationOptions(QChart::SeriesAnimations);
    QChart *cartegorychart = new QChart();
    cartegorychart->addSeries(cartegory);

    QStringList monthlist;
    monthlist = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};

    QBarCategoryAxis *monthaxisX = new QBarCategoryAxis();
    monthaxisX->append(monthlist);
    monthaxisX->setTitleText("month");
    QBarCategoryAxis *cartegoryaxisX = new QBarCategoryAxis();
    cartegorychart->legend()->hide();
    cartegoryaxisX->setVisible(false);


    QValueAxis *monthaxisY = new QValueAxis;
    monthaxisY->setRange(0, 2000000);
    monthaxisY->setLabelFormat("%d");

    monthchart->setAxisX(monthaxisX, month);
    monthchart->setAxisY(monthaxisY, month);
    cartegorychart->setAxisX(cartegoryaxisX, cartegory);

    QChartView *monthchartView = new QChartView(monthchart);
    QChartView *cartegorychartView = new QChartView(cartegorychart);
    monthchartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(monthchartView);
    setMenuWidget(cartegorychartView);
}


void graph_month::on_calendarWidget_clicked(const QDate &date)
{
    QDate datetmp;
    datetmp = ui->calendarWidget->selectedDate();

    check_date=datetmp.toString(Qt::ISODate);

    qDebug()<<check_date;
}

