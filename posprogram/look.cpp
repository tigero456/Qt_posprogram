#include "look.h"
#include "ui_look.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QVector>

look::look(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::look)
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
        ui->comboBox->addItem(cartegoryname);
    }
}

look::~look()
{
    delete ui;
}


void look::on_addbtn_clicked()
{
    QString name, sale, cartegory, code, c_code;
    QSqlQuery q;

    name = ui->nameEdit->text();
    sale = ui->saleEdit->text();
    cartegory = ui->comboBox->currentText();

    code=QString("select cartegory_code from cartegory where cartegory_name='"+cartegory+"'");
    q.prepare(code);
    q.exec();
    q.next();
    c_code=q.value(0).toString();

    q.prepare("insert into product (product_name, product_sale, cartegory_code) values('"+name+"', '"+sale+"', '"+c_code+"')");

    if(q.exec()){
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
    }
        else{
        QMessageBox::critical(this, tr("error::"), q.lastError().text());
    }
}

