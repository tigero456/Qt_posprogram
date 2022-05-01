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
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->searchbox->addItem("이름");
    ui->searchbox->addItem("상품코드");
    ui->searchbox->addItem("분류");
    ui->searchbox->hide();
    ui->p_searchbtn->hide();
    ui->iv_searchbtn->hide();
    ui->searchedit->hide();
    ui->journalbtn->hide();
    ui->graphbtn->hide();
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
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->product_table->clear();
    ui->basketlist_table->clear();
    ui->product_table->setColumnCount(0);
    ui->product_table->setRowCount(0);
    ui->basketlist_table->setColumnCount(0);
    ui->basketlist_table->setRowCount(0);
    ui->searchbox->hide();
    ui->p_searchbtn->hide();
    ui->iv_searchbtn->hide();
    ui->searchedit->hide();
    ui->journalbtn->hide();
    ui->graphbtn->hide();
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
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->p_table->clear();
    ui->p_table->setColumnCount(0);
    ui->p_table->setRowCount(0);
    ui->logo->hide();
    ui->searchbox->show();
    ui->p_searchbtn->show();
    ui->iv_searchbtn->show();
    ui->searchedit->show();
    ui->journalbtn->show();
    ui->graphbtn->show();
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
    check.clear();
    int row=ui->basketlist_table->rowCount();
    int index = ui->product_table->currentRow();
    QString p_code;                            //쿼리문 전달할 변수
    QDate check_life = QDate::currentDate();
    QSqlQuery query;

    ui->pay_table->setColumnCount(3);
    ui->pay_table->setRowCount(row+1);
    ui->basketlist_table->setColumnWidth(0, 80);
    ui->basketlist_table->setColumnWidth(1, 40);
    ui->basketlist_table->setColumnWidth(2, 30);
    QList<QString> pay_header;
    pay_header.append("상품명");
    pay_header.append("수량");
    pay_header.append("가격");
    ui->pay_table->setHorizontalHeaderLabels(pay_header);


    query.prepare("select (product_code) from product where product_name= '"+p_name[index]+"'");
    query.exec();                                     //실행
    query.next();
    p_code=query.value(0).toString();       //상품테이블에서 상품코드가져오기

    query.prepare("select p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where p.product_code = '"+p_code+"'");
    query.exec();                           //상품코드로 상품명, 가격, 유통기한, 수량 가져오기

    QString basket_name, basket_num, b_code, i_life, checkcheck;
    check.append(QDate::fromString(i_life, "yyyy-MM-dd").daysTo(check_life));

    for(int i=0; i<row; i++){
        basket_name = ui->basketlist_table->item(i, 0)->text();
        basket_num = ui->basketlist_table->item(i, 2)->text();

        query.prepare("select (product_code) from product where product_name= '"+basket_name+"'");
        query.exec();
        query.next();
        b_code=query.value(0).toString();           //장바구니 이름으로 상품코드 가져오기

        query.prepare("select min(inventory_life) from inventory where product_code= '"+b_code+"'");
        query.exec();
        query.next();
        i_life=query.value(0).toString();           //상품코드로 유통기한 가져오기

        check.append(QDate::fromString(i_life, "yyyy-MM-dd").daysTo(check_life));
    }
    checkcheck.clear();
    for(int j=0; j<check.size(); j++){
        if(check[j]>0){
            checkcheck="nope";
        }
    }

    query.prepare("select max(sales_code) from paylist");
    query.exec();
    query.next();
    int max_code = query.value(0).toInt();

    for(int i=0; i<row; i++){
        basket_name = ui->basketlist_table->item(i, 0)->text();
        basket_num = ui->basketlist_table->item(i, 2)->text();

        query.prepare("select (product_code) from product where product_name= '"+basket_name+"'");
        query.exec();
        query.next();
        b_code=query.value(0).toString();           //장바구니 이름으로 상품코드 가져오기

        query.prepare("select min(inventory_life) from inventory where product_code= '"+b_code+"'");
        query.exec();
        query.next();
        i_life=query.value(0).toString();           //상품코드로 유통기한 가져오기

        if(checkcheck == "nope"){              //유통기한이 지난 상품 결제시
            qDebug()<<i_life;
            qDebug()<<check;
            QMessageBox::critical(this, tr("nope"), tr("Contains expired products"));
            break;
        }
        else{                           //상품 결제시
            query.prepare("UPDATE inventory SET inventory_number = inventory_number - "+basket_num+" WHERE product_code = '"+b_code+"' and inventory_life = '"+i_life+"'");
            query.exec();
            qDebug()<<i_life;
            qDebug()<<check;

            query.prepare("select inventory_number from inventory where product_code = '"+b_code+"' order by inventory_life limit 0, 1");
            query.exec();
            query.next();
            int numi=query.value(0).toInt();

            if(numi<0){
                query.prepare("delete from inventory where product_code = "+b_code+" and inventory_number <= 0 and inventory_life = '"+i_life+"'");
                query.exec();                   //유통기한이 가장 많이 지난 상품 삭제 min유통기한 삭제

                query.prepare("select min(inventory_life) from inventory where product_code= '"+b_code+"'");
                query.exec();
                query.next();
                i_life=query.value(0).toString();           //상품코드로 현재 min유통기한 가져오기

                query.prepare("UPDATE inventory SET inventory_number = inventory_number + "+QString::number(numi)+" WHERE product_code = "+b_code+" and inventory_life = '"+i_life+"'");
                query.exec();
            }
            else if(numi==0){
                query.prepare("delete from inventory where product_code = "+b_code+" and inventory_number <= 0 and inventory_life = '"+i_life+"'");
                query.exec();                   //유통기한이 가장 많이 지난 상품 삭제 min유통기한 삭제
            }

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

            query.prepare("insert into paylist (sales_code, product_code, sales_date, sales_time, sales_number) values("+QString::number(max_code+1)+", "+b_code+", curdate(), curtime(), '"+basket_num+"')");
            query.exec();                                     //실행
        }
    }

    int p_num=0;
    for(int i=0; i<row; i++){
        QString checkk=ui->basketlist_table->item(i, 2)->text();
        p_num+=checkk.toInt();
    }

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
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->searchbox->clear();
    ui->searchbox->addItem("이름");
    ui->searchbox->addItem("상품코드");
    ui->searchbox->addItem("분류");
    ui->searchbox->addItem("유통기한");
    ui->searchedit->clear();
    ui->searchbox->show();
    ui->p_searchbtn->hide();
    ui->iv_searchbtn->show();
    ui->searchedit->show();
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

    select_query=QString("select p.product_code as '상품코드', p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code"); //쿼리문 저장-분류에 맞는 컬럼값들 가져오기
    query.prepare(select_query);                         //준비
    query.exec();                                     //실행

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        iv_code.append(query.value(0).toString());
        iv_name.append(query.value(1).toString());
        iv_sale.append(query.value(2).toString());
        iv_life.append(query.value(3).toString());
        iv_number.append(query.value(4).toString());
        count++;
    }

    for(int i=0; i<count; i++){
        ui->iv_table->setColumnCount(5);
        ui->iv_table->setRowCount(count);
        ui->iv_table->setColumnWidth(0, 60);
        ui->iv_table->setColumnWidth(4, 50);
//        ui->iv_table->setColumnWidth(1, 70);
//        ui->iv_table->setColumnWidth(2, 70);
//        ui->iv_table->setColumnWidth(3, 70);

        ui->iv_table->setItem(i, 0, new QTableWidgetItem(iv_code[i]));
        ui->iv_table->setItem(i, 1, new QTableWidgetItem(iv_name[i]));
        ui->iv_table->setItem(i, 2, new QTableWidgetItem(iv_sale[i]));
        ui->iv_table->setItem(i, 3, new QTableWidgetItem(iv_life[i]));
        ui->iv_table->setItem(i, 4, new QTableWidgetItem(iv_number[i]));
    }

    QList<QString> iventory_header;
    iventory_header.append("상품코드");
    iventory_header.append("상품명");
    iventory_header.append("상품가격");
    iventory_header.append("유통기한");
    iventory_header.append("수량");
    ui->iv_table->setHorizontalHeaderLabels(iventory_header);
}

void MainWindow::on_p_lookbtn_clicked()
{
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->searchbox->clear();
    ui->searchbox->addItem("이름");
    ui->searchbox->addItem("상품코드");
    ui->searchbox->addItem("분류");
    ui->searchedit->clear();
    ui->searchbox->show();
    ui->p_searchbtn->show();
    ui->iv_searchbtn->hide();
    ui->searchedit->show();
    ui->today_date_label->hide();
    ui->iv_table->hide();
    ui->p_table->show();
    ui->soon_trashbtn->hide();
    ui->now_trashbtn->hide();
    ui->t_btn->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->t_table->hide();

    p_code.clear();
    p_name.clear();
    p_sale.clear();
    p_cartegory.clear();

    QString select_query;                            //쿼리문 전달할 변수
    QSqlQuery query;

    select_query=QString("SELECT * FROM product"); //쿼리문 저장-분류에 맞는 컬럼값들 가져오기
    query.prepare(select_query);                         //준비
    query.exec();                                     //실행

    int count=0;
    while(query.next()){                                //가져온상태.next()함수로 첫번째 변수를 가져옴
        p_code.append(query.value(0).toString());
        p_name.append(query.value(1).toString());
        p_sale.append(query.value(2).toString());
        if(query.value(3)==1){
            p_cartegory.append("라면");
        }
        else if(query.value(3)==2){
            p_cartegory.append("과자");
        }
        else if(query.value(3)==3){
            p_cartegory.append("음료");
        }
        else if(query.value(3)==4){
            p_cartegory.append("아이스크림");
        }
        else if(query.value(3)==5){
            p_cartegory.append("빵");
        }
        else if(query.value(3)==6){
            p_cartegory.append("커피");
        }
        else if(query.value(3)==7){
            p_cartegory.append("주류");
        }
        else if(query.value(3)==8){
            p_cartegory.append("초콜릿");
        }
        else if(query.value(3)==9){
            p_cartegory.append("껌");
        }
        else{
            p_cartegory.append("냉동식품");
        }
        count++;
    }

    for(int i=0; i<count; i++){
        ui->p_table->setColumnCount(4);
        ui->p_table->setRowCount(count);

        ui->p_table->setItem(i, 0, new QTableWidgetItem(p_code[i]));
        ui->p_table->setItem(i, 1, new QTableWidgetItem(p_name[i]));
        ui->p_table->setItem(i, 2, new QTableWidgetItem(p_sale[i]));
        ui->p_table->setItem(i, 3, new QTableWidgetItem(p_cartegory[i]));
    }

    QList<QString> product_header;
    product_header.append("상품코드");
    product_header.append("상품명");
    product_header.append("상품가격");
    product_header.append("카테고리");
    product_header.append("수량");
    ui->p_table->setHorizontalHeaderLabels(product_header);
}

void MainWindow::on_product_addbtn_clicked()
{
    l = new look(this);
    l->show();
}

void MainWindow::on_product_deletebtn_clicked()
{
    pd = new p_delete(this);
    pd->show();
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
    p_i_name.clear();
    p_i_num.clear();

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

    query.prepare("select p.product_name as '상품명', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code");
    query.exec();
    int i=0, i_count=0;
    while(query.next()){
        p_i_name.append(query.value(0).toString());
        p_i_num.append(query.value(1).toString());
        i++;
        i_count++;
    }
    for(int i=0; i<count; i++){
        int num=0;
        addbtn = new QPushButton("추가", this);
        ui->product_table->setColumnCount(4);
        ui->product_table->setRowCount(count);
        ui->product_table->setItem(i, 0, new QTableWidgetItem(p_name[i]));
        ui->product_table->setColumnWidth(0, 110);
        ui->product_table->setItem(i, 1, new QTableWidgetItem(p_sale[i]));
        ui->product_table->setColumnWidth(1, 55);

        for(int j=0; j<i_count; j++){
            if(p_name[i]==p_i_name[j]){
                num+=p_i_num[j].toInt();
            }
        }
        ui->product_table->setItem(i, 2, new QTableWidgetItem(QString::number(num)));
        ui->product_table->setColumnWidth(2, 10);
        ui->product_table->setCellWidget(i, 3, addbtn);
        ui->product_table->setColumnWidth(3, 20);
        connect(addbtn, SIGNAL(clicked()), this, SLOT(Onlistaddbtn_sensor_click()));
    }

    QList<QString> product_header;
    product_header.append("상품명");
    product_header.append("상품가격");
    product_header.append("수량");
    product_header.append("");
    ui->product_table->setHorizontalHeaderLabels(product_header);
}

void MainWindow::Onlistaddbtn_sensor_click(){
    int j = ui->basketlist_table->rowCount();
    int index = ui->product_table->currentRow();
    QString s_num, p_num;

    p_num=ui->product_table->item(index, 2)->text();

    if(p_num.toInt()==0){
        QMessageBox::critical(this, tr("nope"), tr("can't add any more"));
    }
    else{
        ui->product_table->setItem(index, 2, new QTableWidgetItem(QString::number(p_num.toInt()-1)));


        if(j==0){
            num.append(1);
            ui->basketlist_table->setColumnCount(4);
            ui->basketlist_table->setRowCount(j+1);
            ui->basketlist_table->setColumnWidth(0, 80);
            ui->basketlist_table->setColumnWidth(1, 20);
            ui->basketlist_table->setColumnWidth(2, 20);
            ui->basketlist_table->setColumnWidth(3, 20);
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
                        s_num=QString::number(num[i+1]);
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

        QList<QString> basket_header;
        basket_header.append("상품명");
        basket_header.append("가격");
        basket_header.append("수량");
        basket_header.append("");
        ui->basketlist_table->setHorizontalHeaderLabels(basket_header);

        paylist += p_sale[index].toInt();
        qDebug()<<"결제금액 >>";
        qDebug()<<paylist;
    }
}

void MainWindow::Onlistdelbtn_sensor_click(){
    int index = ui->basketlist_table->currentRow();
    QString pay, b_num, b_name, p_num;
    pay=ui->basketlist_table->item(index, 1)->text();
    int delpay = pay.toInt() * num[index];

    b_num=ui->basketlist_table->item(index, 2)->text();
    b_name=ui->basketlist_table->item(index, 0)->text();
    for(int i=0; i<p_name.size(); i++){
        if(b_name==p_name[i]){
            p_num=ui->product_table->item(i, 2)->text();
            ui->product_table->setItem(i, 2, new QTableWidgetItem(QString::number(p_num.toInt()+b_num.toInt())));
        }
    }

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

    QString code;                            //쿼리문 전달할 변수
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
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->searchbox->hide();
    ui->p_searchbtn->hide();
    ui->iv_searchbtn->hide();
    ui->searchedit->hide();
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
    tr_code.clear();

    QSqlQuery query;
    int index = ui->now_t_table->currentRow();

    QString tr_name, tr_life, tr_sale, tr_num, tr_search_name, tr_search_life;
    tr_name = ui->now_t_table->item(index, 0)->text();
    tr_sale = ui->now_t_table->item(index, 1)->text();
    tr_life = ui->now_t_table->item(index, 2)->text();
    tr_num = ui->now_t_table->item(index, 3)->text();

    query.prepare("select max(trash_life) from trash where trash_name = '"+tr_name+"'");
    query.exec();
    query.next();
    tr_search_life=query.value(0).toString();

    query.prepare("select trash_name from trash where trash_name = '"+tr_name+"'");
    query.exec();
    query.next();
    tr_search_name=query.value(0).toString();
    qDebug()<<tr_name;
    qDebug()<<tr_search_name;
    qDebug()<<tr_life;
    qDebug()<<tr_search_life;

    query.prepare("select product_code from product where product_name = '"+tr_name+"'");
    query.exec();
    query.next();
    tr_code=query.value(0).toString();

    query.prepare("delete from inventory where product_code = '"+tr_code+"' and inventory_life = '"+tr_life+"'");                         //준비
    query.exec();

    if(tr_name==tr_search_name && tr_life==tr_search_life){
        query.prepare("UPDATE trash SET trash_num = trash_num + "+tr_num+" WHERE trash_name = '"+tr_name+"' and trash_life = '"+tr_life+"'");
        query.exec();
    }
    else{
        query.prepare("insert into trash(trash_date, trash_name, trash_sale, trash_life, trash_num) values(now(), '"+tr_name+"', '"+tr_sale+"', '"+tr_life+"', '"+tr_num+"')");
        query.exec();
    }
    on_now_trashbtn_clicked();
}

void MainWindow::on_t_btn_clicked()
{
    t_date.clear();
    t_name.clear();
    t_sale.clear();
    t_life.clear();
    t_num.clear();

    ui->today_date_label->show();
    ui->now_t_table->hide();
    ui->p_table->hide();
    ui->t_table->show();
    ui->soon_t_table->hide();
    ui->iv_table->hide();
    ui->now_trashbtn->show();
    ui->soon_trashbtn->show();
    ui->t_btn->show();

    QSqlQuery query;

    query.prepare("select * from trash");                         //준비
    query.exec();

    int count=0;
    while(query.next()){                                //폐기테이블에서 데이터 몽땅 가져오기
        t_date.append(query.value(0).toString());
        t_name.append(query.value(1).toString());
        t_sale.append(query.value(2).toString());
        t_life.append(query.value(3).toString());
        t_num.append(query.value(4).toString());
        count++;
    }

    ui->t_table->setColumnCount(5);
    ui->t_table->setRowCount(t_date.size());
    ui->t_table->setColumnWidth(0, 145);
    ui->t_table->setColumnWidth(2, 60);
    ui->t_table->setColumnWidth(3, 90);
    ui->t_table->setColumnWidth(4, 30);

    for(int i=0; i<t_date.size(); i++){
        ui->t_table->setItem(i, 0, new QTableWidgetItem(t_date[i]));
        ui->t_table->setItem(i, 1, new QTableWidgetItem(t_name[i]));
        ui->t_table->setItem(i, 2, new QTableWidgetItem(t_sale[i]));
        ui->t_table->setItem(i, 3, new QTableWidgetItem(t_life[i]));
        ui->t_table->setItem(i, 4, new QTableWidgetItem(t_num[i]));
    }

    QList<QString> trash_header;
    trash_header.append("폐기날짜");
    trash_header.append("상품명");
    trash_header.append("상품가격");
    trash_header.append("유통기한");
    trash_header.append("수량");
    ui->t_table->setHorizontalHeaderLabels(trash_header);
}

void MainWindow::on_p_searchbtn_clicked()
{
    ui->p_table->clear();
    s_p_code.clear();
    s_p_name.clear();
    s_p_sale.clear();
    s_p_cartegory.clear();

    QString s_box, s_edit;                            //쿼리문 전달할 변수
    QSqlQuery query;
    int count=0;

    s_box = ui->searchbox->currentText();

    if(s_box=="이름"){
        s_edit = ui->searchedit->text();

        query.prepare("select product_code, product_name, product_sale, cartegory_code from product where product_name like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_p_code.append(query.value(0).toString());
            s_p_name.append(query.value(1).toString());
            s_p_sale.append(query.value(2).toString());
            if(query.value(3)==1){
                s_p_cartegory.append("라면");
            }
            else if(query.value(3)==2){
                s_p_cartegory.append("과자");
            }
            else if(query.value(3)==3){
                s_p_cartegory.append("음료");
            }
            else if(query.value(3)==4){
                s_p_cartegory.append("아이스크림");
            }
            else if(query.value(3)==5){
                s_p_cartegory.append("빵");
            }
            else if(query.value(3)==6){
                s_p_cartegory.append("커피");
            }
            else if(query.value(3)==7){
                s_p_cartegory.append("주류");
            }
            else if(query.value(3)==8){
                s_p_cartegory.append("초콜릿");
            }
            else if(query.value(3)==9){
                s_p_cartegory.append("껌");
            }
            else{
                s_p_cartegory.append("냉동식품");
            }
            i++;
            count++;
        }

        if(count==0){
            ui->p_table->clear();
            ui->p_table->setRowCount(0);
            ui->p_table->setColumnCount(0);
        }

        for(int i=0; i<count; i++){
            ui->p_table->setColumnCount(4);
            ui->p_table->setRowCount(count);

            ui->p_table->setItem(i, 0, new QTableWidgetItem(s_p_code[i]));
            ui->p_table->setItem(i, 1, new QTableWidgetItem(s_p_name[i]));
            ui->p_table->setItem(i, 2, new QTableWidgetItem(s_p_sale[i]));
            ui->p_table->setItem(i, 3, new QTableWidgetItem(s_p_cartegory[i]));
        }
    }
    else if(s_box=="상품코드"){
        s_edit = ui->searchedit->text();

        query.prepare("select product_code, product_name, product_sale, cartegory_code from product where product_code like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_p_code.append(query.value(0).toString());
            s_p_name.append(query.value(1).toString());
            s_p_sale.append(query.value(2).toString());
            if(query.value(3)==1){
                s_p_cartegory.append("라면");
            }
            else if(query.value(3)==2){
                s_p_cartegory.append("과자");
            }
            else if(query.value(3)==3){
                s_p_cartegory.append("음료");
            }
            else if(query.value(3)==4){
                s_p_cartegory.append("아이스크림");
            }
            else if(query.value(3)==5){
                s_p_cartegory.append("빵");
            }
            else if(query.value(3)==6){
                s_p_cartegory.append("커피");
            }
            else if(query.value(3)==7){
                s_p_cartegory.append("주류");
            }
            else if(query.value(3)==8){
                s_p_cartegory.append("초콜릿");
            }
            else if(query.value(3)==9){
                s_p_cartegory.append("껌");
            }
            else{
                s_p_cartegory.append("냉동식품");
            }
            i++;
            count++;
        }

        if(count==0){
            ui->p_table->clear();
            ui->p_table->setRowCount(0);
        }

        for(int i=0; i<count; i++){
            ui->p_table->setColumnCount(4);
            ui->p_table->setRowCount(count);

            ui->p_table->setItem(i, 0, new QTableWidgetItem(s_p_code[i]));
            ui->p_table->setItem(i, 1, new QTableWidgetItem(s_p_name[i]));
            ui->p_table->setItem(i, 2, new QTableWidgetItem(s_p_sale[i]));
            ui->p_table->setItem(i, 3, new QTableWidgetItem(s_p_cartegory[i]));
        }
    }
    else{
        s_edit = ui->searchedit->text();
        if(s_edit=="라면" || s_edit=="라" || s_edit=="면"){
            s_edit="1";
        }
        else if(s_edit=="과자" || s_edit=="과" || s_edit=="자"){
            s_edit="2";
        }
        else if(s_edit=="음료" || s_edit=="음" || s_edit=="료"){
            s_edit="3";
        }
        else if(s_edit=="아이스크림" || s_edit=="아" || s_edit=="아이" || s_edit=="아이스" || s_edit=="아이스크" || s_edit=="크림" || s_edit=="스크림"){
            s_edit="4";
        }
        else if(s_edit=="빵" || s_edit=="ㅃ" || s_edit=="빠"){
            s_edit="5";
        }
        else if(s_edit=="커피" || s_edit=="커" || s_edit=="피"){
            s_edit="6";
        }
        else if(s_edit=="주류" || s_edit=="주" || s_edit=="류"){
            s_edit="7";
        }
        else if(s_edit=="초콜릿" || s_edit=="초" || s_edit=="초콜"){
            s_edit="8";
        }
        else if(s_edit=="껌" || s_edit=="꺼" || s_edit=="ㄲ"){
            s_edit="9";
        }
        else if(s_edit=="냉동식품" || s_edit=="냉" || s_edit=="냉동" || s_edit=="냉동식" || s_edit=="식품"){
            s_edit="10";
        }
        else{
            QMessageBox::critical(this, tr("다시"), tr("Saved"));
        }

        query.prepare("select product_code, product_name, product_sale, cartegory_code from product where cartegory_code like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_p_code.append(query.value(0).toString());
            s_p_name.append(query.value(1).toString());
            s_p_sale.append(query.value(2).toString());
            if(query.value(3)==1){
                s_p_cartegory.append("라면");
            }
            else if(query.value(3)==2){
                s_p_cartegory.append("과자");
            }
            else if(query.value(3)==3){
                s_p_cartegory.append("음료");
            }
            else if(query.value(3)==4){
                s_p_cartegory.append("아이스크림");
            }
            else if(query.value(3)==5){
                s_p_cartegory.append("빵");
            }
            else if(query.value(3)==6){
                s_p_cartegory.append("커피");
            }
            else if(query.value(3)==7){
                s_p_cartegory.append("주류");
            }
            else if(query.value(3)==8){
                s_p_cartegory.append("초콜릿");
            }
            else if(query.value(3)==9){
                s_p_cartegory.append("껌");
            }
            else{
                s_p_cartegory.append("냉동식품");
            }
            i++;
            count++;
        }

        if(count==0){
            ui->p_table->clear();
            ui->p_table->setRowCount(0);
        }

        for(int i=0; i<count; i++){
            ui->p_table->setColumnCount(4);
            ui->p_table->setRowCount(count);

            ui->p_table->setItem(i, 0, new QTableWidgetItem(s_p_code[i]));
            ui->p_table->setItem(i, 1, new QTableWidgetItem(s_p_name[i]));
            ui->p_table->setItem(i, 2, new QTableWidgetItem(s_p_sale[i]));
            ui->p_table->setItem(i, 3, new QTableWidgetItem(s_p_cartegory[i]));
        }
    }
    QList<QString> product_header;
    product_header.append("상품코드");
    product_header.append("상품명");
    product_header.append("상품가격");
    product_header.append("카테고리");
    ui->p_table->setHorizontalHeaderLabels(product_header);
}

void MainWindow::on_iv_searchbtn_clicked()
{
    ui->iv_table->clear();
    s_iv_code.clear();
    s_iv_name.clear();
    s_iv_sale.clear();
    s_iv_life.clear();
    s_iv_num.clear();

    QString s_box, s_edit;                            //쿼리문 전달할 변수
    QSqlQuery query;
    int count=0;

    s_box = ui->searchbox->currentText();

    if(s_box=="이름"){
        s_edit = ui->searchedit->text();
        ui->iv_table->setColumnWidth(4, 40);

        query.prepare("select p.product_code as '상품코드', p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where product_name like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_iv_code.append(query.value(0).toString());
            s_iv_name.append(query.value(1).toString());
            s_iv_sale.append(query.value(2).toString());
            s_iv_life.append(query.value(3).toString());
            s_iv_num.append(query.value(4).toString());
            i++;
            count++;
        }

        if(count==0){
            ui->iv_table->clear();
            ui->iv_table->setRowCount(0);
            ui->iv_table->setColumnCount(0);
        }

        for(int i=0; i<count; i++){
            ui->iv_table->setColumnCount(5);
            ui->iv_table->setRowCount(count);

            ui->iv_table->setItem(i, 0, new QTableWidgetItem(s_iv_code[i]));
            ui->iv_table->setItem(i, 1, new QTableWidgetItem(s_iv_name[i]));
            ui->iv_table->setItem(i, 2, new QTableWidgetItem(s_iv_sale[i]));
            ui->iv_table->setItem(i, 3, new QTableWidgetItem(s_iv_life[i]));
            ui->iv_table->setItem(i, 4, new QTableWidgetItem(s_iv_num[i]));
        }
    }
    else if(s_box=="상품코드"){
        s_edit = ui->searchedit->text();
        ui->iv_table->setColumnWidth(4, 40);

        query.prepare("select p.product_code as '상품코드', p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where p.product_code like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_iv_code.append(query.value(0).toString());
            s_iv_name.append(query.value(1).toString());
            s_iv_sale.append(query.value(2).toString());
            s_iv_life.append(query.value(3).toString());
            s_iv_num.append(query.value(4).toString());
            i++;
            count++;
        }

        if(count==0){
            ui->iv_table->clear();
            ui->iv_table->setRowCount(0);
        }

        for(int i=0; i<count; i++){
            ui->iv_table->setColumnCount(5);
            ui->iv_table->setRowCount(count);

            ui->iv_table->setItem(i, 0, new QTableWidgetItem(s_iv_code[i]));
            ui->iv_table->setItem(i, 1, new QTableWidgetItem(s_iv_name[i]));
            ui->iv_table->setItem(i, 2, new QTableWidgetItem(s_iv_sale[i]));
            ui->iv_table->setItem(i, 3, new QTableWidgetItem(s_iv_life[i]));
            ui->iv_table->setItem(i, 4, new QTableWidgetItem(s_iv_num[i]));
        }
    }
    else if(s_box=="분류"){
        s_edit = ui->searchedit->text();
        ui->iv_table->setColumnWidth(4, 40);
        if(s_edit=="라면" || s_edit=="라" || s_edit=="면"){
            s_edit="1";
        }
        else if(s_edit=="과자" || s_edit=="과" || s_edit=="자"){
            s_edit="2";
        }
        else if(s_edit=="음료" || s_edit=="음" || s_edit=="료"){
            s_edit="3";
        }
        else if(s_edit=="아이스크림" || s_edit=="아" || s_edit=="아이" || s_edit=="아이스" || s_edit=="아이스크" || s_edit=="크림" || s_edit=="스크림"){
            s_edit="4";
        }
        else if(s_edit=="빵" || s_edit=="ㅃ" || s_edit=="빠"){
            s_edit="5";
        }
        else if(s_edit=="커피" || s_edit=="커" || s_edit=="피"){
            s_edit="6";
        }
        else if(s_edit=="주류" || s_edit=="주" || s_edit=="류"){
            s_edit="7";
        }
        else if(s_edit=="초콜릿" || s_edit=="초" || s_edit=="초콜"){
            s_edit="8";
        }
        else if(s_edit=="껌" || s_edit=="꺼" || s_edit=="ㄲ"){
            s_edit="9";
        }
        else if(s_edit=="냉동식품" || s_edit=="냉" || s_edit=="냉동" || s_edit=="냉동식" || s_edit=="식품"){
            s_edit="10";
        }
        else{
            QMessageBox::critical(this, tr("enope"), tr("nope"));
        }

        query.prepare("select p.product_code as '상품코드', p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량', p.cartegory_code from product p join inventory i on p.product_code = i.product_code where cartegory_code like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_iv_code.append(query.value(0).toString());
            s_iv_name.append(query.value(1).toString());
            s_iv_sale.append(query.value(2).toString());
            s_iv_life.append(query.value(3).toString());
            s_iv_num.append(query.value(4).toString());
            i++;
            count++;
        }

        if(count==0){
            ui->iv_table->clear();
            ui->iv_table->setRowCount(0);
        }

        for(int i=0; i<count; i++){
            ui->iv_table->setColumnCount(5);
            ui->iv_table->setRowCount(count);

            ui->iv_table->setItem(i, 0, new QTableWidgetItem(s_iv_code[i]));
            ui->iv_table->setItem(i, 1, new QTableWidgetItem(s_iv_name[i]));
            ui->iv_table->setItem(i, 2, new QTableWidgetItem(s_iv_sale[i]));
            ui->iv_table->setItem(i, 3, new QTableWidgetItem(s_iv_life[i]));
            ui->iv_table->setItem(i, 4, new QTableWidgetItem(s_iv_num[i]));
        }
    }
    else{
        s_edit = ui->searchedit->text();
        ui->iv_table->setColumnWidth(0, 60);
        ui->iv_table->setColumnWidth(4, 40);

        query.prepare("select p.product_code as '상품코드', p.product_name as '상품명', p.product_sale as '가격', i.inventory_life as '유통기한', i.inventory_number as '수량' from product p join inventory i on p.product_code = i.product_code where inventory_life like '"+s_edit+"%'");
        query.exec();

        int i=0;
        while(query.next()){
            s_iv_code.append(query.value(0).toString());
            s_iv_name.append(query.value(1).toString());
            s_iv_sale.append(query.value(2).toString());
            s_iv_life.append(query.value(3).toString());
            s_iv_num.append(query.value(4).toString());
            i++;
            count++;
        }

        if(count==0){
            ui->iv_table->clear();
            ui->iv_table->setRowCount(0);
            ui->iv_table->setColumnCount(0);
        }

        for(int i=0; i<count; i++){
            ui->iv_table->setColumnCount(5);
            ui->iv_table->setRowCount(count);

            ui->iv_table->setItem(i, 0, new QTableWidgetItem(s_iv_code[i]));
            ui->iv_table->setItem(i, 1, new QTableWidgetItem(s_iv_name[i]));
            ui->iv_table->setItem(i, 2, new QTableWidgetItem(s_iv_sale[i]));
            ui->iv_table->setItem(i, 3, new QTableWidgetItem(s_iv_life[i]));
            ui->iv_table->setItem(i, 4, new QTableWidgetItem(s_iv_num[i]));
        }
    }
    QList<QString> inventory_header;
    inventory_header.append("상품코드");
    inventory_header.append("상품명");
    inventory_header.append("상품가격");
    inventory_header.append("유통기한");
    inventory_header.append("수량");
    ui->iv_table->setHorizontalHeaderLabels(inventory_header);
}

void MainWindow::on_journalbtn_clicked()
{
    ui->graph_weekbtn->hide();
    ui->graph_monthbtn->hide();
    ui->graph_yearbtn->hide();
    ui->searchbox->hide();
    ui->p_searchbtn->hide();
    ui->iv_searchbtn->hide();
    ui->searchedit->hide();
    ui->iv_table->hide();
    ui->today_date_label->hide();
    ui->p_table->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->now_trashbtn->hide();
    ui->soon_trashbtn->hide();
    ui->t_table->hide();
    ui->t_btn->hide();
}

void MainWindow::on_graphbtn_clicked()
{
    ui->graph_weekbtn->show();
    ui->graph_monthbtn->show();
    ui->graph_yearbtn->show();
    ui->searchbox->hide();
    ui->p_searchbtn->hide();
    ui->iv_searchbtn->hide();
    ui->searchedit->hide();
    ui->iv_table->hide();
    ui->today_date_label->hide();
    ui->p_table->hide();
    ui->soon_t_table->hide();
    ui->now_t_table->hide();
    ui->now_trashbtn->hide();
    ui->soon_trashbtn->hide();
    ui->t_table->hide();
    ui->t_btn->hide();
}


void MainWindow::on_graph_weekbtn_clicked()
{
    g = new ggraph(this);
    g->show();
}


void MainWindow::on_graph_monthbtn_clicked()
{
    gm = new graph_month(this);
    gm->show();
}


void MainWindow::on_graph_yearbtn_clicked()
{
    gy = new graph_year(this);
    gy->show();
}

