#include "add_page.h"
#include "ui_add_page.h"
#include "QSerialPortInfo"
#include "mainwindow.h"
#include"confirm_page.h"
add_page::add_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_page)
{
    ui->setupUi(this);
    setFixedSize(507,313);
    sreialport=new QSerialPort;//实例化串口对象
    QStringList seialNameport;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()){
        seialNameport<<info.portName();
    }
    ui->serial_name->addItems(seialNameport);
}

add_page::~add_page()
{
    delete ui;
}
QString add_page::get_name()
{
    return this->ui->lineEdit->text();
}
void add_page::on_add_bt_clicked()
{
    QSerialPort::BaudRate baudRate;
    if(ui->comboBox_3->currentText()=="4800"){
        baudRate=QSerialPort::Baud4800;
    }
    else if(ui->comboBox_3->currentText()=="9600"){
        baudRate=QSerialPort::Baud9600;//枚举类型
    }
    else if(ui->comboBox_3->currentText()=="115200"){
        baudRate=QSerialPort::Baud115200;
    }
    emit add_sens();
    emit this->destroyed();
    this->close();
}

void add_page::on_cancel_bt_clicked()
{
    this->close();
}
