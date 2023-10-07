 #include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 链接信号与槽 谁发出信号 发出什么信号 谁处理信号
    connect(ui->cmdlineEdit, SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));
    connect(ui->cancelButton, &QPushButton::clicked, this, &Widget::on_cancelButton_clicked);
    connect(ui->browserButton, &QPushButton::clicked,[this](){
        QMessageBox::information(this, "信息", "点击浏览");
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_commitButton_clicked()
{
    // 获取edit line 数据
    QString program = ui->cmdlineEdit->text();
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}


void Widget::on_cancelButton_clicked()
{
    this->close();
}

