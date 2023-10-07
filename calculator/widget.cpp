#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 窗口大小
    this->setMaximumSize(200, 300);
    this->setMinimumSize(200, 300);

    this->setWindowTitle("计算器");

    // 设置字体
    QFont mainLineFont("仿宋", 12);
                       ui->lineEdit->setFont(mainLineFont);

    // 设置图标
    QIcon icon("D:\\dev\\QTProjects\\QtOnline\\calculator\\delete.png");
                       ui->delBtn->setIcon(icon);

    // 设置背景色
    ui->equalBtn->setStyleSheet("background:blue");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneBtn_clicked()
{
    expression +="1";
    ui->lineEdit->setText(expression);
}



void Widget::on_twoBtn_clicked()
{
    expression +="2";
    ui->lineEdit->setText(expression);
}


void Widget::on_threeBtn_clicked()
{
    expression +="3";
    ui->lineEdit->setText(expression);
}


void Widget::on_fourBtn_clicked()
{
    expression +="4";
    ui->lineEdit->setText(expression);
}


void Widget::on_fiveBtn_clicked()
{
    expression +="5";
    ui->lineEdit->setText(expression);
}


void Widget::on_sixBtn_clicked()
{
    expression +="6";
    ui->lineEdit->setText(expression);
}


void Widget::on_sevenBtn_clicked()
{
    expression +="7";
    ui->lineEdit->setText(expression);
}


void Widget::on_eightBtn_clicked()
{
    expression +="8";
    ui->lineEdit->setText(expression);
}


void Widget::on_nineBtn_clicked()
{
    expression +="9";
    ui->lineEdit->setText(expression);
}

void Widget::on_zeroBtn_clicked()
{
    expression +="0";
    ui->lineEdit->setText(expression);
}

void Widget::on_leftBtn_clicked()
{
    expression +="(";
    ui->lineEdit->setText(expression);
}

void Widget::on_rightBtn_clicked()
{
    expression +=")";
    ui->lineEdit->setText(expression);
}

void Widget::on_addBtn_clicked()
{
    expression +="+";
    ui->lineEdit->setText(expression);
}

void Widget::on_subtBtn_clicked()
{
    expression +="-";
    ui->lineEdit->setText(expression);
}

void Widget::on_multBtn_clicked()
{
    expression +="*";
    ui->lineEdit->setText(expression);
}

void Widget::on_divBtn_clicked()
{
    expression +="/";
    ui->lineEdit->setText(expression);
}

void Widget::on_clearbtn_clicked()
{
    expression.clear();
    ui->lineEdit->clear();
}


void Widget::on_delBtn_clicked()
{
    expression.chop(1);
    ui->lineEdit->setText(expression);
}


void Widget::on_equalBtn_clicked()
{
    qDebug() << "onEqualBtnClicked";
    QStack<int> s_num, s_opt;
    char opt[128]={0};
    int i=0, tmp = 0, num1, num2;

    // 把QString转成char *
    QByteArray ba = expression.toLatin1();//QByteArray::fromHex(expression.toLatin1().data()); // QString 转成 ByteArray
    strcpy(opt, ba.data()); // data可以把ByteArray转成char *

    while(opt[i] != '\0'|| s_opt.empty() != true) {

        qDebug() << opt[i];
        if (opt[i] >='0' && opt[i] <='9') {
            tmp = tmp * 10 + opt[i] - '0';
            i++;

            if (opt[i] <'0' || opt[i] > '9') {
                s_num.push(tmp);
                tmp = 0;
            }
            qDebug() << tmp;
        } else {
            if (s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top()) ||
                (s_opt.top() == '(' && opt[i] != ')')) {
                s_opt.push(opt[i]);
                i++;
                continue;
            }
            if (s_opt.top() == '(' && opt[i] == ')') { // 空括号
                s_opt.pop();
                i++;
                continue;
            }
            if ((Priority(opt[i]) <= Priority(s_opt.top())) || (opt[i] == ')' && s_opt.top() != '(') ||
                         (opt[i]=='\0' && s_opt.empty() != true)) {
                char ch = s_opt.top();
                s_opt.pop();
                switch(ch){
                case '+':
                    num1=s_num.top();
                    s_num.pop();
                    num2=s_num.top();
                    s_num.pop();
                    s_num.push(num1+num2);
                        break;
                case '-':
                    num1=s_num.top();
                    s_num.pop();
                    num2=s_num.top();
                    s_num.pop();
                    s_num.push(num2-num1);
                    break;
                case '*':
                    num1=s_num.top();
                    s_num.pop();
                    num2=s_num.top();
                    s_num.pop();
                    s_num.push(num1*num2);
                    break;
                case '/':
                        num1=s_num.top();
                        s_num.pop();
                        num2=s_num.top();
                        s_num.pop();
                        s_num.push(num1/num2);
                        break;
                }
            }
        }
    }
    ui->lineEdit->setText(QString::number(s_num.top()));
    expression.clear();
}

int Widget::Priority(char ch) {
    switch(ch) {
    case '(':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
        return 1;
    default:
        return 0;
    }
}


