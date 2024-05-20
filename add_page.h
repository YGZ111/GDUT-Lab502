#ifndef ADD_PAGE_H
#define ADD_PAGE_H

#include <QDialog>
#include <QSerialPort>
namespace Ui {
class add_page;
}

class add_page : public QDialog
{
    Q_OBJECT

public:
    explicit add_page(QWidget *parent = nullptr);
    ~add_page();
    QString get_name();
    QSerialPort *sreialport=NULL;//用来保存串口对象的实列化地址
signals:
    void add_sens();
private slots:
    void on_add_bt_clicked();

    void on_cancel_bt_clicked();

private:
    Ui::add_page *ui;
};

#endif // ADD_PAGE_H
