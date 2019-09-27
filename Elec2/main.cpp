#include "Elec.h"
#include <QtGui/QApplication>
#include <ObjBase.h>
#include "DATAOperate.h"
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>
#include "FarsiLoginDlg.h"

int main(int argc, char *argv[])
{
	CoInitialize(NULL);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	QApplication a(argc, argv);

	/*
	FarsiLoginDlg dlg;
	dlg.showMaximized();
	if (QDialog::Accepted == dlg.exec()) {
		Elec *w = new Elec();
		w->showMaximized();
	} else {
		return 0;
	}*/

	Elec w;
	w.show();

	return a.exec();
}
