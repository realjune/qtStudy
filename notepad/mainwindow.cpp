#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newAction_N, &QAction::triggered, this, &MainWindow::newActionSlot);
    connect(ui->openAction_O, &QAction::triggered, this, &MainWindow::openActionSlot);
    connect(ui->saveAction_S, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot() {
    ui->textEdit->clear();
    this->setWindowTitle("新建文档");
}

void MainWindow::openActionSlot() {
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件", QCoreApplication::applicationFilePath(), "*.cpp");
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择一个文件");
    } else {
//        qDebug() << fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
    }
}

void MainWindow::saveActionSlot() {
    QString fileName = QFileDialog::getSaveFileName(this, "选择一个文件",
QCoreApplication::applicationFilePath());
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择一个文件");
    } else {
        QFile file(fileName);
        QByteArray ba = ui->textEdit->toPlainText().toUtf8();
//        ba.append(ui->textEdit->toPlainText());
        file.open(QIODevice::WriteOnly);
        file.write(ba);
        file.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k) {
    if (k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_S) {
        saveActionSlot();
        qDebug() << "key: " << k->key();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m) {
    QPoint pt = m->pos();
    qDebug() << "mouse " << pt;
    if (m->button() == Qt::LeftButton) {
        qDebug() << "鼠标左键按下";
    } else if (m->button() == Qt::RightButton) {
        qDebug() << "鼠标右键按下";
    }
}
