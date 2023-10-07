#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    socket = s;
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_pushButton_clicked()
{
    ui->messageEdit->clear();
}


void Chat::on_sendBtn_clicked()
{
    QByteArray ba = ui->messageEdit->toPlainText().toUtf8();
    socket->write(ba);
}

