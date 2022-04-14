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
    ui->iv_table->hide();
    ui->p_table->hide();
    ui->basketlist_table->hide();
    ui->salelist_label->hide();
    ui->pay_table->hide();
    ui->payhistory_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->paybtn->hide();
    ui->combobox->hide();
    ui->iv_lookbtn->hide();
    ui->p_lookbtn->hide();
    ui->product_addbtn->hide();
    ui->product_deletebtn->hide();
    ui->product_changebtn->hide();
    ui->inventory_addbtn->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salebtn_clicked()
{
    ui->logo->hide();
    ui->product_table->show();
    ui->iv_table->hide();
    ui->p_table->hide();
    ui->basketlist_table->show();
    ui->pay_table->hide();
    ui->payhistory_label->hide();
    ui->salelist_label->show();
    ui->basketlist_label->show();
    ui->cartegpry_label->show();
    ui->combobox->show();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->paybtn->show();
    ui->iv_lookbtn->hide();
    ui->p_lookbtn->hide();
    ui->product_addbtn->hide();
    ui->product_deletebtn->hide();
    ui->product_changebtn->hide();
    ui->inventory_addbtn->hide();
   // ui->product_table->clear
}

void MainWindow::on_lookbtn_clicked()
{
    ui->logo->hide();
    ui->product_table->hide();
    ui->iv_table->hide();
    ui->p_table->show();
    ui->basketlist_table->hide();
    ui->pay_table->hide();
    ui->payhistory_label->hide();
    ui->salelist_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->combobox->hide();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->paybtn->hide();
    ui->iv_lookbtn->show();
    ui->p_lookbtn->show();
    ui->product_addbtn->show();
    ui->product_deletebtn->show();
    ui->product_changebtn->show();
    ui->inventory_addbtn->show();
}

void MainWindow::on_paybtn_clicked()
{
    ui->logo->hide();
    ui->product_table->hide();
    ui->iv_table->hide();
    ui->p_table->hide();
    ui->basketlist_table->hide();
    ui->pay_table->show();
    ui->payhistory_label->show();
    ui->salelist_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->combobox->hide();


    int index = ui->product_table->currentRow();
    QString code, S_paylist, p_code;                            //쿼리문 전달할 변수
    QSqlQuery query;

    query.prepare("select (product_code) from product where product_name= '"+p_name[index]+"'");
    query.exec();                                     //실행
    query.next();
    p_code=query.value(0).toString();

    query.prepare("select p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where p.product_code = '"+p_code+"'");
    query.exec();                                     //실행

    query.prepare("UPDATE inventory SET inventory_number = inventory_number-1 WHERE product_code = '"+p_code+"'");
    query.exec();                                     //실행

    S_paylist=QString::number(paylist);

    query.prepare("insert into paylist (pay_amount) values('"+S_paylist+"')");
    query.exec();                                     //실행

    ui->pay_table->setColumnCount(3);
    ui->pay_table->setRowCount(1);
    ui->pay_table->setItem(0, 0, new QTableWidgetItem("총 결제금액"));
    ui->pay_table->setItem(0, 1, new QTableWidgetItem("1"));
    ui->pay_table->setItem(0, 2, new QTableWidgetItem(S_paylist));

//    qDebug()<<paylist;

}

void MainWindow::on_iv_lookbtn_clicked()
{
    ui->iv_table->show();
    ui->p_table->hide();

    iv_name.clear();
    iv_sale.clear();
    iv_life.clear();
    iv_number.clear();

    QString select_query;                            //쿼리문 전달할 변수
    QSqlQuery query;

    select_query=QString("select p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code"); //쿼리문 저장-분류에 맞는 컬럼값들 가져오기
    query.prepare(select_query);                         //준비
    query.exec();                                     //실행

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        iv_name.append(query.value(0).toString());
        iv_sale.append(query.value(1).toString());
        iv_life.append(query.value(2).toString());
        iv_number.append(query.value(3).toString());
        count++;
    }

    for(int i=0; i<count; i++){
        ui->iv_table->setColumnCount(4);
        ui->iv_table->setRowCount(count);
//        ui->iv_table->setColumnWidth(0, 70);
//        ui->iv_table->setColumnWidth(1, 70);
//        ui->iv_table->setColumnWidth(2, 70);
//        ui->iv_table->setColumnWidth(3, 70);

        ui->iv_table->setItem(i, 0, new QTableWidgetItem(iv_name[i]));
        ui->iv_table->setItem(i, 1, new QTableWidgetItem(iv_sale[i]));
        ui->iv_table->setItem(i, 2, new QTableWidgetItem(iv_life[i]));
        ui->iv_table->setItem(i, 3, new QTableWidgetItem(iv_number[i]));
    }

}

void MainWindow::on_p_lookbtn_clicked()
{
    ui->iv_table->hide();
    ui->p_table->show();

    model->setTable("product");
    ui->p_table->setModel(model);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "상품코드");
    model->setHeaderData(1, Qt::Horizontal, "상품명");
    model->setHeaderData(2, Qt::Horizontal, "상품가격");
    model->setHeaderData(3, Qt::Horizontal, "카테고리");
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
    c = new change(this);
    c->show();
}

void MainWindow::on_combobox_activated(int index)
{
    p_name.clear();
    p_sale.clear();

    QString select_query, code, c_code, cartegory;                            //쿼리문 전달할 변수
    QSqlQuery query;

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

    for(int i=0; i<count; i++){
        btn = new QPushButton("추가", this);
        ui->product_table->setColumnCount(3);
        ui->product_table->setRowCount(count);
        ui->product_table->setItem(i, 0, new QTableWidgetItem(p_name[i]));
        ui->product_table->setColumnWidth(1, 70);
        ui->product_table->setItem(i, 1, new QTableWidgetItem(p_sale[i]));
        ui->product_table->setColumnWidth(2, 60);
        ui->product_table->setCellWidget(i, 2, btn);
        connect(btn, SIGNAL(clicked()), this, SLOT(Onlistbtn_sensor_click()));
    }

}

void MainWindow::Onlistbtn_sensor_click(){
    int index = ui->product_table->currentRow();
    int sale;

    btn = new QPushButton("삭제", this);
    ui->basketlist_table->setColumnCount(4);
    ui->basketlist_table->setRowCount(j+1);
    ui->basketlist_table->setColumnWidth(0, 80);
    ui->basketlist_table->setItem(j, 0, new QTableWidgetItem(p_name[index]));
    ui->basketlist_table->setColumnWidth(1, 40);
    ui->basketlist_table->setItem(j, 1, new QTableWidgetItem(p_sale[index]));
    ui->basketlist_table->setColumnWidth(2, 30);
    ui->basketlist_table->setItem(j, 2, new QTableWidgetItem());
    ui->basketlist_table->setColumnWidth(3, 40);
    ui->basketlist_table->setCellWidget(j, 3, btn);
    j++;

    sale=p_sale[index].toInt();
    paylist += sale;
}

void MainWindow::on_inventory_addbtn_clicked()
{
    ia = new inventory_add(this);
    ia->show();

}



