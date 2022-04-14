#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QSqlTableModel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    qDebug() << "드라이버" << QSqlDatabase::drivers();
//    qDebug() << QCoreApplication::libraryPaths();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("store");
    db.setUserName("root");
    db.setPassword("dbrrns198!@&");

    if(db.open()) {
        qDebug() << "database is connected!";
    }
    else {
        qDebug() << "build error!";
    }

    model = new QSqlTableModel(this);

    QString cartegory_query, cartegoryname;         //쿼리문 전달할 변수
    QSqlQuery query;                                  //데이터베이스에 전달할 쿼리변수

    cartegory_query=QString("select cartegory_name from cartegory"); //쿼리문 저장-분류명 가져오기
    query.prepare(cartegory_query);                 //준비
    query.exec();                                    //실행

    //qDebug()<<query.record().count();

    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        cartegoryname=query.value(0).toString();
        ui->combobox->addItem(cartegoryname);
    }


//    ui->product_table->hideColumn(0);
    ui->logo->show();
    ui->product_table->hide();
    ui->look_table->hide();
    ui->basketist_table->hide();
    ui->salelist_label->hide();
    ui->pay_table->hide();
    ui->payhistory_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->paybtn->hide();
    ui->combobox->hide();
    ui->all_lookbtn->hide();
    ui->product_lookbtn->hide();
    ui->product_addbtn->hide();
    ui->product_deletebtn->hide();
    ui->product_changebtn->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salebtn_clicked()
{
    ui->logo->hide();
    ui->product_table->show();
    ui->look_table->hide();
    ui->basketist_table->show();
    ui->pay_table->hide();
    ui->payhistory_label->hide();
    ui->salelist_label->show();
    ui->basketlist_label->show();
    ui->cartegpry_label->show();
    ui->combobox->show();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->paybtn->show();
    ui->all_lookbtn->hide();
    ui->product_lookbtn->hide();
    ui->product_addbtn->hide();
    ui->product_deletebtn->hide();
    ui->product_changebtn->hide();
   // ui->product_table->clear
}

void MainWindow::on_lookbtn_clicked()
{
    ui->logo->hide();
    ui->product_table->hide();
    ui->look_table->show();
    ui->basketist_table->hide();
    ui->pay_table->hide();
    ui->payhistory_label->hide();
    ui->salelist_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->combobox->hide();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->paybtn->hide();
    ui->all_lookbtn->show();
    ui->product_lookbtn->show();
    ui->product_addbtn->show();
    ui->product_deletebtn->show();
    ui->product_changebtn->show();
}

void MainWindow::on_paybtn_clicked()
{
    ui->logo->hide();
    ui->product_table->hide();
    ui->look_table->hide();
    ui->basketist_table->hide();
    ui->pay_table->show();
    ui->payhistory_label->show();
    ui->salelist_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->combobox->hide();
}

void MainWindow::on_all_lookbtn_clicked()
{
    model->setTable("product");    // 테이블명
    ui->look_table->setModel(model);
    //ui->product_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "상품코드");
    model->setHeaderData(1, Qt::Horizontal, "상품명");
    model->setHeaderData(2, Qt::Horizontal, "상품가격");
    model->setHeaderData(3, Qt::Horizontal, "분류");
}

void MainWindow::on_product_lookbtn_clicked()
{
}

void MainWindow::on_product_addbtn_clicked()
{
    l = new look(this);
    l->show();
}

void MainWindow::on_product_deletebtn_clicked()
{
}

void MainWindow::on_product_changebtn_clicked()
{
}

void MainWindow::on_combobox_activated(int index)
{
    QString select_query, code, c_code, cartegory;                            //쿼리문 전달할 변수
    QSqlQuery query;
    QList<QString> p_name, p_sale, btn_return_name, btn_return_sale;

    cartegory = ui->combobox->currentText();
    code=QString("select cartegory_code from cartegory where cartegory_name='"+cartegory+"'");
    query.prepare(code);                         //준비
    query.exec();                                     //실행
    query.next();
    c_code=query.value(0).toString();

    select_query=QString("select product_name, product_sale from product where cartegory_code = '"+c_code+"'"); //쿼리문 저장-분류에 맞는 컬럼값들 가져오기
    query.prepare(select_query);                         //준비
    query.exec();                                     //실행

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        p_name.append(query.value(0).toString());
        p_sale.append(query.value(1).toString());
        count++;
    }

//    qDebug()<<query.record().count();
//    qDebug()<<p_name;
//    qDebug()<<p_sale;

    for(int i=0; i<count; i++){
        btn = new QPushButton("추가", this);
        ui->product_table->setColumnCount(3);
        ui->product_table->setRowCount(count);
        ui->product_table->setItem(i, 0, new QTableWidgetItem(p_name[i]));
        ui->product_table->setColumnWidth(1, 70);
        ui->product_table->setItem(i, 1, new QTableWidgetItem(p_sale[i]));
        ui->product_table->setColumnWidth(2, 60);
        ui->product_table->setCellWidget(i, 2, btn);
        //connect(btn, &QPushButton::clicked, this, &MainWindow::Onlistbtn_sensor_click);
        //btn_return_name[i] = ui->product_table->item(i, 0)->text();
       // btn_return_sale[i] = ui->product_table->item(i, 1)->text();
    }
    qDebug()<<btn_return_name[0];
}

void MainWindow::Onlistbtn_sensor_click(){
    /*QPushButton *w = qobject_cast<QPushButton *>(sender());
    if(w){
        int row = ui->product_table->indexAt(w->pos()).row();
        std::cout << row;
    }*/
}
