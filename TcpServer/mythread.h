#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class MyThread: public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QTcpSocket *s);
    void run();

public slots:
    void clientInfoSlot();

signals:
    void sendToWidget(QByteArray b); // 定义信号

private:
    QTcpSocket *socket;

};

#endif // MYTHREAD_H
