#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Widget::onTimer);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startBtn_clicked()
{
    timer->start(1000);
}


void Widget::on_stopBtn_clicked()
{
    timer->stop();

}

void Widget::onTimer() {
    qDebug()<<"onTimer " << times;
    times++;
}

