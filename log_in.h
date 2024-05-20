#ifndef LOG_IN_H
#define LOG_IN_H

#include <QDialog>
#include<QString>
#include<QDebug>
#include <QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include <QMessageBox>
#include"confirm_page.h"//确认页头文件
namespace Ui {
class log_in;
}

class log_in : public QDialog
{
    Q_OBJECT

public:
    explicit log_in(QWidget *parent = nullptr);
    ~log_in();
    confirm_page *confirm=NULL;//用来保存确认页面的实列化地址
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//创建数据库实例

private slots:
    void on_pushButton_clicked();

    void on_log_btn_clicked();

private:
    Ui::log_in *ui;
};

#endif // LOG_IN_H
