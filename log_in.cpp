#include "log_in.h"
#include "ui_log_in.h"
#include "confirm_page.h"
#include <QString>
#include<QDebug>
#include <QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include <QMessageBox>
log_in::log_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
    setFixedSize(274,195);
    this->confirm=new confirm_page;//实例化确认页面
    connect(this->confirm,&confirm_page::accepted,[=](){
        this->show();
    });
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//创建数据库实例
    //设置相关连接信息
    db.setHostName("localhost");//主机ip,如连接服务器数据库，可改为服务器ip
    db.setUserName("root");//设置用户名
    db.setDatabaseName("mysql");
    db.setPassword("20010520");
    db.setPort(3306);

    if(!db.open())
    {
        qDebug()<<"失败原因"<<db.lastError().text();
    }
    else
    {
        qDebug()<<"连接成功";
    }
}

log_in::~log_in()
{
    delete ui;
}

void log_in::on_pushButton_clicked()
{

}
void log_in::on_log_btn_clicked()
{
    QSqlQuery query;
    QString sql="select * from complete_person";//*号可换成列的名字，改变查询范围
    query.exec(sql);
    while(query.next())
    {
        //取出当前记录的字段值
        qDebug()<<query.value(0).toString();
        if(ui->lineEdit->text()==query.value(0).toString()&&ui->group->currentText()==query.value(2))
        {
            confirm->show();
            this->hide();
            QString num=ui->lineEdit->text();
            QString num2=ui->group->currentText();
            QString num3=query.value(1).toString();
            this->confirm->show_stu(num,num2,num3);
            break;
        }
    }
    if(!(query.next()))//如没有找到此选手
    {
        QString title="信息错误提示框";   //弹出提示错误窗口
        QString strinfo="准考证号或组别填写错误";
        QMessageBox::information(this,title,strinfo,
                                 QMessageBox::Ok,QMessageBox::NoButton);
        db.close();
    }
}
