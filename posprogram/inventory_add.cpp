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
    QString number, product, cartegory, p_namecode, c_code, sql_life, p_code;
    QSqlQuery q;

    sql_life.clear();

    QDate code_life, stCurrentDate = QDate::currentDate();

    number = ui->saleEdit->text();
    product = ui->product_comboBox->currentText();
    cartegory = ui->cartagory_comboBox->currentText();


    q.prepare("select product_code from product where product_name = '"+product+"'");                 //준비
    q.exec();                            //실행
    q.next();
    p_namecode=q.value(0).toString();

    q.prepare("select cartegory_code from cartegory where cartegory_name = '"+cartegory+"'");                 //준비
    q.exec();                            //실행
    q.next();
    c_code=q.value(0).toString();

    if(c_code.toInt()==1){
        stCurrentDate = stCurrentDate.addDays(180);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 180 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else if(c_code.toInt()==2){
        stCurrentDate = stCurrentDate.addDays(180);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 180 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else if(c_code.toInt()==3){
        stCurrentDate = stCurrentDate.addDays(180);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 180 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else if(c_code.toInt()==4){
        q.prepare("select product_code from inventory where product_code = '"+p_namecode+"'");                 //준비
        q.exec();                            //실행
        q.next();
        p_code=q.value(0).toString();

        q.prepare("update inventory set inventory_life = NULL where product_code = '"+p_code+"'");

        if(q.exec()){
            QMessageBox::critical(this, tr("Save"), tr("Saved"));
        }
            else{
            QMessageBox::critical(this, tr("error::"), q.lastError().text());
        }
    }
    else if(c_code.toInt()==5){
        stCurrentDate = stCurrentDate.addDays(7);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 7 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else if(c_code.toInt()==6){
        stCurrentDate = stCurrentDate.addDays(30);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 30 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else if(c_code.toInt()==7){
        q.prepare("select product_code from inventory where product_code = '"+p_namecode+"'");                 //준비
        q.exec();                            //실행
        q.next();
        p_code=q.value(0).toString();

        q.prepare("update inventory set inventory_life = NULL where product_code = '"+p_code+"'");

        if(q.exec()){
            QMessageBox::critical(this, tr("Save"), tr("Saved"));
        }
            else{
            QMessageBox::critical(this, tr("error::"), q.lastError().text());
        }
    }
    else if(c_code.toInt()==8){
        stCurrentDate = stCurrentDate.addDays(180);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 180 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else if(c_code.toInt()==9){
        stCurrentDate = stCurrentDate.addDays(365);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 365 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }
    else{
        stCurrentDate = stCurrentDate.addDays(365);
        code_life=stCurrentDate;        //DB에 저장된 유통기한

        q.prepare("select date_add(curdate(), interval 365 day)");                 //준비
        q.exec();                            //실행
        q.next();
        sql_life=q.value(0).toString();
    }

    q.prepare("select product_code from inventory where product_code = '"+p_namecode+"'");                 //준비
    q.exec();                            //실행
    q.next();
    p_code=q.value(0).toString();

    qDebug()<<p_code;
    qDebug()<<p_namecode;
    qDebug()<<sql_life;
    qDebug()<<code_life.toString(Qt::ISODate);
    if(c_code.toInt()!=4 && c_code.toInt()!=7){
        if(p_code == p_namecode && sql_life == code_life.toString(Qt::ISODate)){
            q.prepare("update inventory set inventory_number = (inventory_number + '"+number+"') where inventory_life = '"+sql_life+"'");                 //준비

            if(q.exec()){
                QMessageBox::critical(this, tr("Save"), tr("Saved"));
            }
                else{
                QMessageBox::critical(this, tr("error::"), q.lastError().text());
            }
        }
        else{
            q.prepare("insert into inventory (product_code, inventory_life, inventory_number) values('"+p_namecode+"', '"+sql_life+"', '"+number+"')");

            if(q.exec()){
                QMessageBox::critical(this, tr("Save"), tr("Saved"));
            }
                else{
                QMessageBox::critical(this, tr("error::"), q.lastError().text());
            }
        }
    }
}


void inventory_add::on_cartagory_comboBox_activated(int index)
{
    ui->product_comboBox->clear();
    ui->saleEdit->clear();
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

