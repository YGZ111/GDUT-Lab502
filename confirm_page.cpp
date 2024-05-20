#include "confirm_page.h"
#include "ui_confirm_page.h"
#include "mainwindow.h"
#include "log_in.h"
#include "ui_log_in.h"
#include<QString>
confirm_page::confirm_page(QWidget *log_in) :
    QDialog(log_in),
    ui(new Ui::confirm_page)
{
    ui->setupUi(this);

}

confirm_page::~confirm_page()
{
    delete ui;
}
void confirm_page::show_stu(QString stu,QString stu2,QString stu3)
{

    ui->stu_num->setText(stu);//准考证号

    ui->shenfen->setText(stu2);//考生组别

    ui->zubie->setText(stu3);
}
void confirm_page::on_con_ok_btn_clicked()
{
    MainWindow *main_page=new MainWindow;
    main_page->show();
    this->close();
}

void confirm_page::on_con_ret_btn_clicked()
{
    emit this->accepted();//发一个信号过去
    this->close();
}
