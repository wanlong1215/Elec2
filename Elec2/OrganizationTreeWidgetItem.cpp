#include "OrganizationTreeWidgetItem.h"

OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(COMPANY o, QTreeWidget *parent) : BasicTreeWidgetItem(parent)
{
	_o1 = o;
	setText(0, QString::fromLocal8Bit(_o1.strName.c_str()));

	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o1.strName.c_str()));
	addPara(QString::fromLocal8Bit("��ע"), QString::fromLocal8Bit(_o1.strDescribe.c_str()));
}

OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(SUBCOMPANY o, QTreeWidgetItem *parent) : BasicTreeWidgetItem(2, parent)
{
	_o2 = o;
	setText(0, QString::fromLocal8Bit(_o2.strName.c_str()));

	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o2.strName.c_str()));
	addPara(QString::fromLocal8Bit("��ע"), QString::fromLocal8Bit(_o2.strDescribe.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(AMSO o, QTreeWidgetItem *parent): BasicTreeWidgetItem(3, parent)
{
	_o3 = o;
	setText(0, QString::fromLocal8Bit(_o3.strName.c_str()));

	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o3.strName.c_str()));
	addPara(QString::fromLocal8Bit("��ע"), QString::fromLocal8Bit(_o3.strDescribe.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(ROUTE o, QTreeWidgetItem *parent): BasicTreeWidgetItem(4, parent)
{
	_o4 = o;
	setText(0, QString::fromLocal8Bit(_o4.strName.c_str()));

	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o4.strName.c_str()));
	addPara(QString::fromLocal8Bit("��ע"), QString::fromLocal8Bit(_o4.strDescribe.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(CONCENTRATOR o, QTreeWidgetItem *parent): BasicTreeWidgetItem(5, parent)
{
	_o5 = o;
	setText(0, QString::fromLocal8Bit(_o5.strName.c_str()));

	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o5.strName.c_str()));
	addPara(QString::fromLocal8Bit("Ŀ����"), QString::fromLocal8Bit(_o5.strDestIP.c_str()));
	addPara(QString::fromLocal8Bit("Ŀ��˿�"), QString::fromLocal8Bit(_o5.strDestPort.c_str()));
	addPara(QString::fromLocal8Bit("��������"), QString::fromLocal8Bit(_o5.strConnectType.c_str()));
	addPara(QString::fromLocal8Bit("��װ�ص�"), QString::fromLocal8Bit(_o5.strInstallPlace.c_str()));
	addPara(QString::fromLocal8Bit("���������"), QString::fromLocal8Bit(_o5.strAPName.c_str()));
	addPara(QString::fromLocal8Bit("�����Э��"), QString::fromLocal8Bit(_o5.strAPProtocol.c_str()));
	addPara(QString::fromLocal8Bit("�ն˶�ȡ���"), QString::number(_o5.TerminalTimer));
	addPara(QString::fromLocal8Bit("��������ȡ���"), QString::number(_o5.ConcentratorTimer));
	addPara(QString::fromLocal8Bit("�������"), QString::number(_o5.HeartTimer));
	addPara(QString::fromLocal8Bit("sim����"), QString::fromLocal8Bit(_o5.strSimCard.c_str()));
}
OrganizationTreeWidgetItem::OrganizationTreeWidgetItem(LINE o, QTreeWidgetItem *parent): BasicTreeWidgetItem(6, parent)
{
	_o6 = o;
	setText(0, QString::fromLocal8Bit(_o6.strName.c_str()));

	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o6.strName.c_str()));
	addPara(QString::fromLocal8Bit("����"), QString::fromLocal8Bit(_o6.strType.c_str()));
	addPara(QString::fromLocal8Bit("�Ӿ���ԱID"), QString::number(_o6.workerID));
}

bool OrganizationTreeWidgetItem::canAddChild()
{
    return _level < 6;
}

QString OrganizationTreeWidgetItem::delMenuText()
{
    QStringList lst;
    lst << QString::fromLocal8Bit("��˾") << QString::fromLocal8Bit("�ֹ�˾") << QString::fromLocal8Bit("������") << QString::fromLocal8Bit("��·") << QString::fromLocal8Bit("������") << QString::fromLocal8Bit("�߶�");

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
	lst << QString::fromLocal8Bit("��˾") << QString::fromLocal8Bit("�ֹ�˾") << QString::fromLocal8Bit("������") << QString::fromLocal8Bit("��·") << QString::fromLocal8Bit("������") << QString::fromLocal8Bit("�߶�");

    if (_level > 0 && _level < lst.count())
    {
        return lst.at(_level);
    }
    else
    {
        return "";
    }
}
