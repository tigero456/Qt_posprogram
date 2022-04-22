#include "inventory_add.h"
#include "ui_inventory_add.h"
#include "mainwindow.h"
#include <QMessageBox>

inventory_add::inventory_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inventory_add)
{
    ui->setupUi(this);

    QString queryStr, cartegoryname;         //쿼리문 전달할 변수
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

inventory_add::~inventory_add()
{
    delete ui;
}

void inventory_add::on_addbtn_clicked()
{
    QString number, product, cartegory, p_code, c_code;
    int life=0;
    QSqlQuery q;

    number = ui->saleEdit->text();
    product = ui->product_comboBox->currentText();
    cartegory = ui->cartagory_comboBox->currentText();

    q.prepare("select product_code from product where product_name = '"+product+"'");                 //준비
    q.exec();                            //실행
    q.next();
    p_code=q.value(0).toString();

    q.prepare("select cartegory_code from cartegory where cartegory_name = '"+cartegory+"'");                 //준비
    q.exec();                            //실행
    q.next();
    c_code=q.value(0).toString();

    if(c_code.toInt()==1){
        life=180;
    }
    else if(c_code.toInt()==2){
        life=180;
    }
    else if(c_code.toInt()==3){
        life=180;
    }
    else if(c_code.toInt()==4){
        life=99999;
    }
    else if(c_code.toInt()==5){
        life=7;
    }
    else if(c_code.toInt()==6){
        life=30;
    }
    else if(c_code.toInt()==7){
        life=0;
    }
    else if(c_code.toInt()==8){
        life=180;
    }
    else if(c_code.toInt()==9){
        life=365;
    }
    else{
        life=365;
    }

    q.prepare("insert into inventory (product_code, inventory_life, inventory_number) values('"+p_code+"', curdate()+ + '"+QString::number(life)+"', '"+number+"')");

    if(q.exec()){
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
    }
        else{
        QMessageBox::critical(this, tr("error::"), q.lastError().text());
    }
}


void inventory_add::on_cartagory_comboBox_activated(int index)
{
    ui->product_comboBox->clear();
    QString queryStr, cartegory, productname, c_code;         //쿼리문 전달할 변수
    QSqlQuery query;

    cartegory = ui->cartagory_comboBox->currentText();

    queryStr=QString("select cartegory_code from cartegory where cartegory_name = '"+cartegory+"'"); //쿼리문 저장
    query.prepare(queryStr);                 //준비
    query.exec();                            //실행
    query.next();
    c_code=query.value(0).toString();

    queryStr=QString("select product_name from product where cartegory_code = '"+c_code+"'"); //쿼리문 저장
    query.prepare(queryStr);                 //준비
    query.exec();                            //실행

    while(query.next()){                     //가져온상태.next()함수로 첫번째 변수를 가져옴
        productname=query.value(0).toString();
        ui->product_comboBox->addItem(productname);
    }


}

