#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建TCP服务端对象
    server= new QTcpServer;
    // 启动TCP服务端
    server->listen(QHostAddress::AnyIPv4, PORT);
    // 收到客户端链接的信号关联
    connect(server, &QTcpServer::newConnection, this, &Widget::newClientHander);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHander() {
    // 建立TCP链接
    QTcpSocket *socket = server->nextPendingConnection();

    // 获取客户端地址
    QHostAddress hostAddr = socket->peerAddress();
    ui->ipLineEdit->setText(hostAddr.toString());
    // 获取客户端端口号
    ui->portLineEdit->setText(QString::number(socket->peerPort()));
    // 获取客户端标识
    ui->titleLabel->setText(socket->peerName());

    // 服务器收到
    // connect(socket, &QTcpSocket::readyRead, this, &Widget::clientInfoSlot);

    // 启动线程
    MyThread *t = new MyThread(socket);
    t->start();

    // 关联接收自定义信号：发送信号的对象，发送的信号，接收信号的对象，接收信号的函数
    connect(t, &MyThread::sendToWidget,this, &Widget::threadSlot);
}


//void Widget::clientInfoSlot() {
//    QTcpSocket *s = (QTcpSocket *)sender();
//    ui->messageEdit->setText(QString(s->readAll()));
//}

// 接收信号方法
void Widget::threadSlot(QByteArray b) {
    ui->messageEdit->setText(QString(b));
}
