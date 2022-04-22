#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QAbstractItemView>


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

    ui->logo->show();
    ui->product_table->hide();
    ui->iv_table->hide();
    ui->p_table->hide();
    ui->today_date_label->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->now_trashbtn->hide();
    ui->t_table->hide();
    ui->t_btn->hide();
    ui->basketlist_table->hide();
    ui->soon_trashbtn->hide();
    ui->pay_table->hide();
    ui->salelist_label->hide();
    ui->payhistory_label->hide();
    ui->basketlist_label->hide();
    ui->cartegpry_label->hide();
    ui->pcancelbtn->hide();
    ui->acancelbtn->hide();
    ui->trashbtn->hide();
    ui->soon_trashbtn->hide();
    ui->paybtn->hide();
    ui->combobox->hide();
    ui->iv_lookbtn->hide();
    ui->p_lookbtn->hide();
    ui->product_addbtn->hide();
    ui->product_deletebtn->hide();
    ui->product_changebtn->hide();
    ui->inventory_addbtn->hide();
    ui->product_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->iv_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->p_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->basketlist_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pay_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salebtn_clicked()
{
    num.clear();
    paylist=0;
    ui->product_table->setRowCount(0);
    ui->basketlist_table->setRowCount(0);
    ui->basketlist_table->clear();
    ui->product_table->clear();
    ui->logo->hide();
    ui->today_date_label->hide();
    ui->soon_trashbtn->hide();
    ui->product_table->show();
    ui->iv_table->hide();
    ui->p_table->hide();
    ui->trashbtn->hide();
    ui->soon_trashbtn->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->now_trashbtn->hide();
    ui->t_table->hide();
    ui->t_btn->hide();
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
}

void MainWindow::on_lookbtn_clicked()
{
    ui->logo->hide();
    ui->product_table->hide();
    ui->iv_table->hide();
    ui->today_date_label->hide();
    ui->p_table->show();
    ui->trashbtn->show();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->now_trashbtn->hide();
    ui->soon_trashbtn->hide();
    ui->t_table->hide();
    ui->t_btn->hide();
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
    QList<QString> pay_header;
    pay_header.append("상품명");
    pay_header.append("수량");
    pay_header.append("가격");
    ui->pay_table->setHorizontalHeaderLabels(pay_header);

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

    int row=ui->basketlist_table->rowCount();
    int index = ui->product_table->currentRow();
    QString p_code;                            //쿼리문 전달할 변수
    QSqlQuery query;

    query.prepare("select (product_code) from product where product_name= '"+p_name[index]+"'");
    query.exec();                                     //실행
    query.next();
    p_code=query.value(0).toString();

    query.prepare("select p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where p.product_code = '"+p_code+"'");
    query.exec();                                     //실행

    query.prepare("UPDATE inventory SET inventory_number = inventory_number-1 WHERE product_code = '"+p_code+"'");
    query.exec();                                     //실행


    query.prepare("insert into paylist (pay_amount) values('"+QString::number(paylist)+"')");
    query.exec();                                     //실행

    int p_num=0;
    for(int i=0; i<row; i++){
        QString check=ui->basketlist_table->item(i, 2)->text();
        p_num+=check.toInt();
    }

    ui->pay_table->setColumnCount(3);
    ui->pay_table->setRowCount(row+1);
    ui->basketlist_table->setColumnWidth(0, 80);
    ui->basketlist_table->setColumnWidth(1, 40);
    ui->basketlist_table->setColumnWidth(2, 30);

    for(int i=0; i<row; i++){
        ui->pay_table->setItem(i, 0, new QTableWidgetItem(ui->basketlist_table->item(i, 0)->text()));
        ui->pay_table->setItem(i, 1, new QTableWidgetItem(ui->basketlist_table->item(i, 2)->text()));
        ui->pay_table->setItem(i, 2, new QTableWidgetItem(ui->basketlist_table->item(i, 1)->text()));
    }
    ui->pay_table->setItem(row, 0, new QTableWidgetItem("총 결제금액"));
    ui->pay_table->setItem(row, 1, new QTableWidgetItem(QString::number(p_num)));
    ui->pay_table->setItem(row, 2, new QTableWidgetItem(QString::number(paylist)));
}

void MainWindow::on_iv_lookbtn_clicked()
{
    ui->today_date_label->hide();
    ui->iv_table->show();
    ui->p_table->hide();
    ui->soon_trashbtn->hide();
    ui->now_trashbtn->hide();
    ui->t_btn->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->t_table->hide();

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

    QList<QString> iventory_header;
    iventory_header.append("상품명");
    iventory_header.append("상품가격");
    iventory_header.append("유통기한");
    iventory_header.append("수량");
    ui->iv_table->setHorizontalHeaderLabels(iventory_header);
}

void MainWindow::on_p_lookbtn_clicked()
{
    ui->today_date_label->hide();
    ui->iv_table->hide();
    ui->p_table->show();
    ui->soon_trashbtn->hide();
    ui->now_trashbtn->hide();
    ui->t_btn->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->t_table->hide();

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
        addbtn = new QPushButton("추가", this);
        ui->product_table->setColumnCount(3);
        ui->product_table->setRowCount(count);
        ui->product_table->setItem(i, 0, new QTableWidgetItem(p_name[i]));
        ui->product_table->setColumnWidth(1, 70);
        ui->product_table->setItem(i, 1, new QTableWidgetItem(p_sale[i]));
        ui->product_table->setColumnWidth(2, 60);
        ui->product_table->setCellWidget(i, 2, addbtn);
        connect(addbtn, SIGNAL(clicked()), this, SLOT(Onlistaddbtn_sensor_click()));
    }

    QList<QString> product_header;
    product_header.append("상품명");
    product_header.append("상품가격");
    product_header.append("");
    ui->product_table->setHorizontalHeaderLabels(product_header);
}

void MainWindow::Onlistaddbtn_sensor_click(){
    int j = ui->basketlist_table->rowCount();
    int index = ui->product_table->currentRow();
    QString s_num;

    if(j==0){
        num.append(1);
        ui->basketlist_table->setColumnCount(4);
        ui->basketlist_table->setRowCount(j+1);
        ui->basketlist_table->setColumnWidth(0, 80);
        ui->basketlist_table->setColumnWidth(1, 40);
        ui->basketlist_table->setColumnWidth(2, 30);
        ui->basketlist_table->setColumnWidth(3, 40);
        delbtn = new QPushButton("삭제", this);
        ui->basketlist_table->setItem(0, 0, new QTableWidgetItem(p_name[index]));
        ui->basketlist_table->setItem(0, 1, new QTableWidgetItem(p_sale[index]));
        ui->basketlist_table->setItem(0, 2, new QTableWidgetItem(QString::number(num[0])));
        ui->basketlist_table->setCellWidget(0, 3, delbtn);
        connect(delbtn, SIGNAL(clicked()), this, SLOT(Onlistdelbtn_sensor_click()));
    }else {
        for(int i=0; i<j; i++){
            QString check = ui->basketlist_table->item(i, 0)->text();

            if(check == p_name[index]){
                num[i]+=1;
                s_num=QString::number(num[i]);
                ui->basketlist_table->setItem(i, 2, new QTableWidgetItem(s_num));
                break;
            }
            else{
                if(i==j-1){
                    num.append(1);
                    s_num=QString::number(num[i]);
                    ui->basketlist_table->setColumnCount(4);
                    ui->basketlist_table->setRowCount(j+1);
                    ui->basketlist_table->setColumnWidth(0, 80);
                    ui->basketlist_table->setColumnWidth(1, 40);
                    ui->basketlist_table->setColumnWidth(2, 30);
                    ui->basketlist_table->setColumnWidth(3, 40);
                    delbtn = new QPushButton("삭제", this);
                    ui->basketlist_table->setItem(j, 0, new QTableWidgetItem(p_name[index]));
                    ui->basketlist_table->setItem(j, 1, new QTableWidgetItem(p_sale[index]));
                    ui->basketlist_table->setItem(j, 2, new QTableWidgetItem(s_num));
                    ui->basketlist_table->setCellWidget(j, 3, delbtn);
                    connect(delbtn, SIGNAL(clicked()), this, SLOT(Onlistdelbtn_sensor_click()));
                }
            }
        }
    }
/*
    for(int i=0; i<num.size(); i++){
        qDebug()<<num[i]<<" ";
    }
    qDebug()<<Qt::endl;
*/
    QList<QString> basket_header;
    basket_header.append("상품명");
    basket_header.append("가격");
    basket_header.append("수량");
    basket_header.append("");
    ui->basketlist_table->setHorizontalHeaderLabels(basket_header);

    paylist += p_sale[index].toInt();
    qDebug()<<paylist;
}

void MainWindow::Onlistdelbtn_sensor_click(){
    int index = ui->basketlist_table->currentRow();
    QString pay=ui->basketlist_table->item(index, 1)->text();
    int delpay = pay.toInt() * num[index];

    num.erase(num.begin()+index);
    /*
    for(int i=0; i<num.size(); i++){
        qDebug()<<num[i]<<" ";
    }
    qDebug()<<Qt::endl;
    */

    ui->basketlist_table->removeRow(index);

    paylist -= delpay;

    qDebug()<<paylist;
}

void MainWindow::on_inventory_addbtn_clicked()
{
    ia = new inventory_add(this);
    ia->show();
}

void MainWindow::on_soon_trashbtn_clicked()
{
    ui->today_date_label->show();

    QString select_query, code, c_code, cartegory, date;                            //쿼리문 전달할 변수
    QSqlQuery query;


    s_t_name.clear();
    s_t_sale.clear();
    s_t_date.clear();
    s_t_num.clear();

    ui->p_table->hide();
    ui->soon_t_table->show();
    ui->iv_table->hide();
    ui->t_table->hide();
    ui->now_t_table->hide();
    ui->now_trashbtn->show();
    ui->soon_trashbtn->show();
    ui->t_btn->show();

    code=QString("select p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where i.inventory_life < curdate()+10 and i.inventory_life >= curdate()");
    query.prepare(code);                         //준비
    query.exec();

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        s_t_name.append(query.value(0).toString());
        s_t_sale.append(query.value(1).toString());
        s_t_date.append(query.value(2).toString());
        s_t_num.append(query.value(3).toString());
        count++;
    }

    ui->soon_t_table->setColumnCount(4);
    ui->soon_t_table->setRowCount(s_t_name.size());

    for(int i=0; i<s_t_name.size(); i++){
        ui->soon_t_table->setItem(i, 0, new QTableWidgetItem(s_t_name[i]));
        ui->soon_t_table->setItem(i, 1, new QTableWidgetItem(s_t_sale[i]));
        ui->soon_t_table->setItem(i, 2, new QTableWidgetItem(s_t_date[i]));
        ui->soon_t_table->setItem(i, 3, new QTableWidgetItem(s_t_num[i]));
    }

    QList<QString> soon_trash_header;
    soon_trash_header.append("상품명");
    soon_trash_header.append("상품가격");
    soon_trash_header.append("유통기한");
    soon_trash_header.append("수량");
    ui->soon_t_table->setHorizontalHeaderLabels(soon_trash_header);
}

void MainWindow::on_trashbtn_clicked()
{
    QString code, date;                            //쿼리문 전달할 변수
    QSqlQuery query;

    code=QString("select curdate()");
    query.prepare(code);                         //준비
    query.exec();
    query.next();
    date=query.value(0).toString();

    ui->today_date_label->setText(date);
    ui->today_date_label->show();
    ui->now_t_table->show();
    ui->p_table->hide();
    ui->soon_t_table->hide();
    ui->iv_table->hide();
    ui->now_trashbtn->show();
    ui->soon_trashbtn->show();
    ui->t_btn->show();
}

void MainWindow::on_now_trashbtn_clicked()
{
    n_t_code.clear();
    n_t_date.clear();
    n_t_sale.clear();
    n_t_num.clear();

    ui->today_date_label->show();
    ui->now_t_table->show();
    ui->p_table->hide();
    ui->soon_t_table->hide();
    ui->iv_table->hide();
    ui->now_trashbtn->show();
    ui->soon_trashbtn->show();
    ui->t_btn->show();

    QString code, date;                            //쿼리문 전달할 변수
    QSqlQuery query;

//    code=QString("select * from store.trash");
    code=QString("select p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where i.inventory_life < curdate()");

    query.prepare(code);                         //준비
    query.exec();

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        n_t_code.append(query.value(0).toString());
        n_t_sale.append(query.value(1).toString());
        n_t_date.append(query.value(2).toString());
        n_t_num.append(query.value(3).toString());
        count++;
    }

    ui->now_t_table->setColumnCount(5);
    ui->now_t_table->setRowCount(n_t_code.size());
    ui->now_t_table->setColumnWidth(3, 30);
    ui->now_t_table->setColumnWidth(4, 50);

    for(int i=0; i<n_t_code.size(); i++){
        trashbtn = new QPushButton("등록", this);
        ui->now_t_table->setItem(i, 0, new QTableWidgetItem(n_t_code[i]));
        ui->now_t_table->setItem(i, 1, new QTableWidgetItem(n_t_sale[i]));
        ui->now_t_table->setItem(i, 2, new QTableWidgetItem(n_t_date[i]));
        ui->now_t_table->setItem(i, 3, new QTableWidgetItem(n_t_num[i]));
        ui->now_t_table->setCellWidget(i, 4, trashbtn);
        connect(trashbtn, SIGNAL(clicked()), this, SLOT(Onlisttrashbtn_sensor_click()));
    }

    QList<QString> now_trash_header;
    now_trash_header.append("상품명");
    now_trash_header.append("상품가격");
    now_trash_header.append("유통기한");
    now_trash_header.append("수량");
    now_trash_header.append("");
    ui->now_t_table->setHorizontalHeaderLabels(now_trash_header);
}

void MainWindow::Onlisttrashbtn_sensor_click(){
    QString code, date;                            //쿼리문 전달할 변수
    QSqlQuery query;
    int index = ui->now_t_table->currentRow();

    QString check = ui->now_t_table->item(index, 0)->text();

//    code=QString("delete from inventory where inventory_life <= curdate()");

    query.prepare(code);                         //준비
    query.exec();
}

void MainWindow::on_t_btn_clicked()
{
    t_code.clear();
    t_date.clear();

    ui->today_date_label->show();
    ui->now_t_table->hide();
    ui->p_table->hide();
    ui->t_table->show();
    ui->soon_t_table->hide();
    ui->iv_table->hide();
    ui->now_trashbtn->show();
    ui->soon_trashbtn->show();
    ui->t_btn->show();

    QString code, date;                            //쿼리문 전달할 변수
    QSqlQuery query;

    code=QString("select * from store.trash");

    query.prepare(code);                         //준비
    query.exec();

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        t_code.append(query.value(0).toString());
        t_date.append(query.value(1).toString());
        count++;
    }

    ui->t_table->setColumnCount(2);
    ui->t_table->setRowCount(n_t_code.size());

    for(int i=0; i<n_t_code.size(); i++){
        ui->t_table->setItem(i, 0, new QTableWidgetItem(t_code[i]));
        ui->t_table->setItem(i, 1, new QTableWidgetItem(t_date[i]));
    }

    QList<QString> trash_header;
    trash_header.append("상품코드");
    trash_header.append("유통기한");
    ui->t_table->setHorizontalHeaderLabels(trash_header);
}

