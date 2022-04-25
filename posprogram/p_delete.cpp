#include "p_delete.h"
#include "ui_p_delete.h"
#include "mainwindow.h"
#include <QMessageBox>

p_delete::p_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p_delete)
{
    ui->setupUi(this);
    QString queryStr, cartegoryname;;         //쿼리문 전달할 변수
    QSqlQuery query;                         //데이터베이스에 전달할 쿼리변수


    model = new QSqlTableModel(this);
    queryStr=QString("select cartegory_name from cartegory"); //쿼리문 저장
    query.prepare(queryStr);                 //준비
    query.exec();                            //실행


    while(query.next()){                     //가져온상태.next()함수로 첫번째 변수를 가져옴
        cartegoryname=query.value(0).toString();
        ui->cartagory_comboBox->addItem(cartegoryname);
    }
}

p_delete::~p_delete()
{
    delete ui;
}

void p_delete::on_cartagory_comboBox_activated(int index)
{
    QString queryStr, cartegory, productname, c_code;         //쿼리문 전달할 변수
    QSqlQuery query;

    cartegory = ui->cartagory_comboBox->currentText();

    qDebug()<<cartegory;

    queryStr=QString("select cartegory_code from cartegory where cartegory_name = '"+cartegory+"'"); //쿼리문 저장
    query.prepare(queryStr);                 //준비
    query.exec();                            //실행
    query.next();
    c_code=query.value(0).toString();

    qDebug()<<c_code;

    queryStr=QString("select product_name from product where cartegory_code = '"+c_code+"'"); //쿼리문 저장
    query.prepare(queryStr);                 //준비
    query.exec();                            //실행

    while(query.next()){                     //가져온상태.next()함수로 첫번째 변수를 가져옴
        productname=query.value(0).toString();
        ui->product_comboBox->addItem(productname);
    }
}

void p_delete::on_delbtn_clicked()
{
    QString product;
    QSqlQuery q;

    //nsale = Integer.parseInt(sale);
    product = ui->product_comboBox->currentText();

    q.prepare("delete from product where product_name = '"+product+"'");

    if(q.exec()){
        QMessageBox::critical(this, tr("Change"), tr("Changed"));
    }
        else{
        QMessageBox::critical(this, tr("error::"), q.lastError().text());
    }
}

