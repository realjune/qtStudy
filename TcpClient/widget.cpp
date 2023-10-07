#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_connectBtn_clicked()
{
    QString ip = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();


    // 链接服务器
    socket->connectToHost(QHostAddress(ip), port.toShort());

    // 链接服务器成功，soket对象会发出信号
    connect(socket, &QTcpSocket::connected, this, [this](){
        QMessageBox::information(this, "链接提示", "链接服务器成功");
        this->hide();
        Chat *c = new Chat(socket);
        c->show();

    });

    // 链接断开， soket会发出信号
    connect(socket, &QTcpSocket::disconnected, [this](){
        QMessageBox::warning(this, "连接提示","链接异常，网络断开");
    });

}

