#ifndef ORGANIZATIONTREEWIDGETITEM_H
#define ORGANIZATIONTREEWIDGETITEM_H

#include "BasicTreeWidgetItem.h"

class OrganizationTreeWidgetItem : public BasicTreeWidgetItem
{
public:
    OrganizationTreeWidgetItem(COMPANY o, QTreeWidget *parent);
	OrganizationTreeWidgetItem(SUBCOMPANY o, QTreeWidgetItem *parent);
	OrganizationTreeWidgetItem(AMSO o, QTreeWidgetItem *parent);
	OrganizationTreeWidgetItem(ROUTE o, QTreeWidgetItem *parent);
	OrganizationTreeWidgetItem(CONCENTRATOR o, QTreeWidgetItem *parent);
	OrganizationTreeWidgetItem(LINE o, QTreeWidgetItem *parent);

    bool canAddChild() override;
    QString addMenuText() override;
    QString delMenuText() override;
};

#endif // ORGANIZATIONTREEWIDGETITEM_H
