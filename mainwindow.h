#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QStackedWidget>
#include <QRadioButton>
#include <QTabWidget>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QNetworkAddressEntry>
#include <QProcess>
#include <QtMqtt/qmqttclient.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



public slots:
    //void setClientPort(int p);

private slots:

    //void connectToMqttServer(const QString& serverAddress, unsigned short port, const QString& username, const QString& password, const QString& sTopic, const QString& pTopic);

    void on_d_save_clicked();

    void on_DTU_clicked();

    void on_localnetwork_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_l_save_clicked();

    //void on_buttonConnect_clicked();
    //void on_buttonQuit_clicked();
    void updateLogStateChange();

    void brokerDisconnected();

   // void on_buttonPublish_clicked();

   // void on_buttonSubscribe_clicked();


private:
    Ui::MainWindow *ui;
    QMqttClient *mqttClient;
    QMqttClient *m_client;

signals:
    //void startConnect(const QString& serverAddress, unsigned short port, const QString& username, const QString& password,const QString& Stopic, const QString& Ptopic);
};
#endif // MAINWINDOW_H
