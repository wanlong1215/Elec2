#include "DetailTreeWidgetItem.h"

DetailTreeWidgetItem::DetailTreeWidgetItem(TERMINAL o, QTreeWidget *parent) : BasicTreeWidgetItem(parent)
{
	_o7 = o;
	setText(6, QString::fromStdString(_o7.strName));

	addPara(QString::fromLocal8Bit("名称"), QString::fromStdString(_o7.strName));
	addPara(QString::fromLocal8Bit("类型"), QString::fromStdString(_o7.strType));
	addPara(QString::fromLocal8Bit("索引"), QString::number(_o7.index));
	addPara(QString::fromLocal8Bit("安装时间"), QString::number(_o7.installTime));
}

void DetailTreeWidgetItem::setDependenceValue(QString cName, QString scName, QString amName, QString roName, QString coName, QString lName)
{
	setText(0, cName);
	setText(1, scName);
	setText(2, amName);
	setText(3, roName);
	setText(4, coName);
	setText(5, lName);
}

bool DetailTreeWidgetItem::canAddChild()
{
    return false;
}

QString DetailTreeWidgetItem::delMenuText()
{
    return QString::fromLocal8Bit("终端");
}

QString DetailTreeWidgetItem::addMenuText()
{
    return "";
}
