#include "CenterWidget.h"
#include "ui_CenterWidget.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>
#include "OrganizationTreeWidgetItem.h"
#include "DetailTreeWidgetItem.h"

CenterWidget::CenterWidget(QWidget *parent) :
QWidget(parent),_selItem(NULL),
ui(new Ui::CenterWidget)
{
	ui->setupUi(this);

	ui->trwOrganization->setHeaderHidden(true);
	ui->trwDetail->setHeaderHidden(true);
	ui->trwDetail->setColumnCount(7);

	ui->trwOrganization->viewport()->installEventFilter(this);
	ui->trwDetail->viewport()->installEventFilter(this);

	_isConnected = _db.DB2Connect("127.0.0.1", "Administrator", "123");

	if (_isConnected) {
		init();
	}
}

CenterWidget::~CenterWidget()
{
	delete ui;
}

void CenterWidget::init()
{
	vector<COMPANY> vc;
	QList<OrganizationTreeWidgetItem *> lstO1;
	if (1 == _db.GetAllCompanyID(vc)) {
		for (int i = 0; i < vc.size(); i++) {
			COMPANY o = vc[i];
			OrganizationTreeWidgetItem *ni = new OrganizationTreeWidgetItem(o, ui->trwOrganization);
			ui->trwOrganization->addTopLevelItem(ni);
			lstO1.append(ni);
		}
	}

	vector<SUBCOMPANY> sc;
	QList<OrganizationTreeWidgetItem *> lstO2;
	if (1 == _db.GetAllSubCompanyID(sc)) {
		for (int i = 0; i < sc.size(); i++) {
			SUBCOMPANY o = sc[i];

			for (int j = 0; j < lstO1.count(); j++) {
				OrganizationTreeWidgetItem *pi = lstO1.at(j);
				if (pi->id() == o.companyID) {
					OrganizationTreeWidgetItem *ni = new OrganizationTreeWidgetItem(o, pi);
					pi->addChild(ni);
					pi->setExpanded(true);
					lstO2.append(ni);
					
					break;
				}
			}
		}
	}

	vector<AMSO> am;
	QList<OrganizationTreeWidgetItem *> lstO3;
	if (1 == _db.GetAllAMSOID(am)) {
		for (int i = 0; i < am.size(); i++) {
			AMSO o = am[i];

			for (int j = 0; j < lstO2.count(); j++) {
				OrganizationTreeWidgetItem *pi = lstO2.at(j);
				if (pi->id() == o.subCompanyID) {
					OrganizationTreeWidgetItem *ni = new OrganizationTreeWidgetItem(o, pi);
					pi->addChild(ni);
					pi->setExpanded(true);
					lstO3.append(ni);

					break;
				}
			}
		}
	}

	vector<ROUTE> ro;
	QList<OrganizationTreeWidgetItem *> lstO4;
	if (1 == _db.GetAllRouteID(ro)) {
		for (int i = 0; i < ro.size(); i++) {
			ROUTE o = ro[i];

			for (int j = 0; j < lstO3.count(); j++) {
				OrganizationTreeWidgetItem *pi = lstO3.at(j);
				if (pi->id() == o.AMSOID) {
					OrganizationTreeWidgetItem *ni = new OrganizationTreeWidgetItem(o, pi);
					pi->addChild(ni);
					pi->setExpanded(true);
					lstO4.append(ni);

					break;
				}
			}
		}
	}

	vector<CONCENTRATOR> co;
	QList<OrganizationTreeWidgetItem *> lstO5;
	if (1 == _db.GetAllConcentratorID(co)) {
		for (int i = 0; i < co.size(); i++) {
			CONCENTRATOR o = co[i];

			for (int j = 0; j < lstO4.count(); j++) {
				OrganizationTreeWidgetItem *pi = lstO4.at(j);
				if (pi->id() == o.routeID) {
					OrganizationTreeWidgetItem *ni = new OrganizationTreeWidgetItem(o, pi);
					pi->addChild(ni);
					pi->setExpanded(true);
					lstO5.append(ni);

					break;
				}
			}
		}
	}

	vector<LINE> li;
	if (1 == _db.GetAllLineID(li)) {
		for (int i = 0; i < li.size(); i++) {
			LINE o = li[i];

			for (int j = 0; j < lstO5.count(); j++) {
				OrganizationTreeWidgetItem *pi = lstO5.at(j);
				if (pi->id() == o.ConcentratorID) {
					OrganizationTreeWidgetItem *ni = new OrganizationTreeWidgetItem(o, pi);
					pi->addChild(ni);
					pi->setExpanded(true);

					break;
				}
			}
		}
	}
}

bool CenterWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui->trwOrganization->viewport()) {
		if (e->type() == QEvent::ContextMenu) {
			QContextMenuEvent *menuEv = dynamic_cast<QContextMenuEvent *>( e );
			QTreeWidgetItem *clickItem = ui->trwOrganization->itemAt(menuEv->pos());
			QMenu menu;
			QAction *addAc = NULL;
			QAction *delAc = NULL;
			QAction *selAc = NULL;
			OrganizationTreeWidgetItem *itemO = NULL;
			if (NULL == clickItem) {
				addAc = menu.addAction(QString::fromLocal8Bit("ÃÌº”π´Àæ"));
			} else {
				itemO = dynamic_cast<OrganizationTreeWidgetItem *>(clickItem);
				if (NULL != itemO)
				{
					if (itemO->canAddChild()) {
						addAc = menu.addAction(QString("%1%2").arg(QString::fromLocal8Bit("ÃÌº”")).arg(itemO->addMenuText()));
					}

					delAc = menu.addAction(QString("%1%2").arg(QString::fromLocal8Bit("…æ≥˝")).arg(itemO->delMenuText()));
				}
			}

			selAc = menu.exec( QCursor::pos() );
			if (NULL != selAc && addAc == selAc) {
				OrganizationTreeWidgetItem *item = NULL;
				if (NULL == clickItem) {
					COMPANY o;
					if (0 != insertDefaultCompany(o)) {
						item = new OrganizationTreeWidgetItem(o, ui->trwOrganization);
						ui->trwOrganization->addTopLevelItem(item);
					}
				} else if (NULL != itemO) {
					switch (itemO->_level) {
						case 1: {
							SUBCOMPANY o;
							if (0 != insertDefaultSubCompany(itemO->id(), o)) {
								item = new OrganizationTreeWidgetItem(o, itemO);
							}
								} break;
						case 2: {
							AMSO o;
							if (0 != insertDefaultAnso(itemO->id(), o)) {
								item = new OrganizationTreeWidgetItem(o, itemO);
							}
								} break;
						case 3: {
							ROUTE o;
							if (0 != insertDefaultRoute(itemO->id(), o)) {
								item = new OrganizationTreeWidgetItem(o, itemO);
							}
								} break;
						case 4: {
							CONCENTRATOR o;
							if (0 != insertDefaultConcentrator(itemO->id(), o)) {
								item = new OrganizationTreeWidgetItem(o, itemO);
							}
								} break;
						case 5: {
							LINE o;
							if (0 != insertDefaultLine(itemO->id(), o)) {
								item = new OrganizationTreeWidgetItem(o, itemO);
							}
								} break;
						default:
							break;
					}
					if (NULL != item) {
						itemO->addChild(item);
						itemO->setExpanded(true);
					}
				}

				if (NULL != item) {
					ui->trwOrganization->clearSelection();
					_selItem = item;
					_selItem->setSelected(true);
					showProperty();
				}
			} else if (NULL != selAc && delAc == selAc && NULL != itemO) {
				if (NULL == itemO->parent()) {
					if (_db.DelCompany(itemO->id())) {
						ui->trwOrganization->takeTopLevelItem(ui->trwOrganization->indexOfTopLevelItem(itemO));
					}
				} else {
					switch (itemO->_level) {
						case 2: {
							if (_db.DelSubCompany(itemO->id())) {
								itemO->parent()->removeChild(itemO);
							}
								}
								break;
						case 3: {
							if (_db.DelAMSO(itemO->id())) {
								itemO->parent()->removeChild(itemO);
							}
								}
								break;
						case 4: {
							if (_db.DelRoute(itemO->id())) {
								itemO->parent()->removeChild(itemO);
							}
								}
								break;
						case 5: {
							if (_db.DelConcentrator(itemO->id())) {
								itemO->parent()->removeChild(itemO);
							}
								}
								break;
						case 6: {
							if (_db.DelLine(itemO->id())) {
								itemO->parent()->removeChild(itemO);
							}
								}
								break;
						default:
							break;
					}

					ui->trwOrganization->clearSelection();
					_selItem = NULL;
					showProperty();
				}
			}
		} else if (e->type() == QEvent::MouseButtonPress) {
			QMouseEvent *mouseEv = dynamic_cast<QMouseEvent *>( e );
			QTreeWidgetItem *clickItem = ui->trwOrganization->itemAt(mouseEv->pos());
			if (NULL != clickItem) {
				_selItem = dynamic_cast<OrganizationTreeWidgetItem *>(clickItem);
				showProperty();
			}
		}
	} else if (obj == ui->trwDetail->viewport()) {
		if (e->type() == QEvent::ContextMenu) {
			QList<QTreeWidgetItem*> selItems = ui->trwOrganization->selectedItems();
			if (1 == selItems.count()) {
				OrganizationTreeWidgetItem *itemO = dynamic_cast<OrganizationTreeWidgetItem *>(selItems.first());
				if (NULL != itemO && itemO->_level == 6) {
					QContextMenuEvent *menuEv = dynamic_cast<QContextMenuEvent *>( e );
					QTreeWidgetItem *clickItem = ui->trwDetail->itemAt(menuEv->pos());
					QMenu menu;
					QAction *addAc = NULL;
					QAction *delAc = NULL;
					QAction *selAc = NULL;
					DetailTreeWidgetItem *itemD = NULL;
					if (NULL == clickItem) {
						addAc = menu.addAction(QString::fromLocal8Bit("ÃÌº”÷’∂À"));
					} else {
						itemD = dynamic_cast<DetailTreeWidgetItem *>(clickItem);
						if (NULL != itemD)
						{
							delAc = menu.addAction(QString::fromLocal8Bit("…æ≥˝÷’∂À"));
						}
					}

					selAc = menu.exec( QCursor::pos() );
					if (NULL != selAc && addAc == selAc) {
						if (NULL == clickItem) {
							TERMINAL o;
							if (0 != insertDefaultTerminal(itemO->id(), o)) {
								DetailTreeWidgetItem *item = new DetailTreeWidgetItem(o, ui->trwDetail);
								setDependenceValue(item);
								ui->trwDetail->addTopLevelItem(item);

								ui->trwDetail->clearSelection();
								_selItem = item;
								_selItem->setSelected(true);
								showProperty();
							}
						}
					} else if (NULL != selAc && delAc == selAc && NULL != itemD) {
						if (_db.DelTerminal(itemD->id())) {
							ui->trwDetail->takeTopLevelItem(ui->trwDetail->indexOfTopLevelItem(itemD));

							ui->trwDetail->clearSelection();
							_selItem = NULL;
							showProperty();
						}
					}
				}
			}
		}
	}

	return QWidget::eventFilter(obj, e);
}

void CenterWidget::showProperty()
{
	disconnect(ui->tawProperty, SIGNAL(cellChanged(int,int)), this, SLOT(onPropertyCellChanged(int,int)));
	if (NULL == _selItem) {
		while (ui->tawProperty->rowCount() != 0) {
			ui->tawProperty->removeRow(0);
		}
		return;
	}

	QList<KVPara> paras = _selItem->paras();

	ui->tawProperty->clearContents();
	ui->tawProperty->setColumnCount(2);
	ui->tawProperty->setRowCount(paras.count());
	ui->tawProperty->setColumnWidth(0, ui->tawProperty->width()/2-50);
	ui->tawProperty->setColumnWidth(1, ui->tawProperty->width()/2);
	ui->tawProperty->setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromLocal8Bit(" Ù–‘")));
	ui->tawProperty->setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromLocal8Bit("÷µ")));

	for (int i = 0; i < paras.count(); i++) {
		KVPara para = paras.at(i);
		QTableWidgetItem *keyItem = new QTableWidgetItem(para.key);
		keyItem->setFlags(keyItem->flags() & (~Qt::ItemIsEditable));
		ui->tawProperty->setItem(i, 0, keyItem);
		ui->tawProperty->setItem(i, 1, new QTableWidgetItem(para.value));
	}
	connect(ui->tawProperty, SIGNAL(cellChanged(int,int)), this, SLOT(onPropertyCellChanged(int,int)));
}

void CenterWidget::onPropertyCellChanged(int r, int c)
{
	if (NULL == _selItem) {
		return;
	}

	QTableWidgetItem *itemPV = ui->tawProperty->item(r, c);
	QTableWidgetItem *itemPK = ui->tawProperty->item(r, 0);
	if (NULL != itemPV && NULL != itemPK) {
		_selItem->updatePara(itemPK->text(), itemPV->text());

		switch (_selItem->_level) {
			case 1: 
				_db.ModifyCompany(_selItem->_o1, _selItem->id());
				break;
			case 2: 
				_db.ModifySubCompany(_selItem->_o2, _selItem->id());
				break;
			case 3: 
				_db.ModifyAMSO(_selItem->_o3, _selItem->id());
				break;
			case 4: 
				_db.ModifyRoute(_selItem->_o4, _selItem->id());
				break;
			case 5: 
				_db.ModifyConcentrator(_selItem->_o5, _selItem->id());
				break;
			case 6: 
				_db.ModifyLine(_selItem->_o6, _selItem->id());
				break;
			case 7: 
				_db.ModifyTerminal(_selItem->_o7, _selItem->id());
				break;
			default:
				break;
		}
	}
}

int CenterWidget::insertDefaultCompany(COMPANY &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName = "π´Àæ";
	o.strDescribe = "";

	int res = _db.InsertCompany(o);
	o.companyID = res;

	return res;
}

int CenterWidget::insertDefaultSubCompany(int id, SUBCOMPANY &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName = "√ó√ì¬π¬´√ã¬æ";
	o.strDescribe = "";

	int res = _db.InsertSubCompany(o, id);
	o.subCompanyID = res;
	o.companyID = id;

	return res;
}
int CenterWidget::insertDefaultAnso(int id, AMSO &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName = "¬π¬©¬µ√ß√ã√π";
	o.strDescribe = "";

	int res = _db.InsertAMSO(o, id);
	o.AMSOID = res;
	o.subCompanyID = id;

	return res;
}
int CenterWidget::insertDefaultRoute(int id, ROUTE &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName = "√è√ü√Ç¬∑";
	o.strDescribe = "";

	int res = _db.InsertRoute(o, id);
	o.routeID = res;
	o.AMSOID = id;

	return res;
}
int CenterWidget::insertDefaultConcentrator(int id, CONCENTRATOR &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName = "¬º¬Ø√ñ√ê√Ü√∑";
	o.strDestIP = "";
	o.strDestPort = "";
	o.strConnectType = "";
	o.strInstallPlace = "";
	o.strAPName = "";
	o.strAPProtocol = "";
	o.TerminalTimer = 0;
	o.ConcentratorTimer = 0;
	o.HeartTimer = 0;
	o.strSimCard = "";

	int res = _db.InsertConcentrator(o, id);
	o.ConcentratorID = res;
	o.routeID = id;

	return res;
}
int CenterWidget::insertDefaultLine(int id, LINE &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName ="√è√ü¬∂√é";
	o.strType = "";
	o.workerID = 0;

	int res = _db.InsertLine(o, id);
	o.lineID = res;
	o.ConcentratorID = id;

	return res;
}
int CenterWidget::insertDefaultTerminal(int id, TERMINAL &o)
{
	if (!_isConnected) {
		return 0;
	}

	o.strName = "÷’∂À";
	o.strType = "";
	o.index = 0;
	o.installTime = 0;

	int res = _db.InsertTerminal(o, id);
	o.TerminalID = res;
	o.lineID = id;

	return res;
}

void CenterWidget::setDependenceValue(DetailTreeWidgetItem *item)
{
	if (NULL == item) {
		return;
	}
	QList<QTreeWidgetItem*> selItems = ui->trwOrganization->selectedItems();
	if (1 == selItems.count()) {
		OrganizationTreeWidgetItem *oi6 = dynamic_cast<OrganizationTreeWidgetItem *>(selItems.first());
		if (NULL == oi6 || 6 != oi6->_level) {
			return;
		}

		OrganizationTreeWidgetItem *oi5 = dynamic_cast<OrganizationTreeWidgetItem *>(oi6->parent());
		if (NULL == oi5 || 5 != oi5->_level) {
			return;
		}

		OrganizationTreeWidgetItem *oi4 = dynamic_cast<OrganizationTreeWidgetItem *>(oi5->parent());
		if (NULL == oi4 || 4 != oi4->_level) {
			return;
		}

		OrganizationTreeWidgetItem *oi3 = dynamic_cast<OrganizationTreeWidgetItem *>(oi4->parent());
		if (NULL == oi3 || 3 != oi3->_level) {
			return;
		}

		OrganizationTreeWidgetItem *oi2 = dynamic_cast<OrganizationTreeWidgetItem *>(oi3->parent());
		if (NULL == oi2 || 2 != oi2->_level) {
			return;
		}

		OrganizationTreeWidgetItem *oi1 = dynamic_cast<OrganizationTreeWidgetItem *>(oi2->parent());
		if (NULL == oi1 || 1 != oi1->_level) {
			return;
		}
		
		item->setDependenceValue(QString::fromLocal8Bit(oi1->name().c_str()), QString::fromLocal8Bit(oi2->name().c_str()), QString::fromLocal8Bit(oi3->name().c_str()), QString::fromLocal8Bit(oi4->name().c_str()), QString::fromLocal8Bit(oi5->name().c_str()), QString::fromLocal8Bit(oi6->name().c_str()));
	}
}