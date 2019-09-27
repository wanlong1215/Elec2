#ifndef ELEC_H
#define ELEC_H

#include <QtGui/QMainWindow>
#include "ui_Elec.h"

class Elec : public QMainWindow
{
	Q_OBJECT

public:
	Elec(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Elec();

private slots:
	void onConfig();
	void onQuery();
	void onUser();
	void onQuit();

private:
	Ui::ElecClass ui;
};

#endif // ELEC_H
