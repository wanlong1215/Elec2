#ifndef BASICTREEWIDGETITEM_H
#define BASICTREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include "DATAOperate.h"

struct KVPara
{
    QString key;
    QString value;
};

class BasicTreeWidgetItem : public QTreeWidgetItem
{
public:
    BasicTreeWidgetItem(QTreeWidget *parent);
	BasicTreeWidgetItem(int level, QTreeWidgetItem *parent);

	int id();
	string name();

    void addPara(const QString &k, const QString &v);
    void updatePara(const QString &k, const QString &v);

    const QList<KVPara> &paras();

    virtual bool canAddChild() = 0;
    virtual QString addMenuText() = 0;
    virtual QString delMenuText() = 0;

public:
    int _level;
    QList<KVPara> _data; // map默认排序，这里添加参数的顺序按照接口的顺序添加

	COMPANY _o1;
	SUBCOMPANY _o2;
	AMSO _o3;
	ROUTE _o4;
	CONCENTRATOR _o5;
	LINE _o6;
	TERMINAL _o7; 
};

#endif // BASICTREEWIDGETITEM_H
