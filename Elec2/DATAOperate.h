#pragma once
#include "dbtool_ado.h"
using namespace ADO_WRAPPER;
#include <vector>
using namespace std;


struct COMPANY 
{
	int companyID;
	string strName;
	string strDescribe;
};

struct SUBCOMPANY
{
	int subCompanyID;
	int companyID;
	string strName;
	string strDescribe;
};

struct AMSO 
{
	int AMSOID;
	int subCompanyID;
	string strName;
	string strDescribe;
};

struct ROUTE
{
	int routeID;//所属线路ID
	int AMSOID;
	string strName;
	string strDescribe;
};

struct CONCENTRATOR 
{
	int ConcentratorID;
	int routeID;//所属线路ID
	string strName;//集中器名称
	string strDestIP;//目标域
	string strDestPort;//目标端口
	string strConnectType;//连接类型
	string strInstallPlace;//安装地点
	string strAPName;//接入点名称
	string strAPProtocol;//接入点协议
	int TerminalTimer;//终端读取间隔
	int	ConcentratorTimer;//集中器读取间隔
	int HeartTimer;//心跳间隔
	string strSimCard;//sim卡号
	int GPRSReConnectTimer;//Gprs掉线重拨间隔-分
	int GPRSSignalStrength;//GPRS信号强度
	int SaveTimer;//存储间隔
	int wirelessSearchTimer;//无线模组轮寻间隔
	int ConcentratorAddr;//集中器地址
	INT64 ConcentratorCurrentTime;//集中器当前时间
};

struct LINE 
{
	int lineID;
	int ConcentratorID;
	string strName;
	string strType;
	int	workerID;
};

struct TERMINAL 
{
	int TerminalID;
	int lineID;
	string strName;//终端名称
	string strType;//终端类型
	int index;//终端索引
	INT64 installTime;//终端安装时间
	int addr;//终端地址编号
	int preAddr;//相邻前一个终端编号
	int nextAddr;//相邻后一个终端编号
	int ConcentratorAddr;//集中器地址
	INT64 TerminalCurrentTime;//终端当前信息
	int RouteState1;//路由节点1
	int RouteState2;//路由节点2
	int RouteState3;//路由节点3
	int RouteState4;//路由节点4
	int RouteState5;//路由节点5
	int RouteState6;//路由节点6
};

struct DATA 
{
	int DataID;
	int TerminalAddr;
	int ConcentratorAddr;
	INT64 CollectTime;
	int relaycnt;
	int relayPosition;
	int GetherUnitAddr;
	int vValue;
	int vAngValue;
	int iValue;
	int iAngValue;
	int intRev1;
	int intRev2;
	int intRev3;
	int intRev4;
	int intRev5;
	int intRev6;
};

class CDATAOperate
{
public:
	CDATAOperate();
	~CDATAOperate(void);
	BOOL DB2Connect(string strIP, string strUsr, string strCode);
	///各个表的插入操作，成功返回插入项的索引，失败返回0
	int InsertCompany(COMPANY p);
	int InsertSubCompany(SUBCOMPANY p, int CompanyID);
	int InsertAMSO(AMSO p, int SubCompanyID);
	int InsertRoute(ROUTE p, int AMSOID);
	int InsertConcentrator(CONCENTRATOR p, int RouteID);
	int InsertLine(LINE p, int ConcentratorID);
	int InsertTerminal(TERMINAL p, int LineID);
	int InsertData(DATA p);
	///各个表的删除操作，成功返回TURE，失败返回FALSE
	BOOL DelCompany(int companyID);
	BOOL DelSubCompany(int subCompanyID);
	BOOL DelAMSO(int AMSOID);
	BOOL DelRoute(int RouteID);
	BOOL DelConcentrator(int ConcentratorID);
	BOOL DelLine(int lineID);
	BOOL DelTerminal(int TerminalID);
	BOOL DelData(int TerminalAddr);
	///修改各个表的值，成功返回1，失败返回0
	int ModifyCompany(COMPANY p, int CompanyID);
	int ModifySubCompany(SUBCOMPANY p, int SubCompanyID);
	int ModifyAMSO(AMSO p, int AMSOID);
	int ModifyRoute(ROUTE p, int RouteID);
	int ModifyConcentrator(CONCENTRATOR p, int ConcentratorID);
	int ModifyLine(LINE p, int LineID);
	int ModifyTerminal(TERMINAL p, int TerminalID);
	//int ModifyData(int TerminalID, string strValue);
	///查询各个表的值，成功返回1，失败返回0
	int GetCompany(COMPANY &p, int CompanyID);
	int GetSubCompany(SUBCOMPANY &p, int SubCompanyID);
	int GetAMSO(AMSO &p, int AMSOID);
	int GetRoute(ROUTE &p, int RouteID);
	int GetConcentrator(CONCENTRATOR &p, int ConcentratorID);
	int GetLine(LINE &p, int LineID);
	int GetTerminal(TERMINAL &p, int TerminalID);
	///返回各个表的所有项，成功返回1，失败返回0
	int GetAllCompanyID(vector<COMPANY> &vCompany);
	int GetAllSubCompanyID(vector<SUBCOMPANY> &vCompany);
	int GetAllAMSOID(vector<AMSO> &vCompany);
	int GetAllRouteID(vector<ROUTE> &vCompany);
	int GetAllConcentratorID(vector<CONCENTRATOR> &vCompany);
	int GetAllLineID(vector<LINE> &vCompany);
	int GetAllTerminalID(vector<TERMINAL> &vCompany);
	//int GetData(int TerminalID);
	///通过集中器ID返回所有当前集中器下的所有终端数据
	int GetDatabyConcentratorID(vector<DATA> &vData, int ConAddr);
	int GetDatabyTerminalID(vector<DATA> &vData, int ConAddr, int TerminalAddr);


private:
	Connection m_conn;
};
