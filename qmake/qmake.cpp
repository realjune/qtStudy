#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

// 程序入口
int main(int argc, char *argv[]) {
	// app入口
	QApplication app(argc, argv);


	// 标签控件
	QLabel *infoLabel = new QLabel;
	QLabel *openLabel = new QLabel;
	QLineEdit *cmdLineEdit = new QLineEdit;
	QPushButton *commitButton = new QPushButton;
	QPushButton *cancelButton = new QPushButton;
	QPushButton * browserButton = new QPushButton;

	infoLabel->setText("info");
	openLabel->setText("open");
	commitButton->setText("commit");
	cancelButton->setText("cancel");
	browserButton->setText("browser");

	QHBoxLayout *cmdLayout = new QHBoxLayout;
	cmdLayout->addWidget(openLabel);
	cmdLayout->addWidget(cmdLineEdit);

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(openLabel);
	buttonLayout->addWidget(cancelButton);
	buttonLayout->addWidget(browserButton);

	QVBoxLayout *mainLayout= new QVBoxLayout;
	mainLayout->addWidget(infoLabel);
	mainLayout->addLayout(cmdLayout);
	mainLayout->addLayout(buttonLayout);

	QWidget w;
	w.setLayout(mainLayout);
	w.setWindowTitle("run");
	w.show();

	// app 运行
	return app.exec();
}