#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startBtn_clicked()
{

    myTimerId = this->startTimer(TIMEOUT);
    qDebug()<<"start ... "<< myTimerId;
}

void Widget::timerEvent(QTimerEvent *event) {
    if (event->timerId() != myTimerId) {
        return;
    }

    qDebug()<<"timerEvent "<<event->timerId();
}


void Widget::on_pushButton_2_clicked()
{
    this->killTimer(myTimerId);
    qDebug()<<"stop ... "<< myTimerId;
}

