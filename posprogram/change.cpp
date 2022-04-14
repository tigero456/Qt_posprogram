#include "change.h"
#include "ui_change.h"
#include "mainwindow.h"
#include <QMessageBox>

change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
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

change::~change()
{
    delete ui;
}

void change::on_addbtn_clicked()
{
    QString sale, code, p_code, product;
    QSqlQuery q;

    sale = ui->saleEdit->text();

    //nsale = Integer.parseInt(sale);
    product = ui->product_comboBox->currentText();

    code=QString("select product_code from product where product_name = '"+product+"'");
    q.prepare(code);
    q.exec();
    q.next();
    p_code=q.value(0).toString();

    qDebug()<<p_code;

    q.prepare("update product set product_sale = '"+sale+"' where product_code = '"+p_code+"'");

    if(q.exec()){
        QMessageBox::critical(this, tr("Change"), tr("Changed"));
    }
        else{
        QMessageBox::critical(this, tr("error::"), q.lastError().text());
    }
}

void change::on_cartagory_comboBox_activated(int index)
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

