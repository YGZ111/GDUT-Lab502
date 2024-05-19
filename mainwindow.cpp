#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "mqttworker.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->baudRate->addItem("4800");
    ui->baudRate->addItem("9600");
    ui->baudRate->addItem("19200");
    ui->baudRate->addItem("115200");

    ui->baudRate->setCurrentIndex(1);


    //ui->localnetwork->setChecked(true);
    //设置第一页DTU的信息
    ui->DTU->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);


    //mqtt客户端
    m_client = new QMqttClient(this);


    QString mqttIp = ui->mqtt_ip->text();
    unsigned short mqttPort = ui->l_port->text().toUShort();
    QString mqttUser = ui->l_user->text();
    QString mqttPassword = ui->l_password ->text();
    QString sTopic =ui->subscribeTopic->text();
    QString pTopic =ui->publishTopic->text();

    // Connect to MQTT server
    m_client->setHostname("192.168.89.130");
    m_client->setPort(1884);
    m_client->setUsername("admin");
    m_client->setPassword("public");


    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_d_save_clicked()
{
    QString d_port = ui->d_port->currentText();
    QString d_Brate = ui->baudRate->currentText();



    qDebug() << d_Brate ;
}

void MainWindow::on_DTU_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_localnetwork_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index==0)
    {
        QString ipv4, default_Gateway;

        QProcess process;
        process.start("route", QStringList() << "print");
        process.waitForFinished();
        QString result = process.readAllStandardOutput();

        // Split the output into lines
        QStringList lines = result.split("\n", QString::SkipEmptyParts);

        // Iterate through each line
        foreach (const QString &line, lines)
        {
            // Check if the line contains "0.0.0.0" (default route)
            if (line.contains(QRegExp("\\b0\\.0\\.0\\.0\\b")))
            {
                // Split the line into fields
                QStringList fields = line.simplified().split(" ", QString::SkipEmptyParts);
                if (fields.size() >= 3)
                {
                    ipv4 = fields[3];
                    default_Gateway = fields[2];
                    break; // Stop searching after finding the default route
                }
            }
        }




        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

        foreach (QNetworkInterface interface, interfaces)
        {
            // 过滤掉回环接口和未激活接口
            if (interface.flags().testFlag(QNetworkInterface::IsLoopBack) || !interface.flags().testFlag(QNetworkInterface::IsUp))
                continue;

            // 获取该接口的地址条目列表
            QList<QNetworkAddressEntry> entries = interface.addressEntries();

            foreach (QNetworkAddressEntry entry, entries)
            {
                if (entry.ip().toString() == ipv4)
                {
                    QString information;
                    information += "接口名称:" + interface.humanReadableName() + "\n"
                            + "IP地址:" + entry.ip().toString() + "\n"
                            + "子网掩码:" + entry.netmask().toString() + "\n"
                            + "默认网关:" + default_Gateway + "\n"
                            + "广播地址:" + entry.broadcast().toString() + "\n";
                    ui->networkInformation->setPlainText(information);

//                    qDebug() << "接口名称:" << interface.humanReadableName();
//                    qDebug() << "IP地址:" << entry.ip().toString();
//                    qDebug() << "子网掩码:" << entry.netmask().toString();
//                    qDebug() << "默认网关:" << default_Gateway;
//                    qDebug() << "广播地址:" << entry.broadcast().toString();
                }
            }
        }
    }
}




//void MainWindow::on_buttonQuit_clicked()
//{
//    QApplication::quit();
//}

void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    //qDebug() << content ;
    if(m_client->state() ==2 )
        qDebug() << "连接成功" ;
    else if(m_client->state() ==0 )
        qDebug() << "断开连接" ;
    //ui->editLog->insertPlainText(content);
}


void MainWindow::brokerDisconnected()
{
      //  qDebug() << "断开连接" ;
//    ui->lineEditHost->setEnabled(true);
//    ui->spinBoxPort->setEnabled(true);
//    ui->buttonConnect->setText(tr("Connect"));
}

//void MainWindow::setClientPort(int p)
//{
//    m_client->setPort(p);
//}



void MainWindow::on_l_save_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected) {
//        ui->lineEditHost->setEnabled(false);
//        ui->spinBoxPort->setEnabled(false);
//        ui->buttonConnect->setText(tr("Disconnect"));
        m_client->connectToHost();

    }
    else {
//        ui->lineEditHost->setEnabled(true);
//        ui->spinBoxPort->setEnabled(true);
//        ui->buttonConnect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }

}



