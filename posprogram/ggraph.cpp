#include "ggraph.h"
#include "ui_ggraph.h"
#include <QtCharts>
#include <QtGui>
#include <QPainter>
#include <QWidget>
#include <QChartView>

ggraph::ggraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ggraph)
{
    ui->setupUi(this);

    setWindowTitle("2022년 05월 1주차 매출");
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

    *set0 << 200000 << 300000 << 130000 << 40000 << 110000 << 30000 << 420000;
    *set1 << 100000 << 200000 << 100000 << 20000 << 90000 << 200000 << 48000;
    *set2 << 400000 << 40000 << 30000 << 240000 << 400000 << 500000 << 220000;
    *set3 << 300000 << 100000 << 60000 << 260000 << 400000 << 560000 << 120000;
    *set4 << 50000 << 300000 << 30000 << 10000 << 40000 << 240000 << 30000;
    *set5 << 3000 << 500000 << 50000 << 30000 << 540000 << 30000 << 40000;
    *set2_0 << 1000;
    *set2_1 << 2000;
    *set2_2 << 3000;
    *set2_3 << 4000;
    *set2_4 << 5000;
    *set2_5 << 6000;

    QStackedBarSeries *week = new QStackedBarSeries();
    week->append(set0);
    week->append(set1);
    week->append(set2);
    week->append(set3);
    week->append(set4);
    week->append(set5);
    QHorizontalPercentBarSeries *cartegory = new QHorizontalPercentBarSeries();
    cartegory->append(set2_0);
    cartegory->append(set2_1);
    cartegory->append(set2_2);
    cartegory->append(set2_3);
    cartegory->append(set2_4);
    cartegory->append(set2_5);

    QChart *weekchart = new QChart();
    weekchart->addSeries(week);
    weekchart->createDefaultAxes();
    weekchart->legend()->show();
    weekchart->setAnimationOptions(QChart::SeriesAnimations);
    QChart *cartegorychart = new QChart();
    cartegorychart->addSeries(cartegory);

    QStringList daylist;
    daylist = {"월", "화", "수", "목", "금", "토", "일"};

    QBarCategoryAxis *weekaxisX = new QBarCategoryAxis();
    weekaxisX->append(daylist);
    weekaxisX->setTitleText("days");
    QBarCategoryAxis *cartegoryaxisX = new QBarCategoryAxis();
    cartegorychart->legend()->hide();
    cartegoryaxisX->setVisible(false);


    QValueAxis *weekaxisY = new QValueAxis;
    weekaxisY->setRange(0, 2000000);
    weekaxisY->setLabelFormat("%d");

    weekchart->setAxisX(weekaxisX, week);
    weekchart->setAxisY(weekaxisY, week);
    cartegorychart->setAxisX(cartegoryaxisX, cartegory);

    QChartView *weekchartView = new QChartView(weekchart);
    QChartView *cartegorychartView = new QChartView(cartegorychart);
    weekchartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(weekchartView);
    setMenuWidget(cartegorychartView);
}

ggraph::~ggraph()
{
    delete ui;
}
