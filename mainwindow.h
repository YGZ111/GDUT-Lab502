#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add_page.h"
#include <QPushButton>>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    add_page *add_con=NULL;
    QPushButton *con_bt=NULL;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sense_action_triggered();

    void on_pushButton_clicked();

    void on_con_add_clicked();
    void con_show();
    void on_btn_tem_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
