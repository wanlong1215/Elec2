#ifndef DETAILTREEWIDGETITEM_H
#define DETAILTREEWIDGETITEM_H

#include "BasicTreeWidgetItem.h"

class DetailTreeWidgetItem : public BasicTreeWidgetItem
{
public:
    DetailTreeWidgetItem(TERMINAL o, QTreeWidget *parent);

	// ÿ��չʾʱ���ô�����ϵ��ֵ�������洢�������޸�
	void setDependenceValue(QString cName, QString scName, QString amName, QString roName, QString coName, QString lName);

    bool canAddChild() override;
    QString addMenuText() override;
    QString delMenuText() override;
};

#endif // DETAILTREEWIDGETITEM_H
