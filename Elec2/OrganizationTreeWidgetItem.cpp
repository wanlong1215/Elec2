#include "OrganizationTreeWidgetItem.h"

OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(COMPANY o, QTreeWidget *parent) : BasicTreeWidgetItem(parent)
{
	_o1 = o;
	setText(0, QString::fromLocal8Bit(_o1.strName.c_str()));

	addPara(QString::fromLocal8Bit("名称"), QString::fromLocal8Bit(_o1.strName.c_str()));
	addPara(QString::fromLocal8Bit("备注"), QString::fromLocal8Bit(_o1.strDescribe.c_str()));
}

OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(SUBCOMPANY o, QTreeWidgetItem *parent) : BasicTreeWidgetItem(2, parent)
{
	_o2 = o;
	setText(0, QString::fromLocal8Bit(_o2.strName.c_str()));

	addPara(QString::fromLocal8Bit("名称"), QString::fromLocal8Bit(_o2.strName.c_str()));
	addPara(QString::fromLocal8Bit("备注"), QString::fromLocal8Bit(_o2.strDescribe.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(AMSO o, QTreeWidgetItem *parent): BasicTreeWidgetItem(3, parent)
{
	_o3 = o;
	setText(0, QString::fromLocal8Bit(_o3.strName.c_str()));

	addPara(QString::fromLocal8Bit("名称"), QString::fromLocal8Bit(_o3.strName.c_str()));
	addPara(QString::fromLocal8Bit("备注"), QString::fromLocal8Bit(_o3.strDescribe.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(ROUTE o, QTreeWidgetItem *parent): BasicTreeWidgetItem(4, parent)
{
	_o4 = o;
	setText(0, QString::fromLocal8Bit(_o4.strName.c_str()));

	addPara(QString::fromLocal8Bit("名称"), QString::fromLocal8Bit(_o4.strName.c_str()));
	addPara(QString::fromLocal8Bit("备注"), QString::fromLocal8Bit(_o4.strDescribe.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(CONCENTRATOR o, QTreeWidgetItem *parent): BasicTreeWidgetItem(5, parent)
{
	_o5 = o;
	setText(0, QString::fromLocal8Bit(_o5.strName.c_str()));

	addPara(QString::fromLocal8Bit("名称"), QString::fromLocal8Bit(_o5.strName.c_str()));
	addPara(QString::fromLocal8Bit("目标域"), QString::fromLocal8Bit(_o5.strDestIP.c_str()));
	addPara(QString::fromLocal8Bit("目标端口"), QString::fromLocal8Bit(_o5.strDestPort.c_str()));
	addPara(QString::fromLocal8Bit("连接类型"), QString::fromLocal8Bit(_o5.strConnectType.c_str()));
	addPara(QString::fromLocal8Bit("安装地点"), QString::fromLocal8Bit(_o5.strInstallPlace.c_str()));
	addPara(QString::fromLocal8Bit("接入点名称"), QString::fromLocal8Bit(_o5.strAPName.c_str()));
	addPara(QString::fromLocal8Bit("接入点协议"), QString::fromLocal8Bit(_o5.strAPProtocol.c_str()));
	addPara(QString::fromLocal8Bit("终端读取间隔"), QString::number(_o5.TerminalTimer));
	addPara(QString::fromLocal8Bit("集中器读取间隔"), QString::number(_o5.ConcentratorTimer));
	addPara(QString::fromLocal8Bit("心跳间隔"), QString::number(_o5.HeartTimer));
	addPara(QString::fromLocal8Bit("sim卡号"), QString::fromLocal8Bit(_o5.strSimCard.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(LINE o, QTreeWidgetItem *parent): BasicTreeWidgetItem(6, parent)
{
	_o6 = o;
	setText(0, QString::fromLocal8Bit(_o6.strName.c_str()));

	addPara(QString::fromLocal8Bit("名称"), QString::fromLocal8Bit(_o6.strName.c_str()));
	addPara(QString::fromLocal8Bit("类型"), QString::fromLocal8Bit(_o6.strType.c_str()));
	addPara(QString::fromLocal8Bit("接警人员ID"), QString::number(_o6.workerID));
}

bool OrganizationTreeWidgetItem::canAddChild()
{
    return _level < 6;
}

QString OrganizationTreeWidgetItem::delMenuText()
{
    QStringList lst;
    lst << QString::fromLocal8Bit("公司") << QString::fromLocal8Bit("分公司") << QString::fromLocal8Bit("供电所") << QString::fromLocal8Bit("线路") << QString::fromLocal8Bit("集中器") << QString::fromLocal8Bit("线段");

    int l = _level -1;
    if (l >= 0 && l < lst.count())
    {
        return lst.at(l);
    }
    else
    {
        return "";
    }
}

QString OrganizationTreeWidgetItem::addMenuText()
{
	QStringList lst;
	lst << QString::fromLocal8Bit("公司") << QString::fromLocal8Bit("分公司") << QString::fromLocal8Bit("供电所") << QString::fromLocal8Bit("线路") << QString::fromLocal8Bit("集中器") << QString::fromLocal8Bit("线段");

    if (_level > 0 && _level < lst.count())
    {
        return lst.at(_level);
    }
    else
    {
        return "";
    }
}
