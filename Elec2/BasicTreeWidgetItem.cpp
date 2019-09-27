#include "BasicTreeWidgetItem.h"
#include <QDebug>

BasicTreeWidgetItem::BasicTreeWidgetItem(QTreeWidget *parent)
    :QTreeWidgetItem(parent)
{
    _level = 1;
}

BasicTreeWidgetItem::BasicTreeWidgetItem( int level, QTreeWidgetItem *parent)
    :QTreeWidgetItem(parent)
{
    _level = level;
}

int BasicTreeWidgetItem::id()
{
	switch (_level) {
		case 1:
			return _o1.companyID;
		case 2:
			return _o2.subCompanyID;
		case 3:
			return _o3.AMSOID;
		case 4:
			return _o4.routeID;
		case 5:
			return _o5.ConcentratorID;
		case 6:
			return _o6.lineID;
		case 7:
			return _o7.TerminalID;
		default:
			break;
	}

	return 0;
}

string BasicTreeWidgetItem::name()
{
	switch (_level) {
		case 1:
			return _o1.strName;
		case 2:
			return _o2.strName;
		case 3:
			return _o3.strName;
		case 4:
			return _o4.strName;
		case 5:
			return _o5.strName;
		case 6:
			return _o6.strName;
		case 7:
			return _o7.strName;
		default:
			break;
	}

	return "";
}

void BasicTreeWidgetItem::addPara(const QString &k, const QString &v)
{
    KVPara para;
    para.key = k;
    para.value = v;

    _data.append(para);
}

void BasicTreeWidgetItem::updatePara(const QString &k, const QString &v)
{
    for (int i = 0; i < _data.count(); i++) {
        KVPara para = _data.at(i);
        if (para.key == k) {
            KVPara np;
            np.key = k;
            np.value = v;

            _data.replace(i, np);

			switch (_level)
			{
			case 1:
				if (k == QString::fromLocal8Bit("名称")) {
					_o1.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("备注")) {
					_o1.strDescribe = QString(v.toLocal8Bit()).toStdString();
				}
				break;
			case 2:
				if (k == QString::fromLocal8Bit("名称")) {
					_o2.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("备注")) {
					_o2.strDescribe = QString(v.toLocal8Bit()).toStdString();
				}
				break;
			case 3:
				if (k == QString::fromLocal8Bit("名称")) {
					_o3.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("备注")) {
					_o3.strDescribe = QString(v.toLocal8Bit()).toStdString();
				}
				break;
			case 4:
				if (k == QString::fromLocal8Bit("名称")) {
					_o4.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("备注")) {
					_o4.strDescribe = QString(v.toLocal8Bit()).toStdString();
				}
				break;
			case 5:
				if (k == QString::fromLocal8Bit("名称")) {
					_o5.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("目标域")) {
					_o5.strDestIP = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("目标端口")) {
					_o5.strDestPort = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("连接类型")) {
					_o5.strConnectType = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("安装地点")) {
					_o5.strInstallPlace = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("接入点名称")) {
					_o5.strAPName = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("接入点协议")) {
					_o5.strAPProtocol = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("终端读取间隔")) {
					_o5.TerminalTimer = v.toInt();
				}else if (k == QString::fromLocal8Bit("集中器读取间隔")) {
					_o5.ConcentratorTimer = v.toInt();
				}else if (k == QString::fromLocal8Bit("心跳间隔")) {
					_o5.HeartTimer = v.toInt();
				}else if (k == QString::fromLocal8Bit("sim卡号")) {
					_o5.strSimCard = QString(v.toLocal8Bit()).toStdString();
				}
				break;
			case 6:
				if (k == QString::fromLocal8Bit("名称")) {
					_o6.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("类型")) {
					_o6.strType = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("接警人员ID")) {
					_o6.workerID = v.toInt();
				}
				break;
			case 7:
				if (k == QString::fromLocal8Bit("名称")) {
					_o7.strName = QString(v.toLocal8Bit()).toStdString();
				} else if (k == QString::fromLocal8Bit("类型")) {
					_o7.strType = QString(v.toLocal8Bit()).toStdString();
				}else if (k == QString::fromLocal8Bit("索引")) {
					_o7.index = v.toInt();
				}else if (k == QString::fromLocal8Bit("安装时间")) {
					_o7.installTime = v.toInt();
				}
				break;
			default:
				break;
			}

			if (QString::fromLocal8Bit("名称") == k) {
                this->setText(0, v);
            }
            break;
        }
    }
}

const QList<KVPara> &BasicTreeWidgetItem::paras()
{
    return _data;
}
