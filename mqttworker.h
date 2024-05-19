#ifndef MQTTWORKER_H
#define MQTTWORKER_H

#include <QObject>
#include <QDebug>
#include <QtMqtt/qmqttclient.h>

class MqttWorker : public QObject
{
    Q_OBJECT
public:
    explicit MqttWorker(QObject *parent = nullptr);


signals:


private slots:


private:

};


#endif // MQTTWORKER_H
