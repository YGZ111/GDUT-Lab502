#ifndef CONFIRM_PAGE_H
#define CONFIRM_PAGE_H

#include <QDialog>

namespace Ui {
class confirm_page;
}

class confirm_page : public QDialog
{
    Q_OBJECT

public:
    void show_stu(QString stu,QString stu2,QString stu3);

    explicit confirm_page(QWidget *parent = nullptr);
    ~confirm_page();

private slots:
    void on_con_ok_btn_clicked();

    void on_con_ret_btn_clicked();

public:
    Ui::confirm_page *ui;
};

#endif // CONFIRM_PAGE_H
