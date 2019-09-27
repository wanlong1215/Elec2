#include "Elec.h"

Elec::Elec(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	connect(ui.btnConfig, SIGNAL(clicked(bool)), this, SLOT(onConfig()));
	connect(ui.btnQuery, SIGNAL(clicked(bool)), this, SLOT(onQuery()));
	connect(ui.btnUser, SIGNAL(clicked(bool)), this, SLOT(onUser()));
	connect(ui.btnQuit, SIGNAL(clicked(bool)), this, SLOT(onQuit()));
}

Elec::~Elec()
{

}

void Elec::onConfig()
{
	ui.stackedWidget->setCurrentIndex(0);
}
void Elec::onQuery()
{
	ui.stackedWidget->setCurrentIndex(1);
}
void Elec::onUser()
{
	ui.stackedWidget->setCurrentIndex(2);
}
void Elec::onQuit()
{
	close();
}