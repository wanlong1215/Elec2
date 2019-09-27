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
	int routeID;//������·ID
	int AMSOID;
	string strName;
	string strDescribe;
};

struct CONCENTRATOR 
{
	int ConcentratorID;
	int routeID;//������·ID
	string strName;//����������
	string strDestIP;//Ŀ����
	string strDestPort;//Ŀ��˿�
	string strConnectType;//��������
	string strInstallPlace;//��װ�ص�
	string strAPName;//���������
	string strAPProtocol;//�����Э��
	int TerminalTimer;//�ն˶�ȡ���
	int	ConcentratorTimer;//��������ȡ���
	int HeartTimer;//�������
	string strSimCard;//sim����
	int GPRSReConnectTimer;//Gprs�����ز����-��
	int GPRSSignalStrength;//GPRS�ź�ǿ��
	int SaveTimer;//�洢���
	int wirelessSearchTimer;//����ģ����Ѱ���
	int ConcentratorAddr;//��������ַ
	INT64 ConcentratorCurrentTime;//��������ǰʱ��
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
	string strName;//�ն�����
	string strType;//�ն�����
	int index;//�ն�����
	INT64 installTime;//�ն˰�װʱ��
	int addr;//�ն˵�ַ���
	int preAddr;//����ǰһ���ն˱��
	int nextAddr;//���ں�һ���ն˱��
	int ConcentratorAddr;//��������ַ
	INT64 TerminalCurrentTime;//�ն˵�ǰ��Ϣ
	int RouteState1;//·�ɽڵ�1
	int RouteState2;//·�ɽڵ�2
	int RouteState3;//·�ɽڵ�3
	int RouteState4;//·�ɽڵ�4
	int RouteState5;//·�ɽڵ�5
	int RouteState6;//·�ɽڵ�6
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
	///������Ĳ���������ɹ����ز������������ʧ�ܷ���0
	int InsertCompany(COMPANY p);
	int InsertSubCompany(SUBCOMPANY p, int CompanyID);
	int InsertAMSO(AMSO p, int SubCompanyID);
	int InsertRoute(ROUTE p, int AMSOID);
	int InsertConcentrator(CONCENTRATOR p, int RouteID);
	int InsertLine(LINE p, int ConcentratorID);
	int InsertTerminal(TERMINAL p, int LineID);
	int InsertData(DATA p);
	///�������ɾ���������ɹ�����TURE��ʧ�ܷ���FALSE
	BOOL DelCompany(int companyID);
	BOOL DelSubCompany(int subCompanyID);
	BOOL DelAMSO(int AMSOID);
	BOOL DelRoute(int RouteID);
	BOOL DelConcentrator(int ConcentratorID);
	BOOL DelLine(int lineID);
	BOOL DelTerminal(int TerminalID);
	BOOL DelData(int TerminalAddr);
	///�޸ĸ������ֵ���ɹ�����1��ʧ�ܷ���0
	int ModifyCompany(COMPANY p, int CompanyID);
	int ModifySubCompany(SUBCOMPANY p, int SubCompanyID);
	int ModifyAMSO(AMSO p, int AMSOID);
	int ModifyRoute(ROUTE p, int RouteID);
	int ModifyConcentrator(CONCENTRATOR p, int ConcentratorID);
	int ModifyLine(LINE p, int LineID);
	int ModifyTerminal(TERMINAL p, int TerminalID);
	//int ModifyData(int TerminalID, string strValue);
	///��ѯ�������ֵ���ɹ�����1��ʧ�ܷ���0
	int GetCompany(COMPANY &p, int CompanyID);
	int GetSubCompany(SUBCOMPANY &p, int SubCompanyID);
	int GetAMSO(AMSO &p, int AMSOID);
	int GetRoute(ROUTE &p, int RouteID);
	int GetConcentrator(CONCENTRATOR &p, int ConcentratorID);
	int GetLine(LINE &p, int LineID);
	int GetTerminal(TERMINAL &p, int TerminalID);
	///���ظ������������ɹ�����1��ʧ�ܷ���0
	int GetAllCompanyID(vector<COMPANY> &vCompany);
	int GetAllSubCompanyID(vector<SUBCOMPANY> &vCompany);
	int GetAllAMSOID(vector<AMSO> &vCompany);
	int GetAllRouteID(vector<ROUTE> &vCompany);
	int GetAllConcentratorID(vector<CONCENTRATOR> &vCompany);
	int GetAllLineID(vector<LINE> &vCompany);
	int GetAllTerminalID(vector<TERMINAL> &vCompany);
	//int GetData(int TerminalID);
	///ͨ��������ID�������е�ǰ�������µ������ն�����
	int GetDatabyConcentratorID(vector<DATA> &vData, int ConAddr);
	int GetDatabyTerminalID(vector<DATA> &vData, int ConAddr, int TerminalAddr);


private:
	Connection m_conn;
};
