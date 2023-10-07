#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#define TIMEOUT 1000

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startBtn_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    virtual void timerEvent(QTimerEvent *event);
    int myTimerId;
};
#endif // WIDGET_H
