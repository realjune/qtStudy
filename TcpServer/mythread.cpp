#include "mythread.h"

MyThread::MyThread(QTcpSocket *s)
{
    socket = s;
}

void MyThread::run() {
    connect(socket, &QTcpSocket::readyRead, this, &MyThread::clientInfoSlot);
}

void MyThread::clientInfoSlot() {
//    qDebug() << socket->readAll();
    QByteArray ba= socket->readAll();
    emit sendToWidget(ba); // 发送信号
}
