#include "graph_year.h"
#include "ui_graph_year.h"
#include <QtCharts>
#include <QtGui>
#include <QPainter>
#include <QWidget>
#include <QChartView>

graph_year::graph_year(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graph_year)
{
    ui->setupUi(this);

    setWindowTitle("2022년 ~ 2025 연 매출");
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

    *set0 << 200000;
    *set1 << 100000;
    *set2 << 400000;
    *set3 << 300000;
    *set4 << 50000;
    *set5 << 3000;
    *set2_0 << 1000;
    *set2_1 << 2000;
    *set2_2 << 3000;
    *set2_3 << 4000;
    *set2_4 << 5000;
    *set2_5 << 6000;

    QStackedBarSeries *year = new QStackedBarSeries();
    year->append(set0);
    year->append(set1);
    year->append(set2);
    year->append(set3);
    year->append(set4);
    year->append(set5);
    QHorizontalPercentBarSeries *cartegory = new QHorizontalPercentBarSeries();
    cartegory->append(set2_0);
    cartegory->append(set2_1);
    cartegory->append(set2_2);
    cartegory->append(set2_3);
    cartegory->append(set2_4);
    cartegory->append(set2_5);

    QChart *yearchart = new QChart();
    yearchart->addSeries(year);
    yearchart->createDefaultAxes();
    yearchart->legend()->show();
    yearchart->setAnimationOptions(QChart::SeriesAnimations);
    QChart *cartegorychart = new QChart();
    cartegorychart->addSeries(cartegory);

    QStringList yearlist;
    yearlist = {"2022", "2023", "2024", "2025"};

    QBarCategoryAxis *yearaxisX = new QBarCategoryAxis();
    yearaxisX->append(yearlist);
    yearaxisX->setTitleText("year");
    QBarCategoryAxis *cartegoryaxisX = new QBarCategoryAxis();
    cartegorychart->legend()->hide();
    cartegoryaxisX->setVisible(false);

    QValueAxis *yearaxisY = new QValueAxis;
    yearaxisY->setRange(0, 2000000);
    yearaxisY->setLabelFormat("%d");

    yearchart->setAxisX(yearaxisX, year);
    yearchart->setAxisY(yearaxisY, year);
    cartegorychart->setAxisX(cartegoryaxisX, cartegory);

    QChartView *yearchartView = new QChartView(yearchart);
    QChartView *cartegorychartView = new QChartView(cartegorychart);
    yearchartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(yearchartView);
    setMenuWidget(cartegorychartView);
}

graph_year::~graph_year()
{
    delete ui;
}
