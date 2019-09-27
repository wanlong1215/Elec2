#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include "DetailTreeWidgetItem.h"
#include "DATAOperate.h"

namespace Ui {
	class CenterWidget;
}

class CenterWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CenterWidget(QWidget *parent = 0);
	~CenterWidget();

	void init();

protected:
	bool eventFilter(QObject *obj, QEvent *e);

	void showProperty();

	int insertDefaultCompany(COMPANY &o);
	int insertDefaultSubCompany(int id, SUBCOMPANY &o);
	int insertDefaultAnso(int id, AMSO &o);
	int insertDefaultRoute(int id, ROUTE &o);
	int insertDefaultConcentrator(int id, CONCENTRATOR &o);
	int insertDefaultLine(int id, LINE &o);
	int insertDefaultTerminal(int id, TERMINAL &o);

	void setDependenceValue(DetailTreeWidgetItem *item);

protected slots:
	void onPropertyCellChanged(int r, int c);

private:
	Ui::CenterWidget *ui;

	CDATAOperate _db;
	bool _isConnected;

	BasicTreeWidgetItem *_selItem;
};

#endif // CENTERWIDGET_H
