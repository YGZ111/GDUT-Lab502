#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "control_page.h"
#include "add_page.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //一般在qt构造函数中初始化
    this->add_con=new add_page; //实例化控制添加界面对象
    connect(this->add_con,&add_page::add_sens,[=](){
        this->con_show();
    });
    connect(add_con, SIGNAL(add_sens()),this,SLOT(con_show()));
    con_show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::con_show()
{

}

void MainWindow::on_sense_action_triggered()//无用
{
}

void MainWindow::on_pushButton_clicked()//添加按钮动作
{

}

void MainWindow::on_con_add_clicked()
{
    add_con->show();
}

void MainWindow::on_btn_tem_clicked()
{

}
