
#include "DATAOperate.h"

CDATAOperate::CDATAOperate(void):m_conn(NULL)
{
}

CDATAOperate::~CDATAOperate(void)
{
}


BOOL CDATAOperate::DB2Connect(string strIP, string strUsr, string strCode)
{
	try
	{
		string strConnectionString = "Provider=IBMDADB2.DB2COPY1;Persist Security Info=False;Data Source=AUTOTEST;Location=";
		strConnectionString += strIP;
		string strName = strUsr;
		string strPwd = strCode;
		m_conn.open( strConnectionString.c_str(), strName.c_str(), strPwd.c_str() );	
	}
	catch (_com_error& e)
	{
		///捕获相关错误信息		
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}

int CDATAOperate::InsertCompany(COMPANY p)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select CompanyID from final table (insert into BR_COMPANY(CName,SVersion) values (?, ?) )";
		st.prepare(sql);
		st.set_string( 0,p.strName );
		st.set_string( 1, p.strDescribe );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int Company_ID;
		Company_ID = rs.get_long( 0 );
		rs.close();
		return Company_ID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::InsertSubCompany(SUBCOMPANY p, int CompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select SubCompanyID from final table (insert into BR_SUBCOMPANY(CompanyID,SubNAME,SVersion) values (?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, CompanyID);
		st.set_string( 1, p.strName );
		st.set_string( 2, p.strDescribe );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::InsertAMSO(AMSO p, int SubCompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select AMSOID from final table (insert into BR_AMSO(SubCompanyID,AMSONAME,SVersion) values (?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, SubCompanyID);
		st.set_string( 1, p.strName );
		st.set_string( 2, p.strDescribe );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::InsertRoute(ROUTE p, int AMSOID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select RouteID from final table (insert into BR_ROUTE(AMSOID,RouteNAME,SVersion) values (?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, AMSOID);
		st.set_string( 1, p.strName );
		st.set_string( 2, p.strDescribe );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::InsertConcentrator(CONCENTRATOR p, int RouteID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select ConcentratorID from final table (insert into BR_CONCENTRATOR(RouteID,ConcentratorNAME,DestAddr,DestPort,ConnectType,InstallPlace,APName,APProtocol,GetTerminalTimer,GetConcentratorTimer,HeartTimer,SimCardNumber,GPRSReConnectTimer,GPRSSignalStrength,SaveTimer,wirelessSearchTimer,ConcentratorAddr,ConcentratorCurrentTime) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, RouteID);
		st.set_string( 1, p.strName );
		st.set_string( 2, p.strDestIP );
		st.set_string( 3, p.strDestPort );
		st.set_string( 4, p.strConnectType );
		st.set_string( 5, p.strInstallPlace );
		st.set_string( 6, p.strAPName );
		st.set_string( 7, p.strAPProtocol );
		st.set_long( 8, p.TerminalTimer);
		st.set_long( 9, p.ConcentratorTimer);
		st.set_long( 10, p.HeartTimer);
		st.set_string( 11, p.strSimCard );
		st.set_long( 12, p.GPRSReConnectTimer);
		st.set_long( 13, p.GPRSSignalStrength);
		st.set_long( 14, p.SaveTimer);
		st.set_long( 15, p.wirelessSearchTimer);
		st.set_long( 16, p.ConcentratorAddr);
		st.set_bigInt( 17, p.ConcentratorCurrentTime);
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::InsertLine(LINE p, int ConcentratorID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select LineID from final table (insert into BR_LINE(ConcentratorID,LineNAME,LineType,WorkerID) values (?, ?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, ConcentratorID);
		st.set_string( 1, p.strName );
		st.set_string( 2, p.strType );
		st.set_long(3, p.workerID);
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::InsertTerminal(TERMINAL p, int LineID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select TerminalID from final table (insert into BR_TERMINAL(LineID,TerminalNAME,TerminalTYPE,TerminalIndex,TerminalInstallTime,TerminalAddr,TerminalPreAddr,TerminalNextAddr,ConcentratorAddr,TerminalCurrentTime,RouteState1,RouteState2,RouteState3,RouteState4,RouteState5,RouteState6) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, LineID);
		st.set_string( 1, p.strName );
		st.set_string( 2, p.strType );
		st.set_long(3, p.index);
		st.set_bigInt(4, p.installTime);
		st.set_long(5, p.addr);
		st.set_long(6, p.preAddr);
		st.set_long(7, p.nextAddr);
		st.set_long(8, p.ConcentratorAddr);
		st.set_bigInt(9, p.TerminalCurrentTime);
		st.set_long(10, p.RouteState1);
		st.set_long(11, p.RouteState2);
		st.set_long(12, p.RouteState3);
		st.set_long(13, p.RouteState4);
		st.set_long(14, p.RouteState5);
		st.set_long(15, p.RouteState6);
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}

int CDATAOperate::InsertData(DATA p)
{
	try
	{
		//SYSTEMTIME sysTime;
		//GetLocalTime(&sysTime);

		//FILETIME ft={0}; 
		//SystemTimeToFileTime(&sysTime, &ft); 

		//ULONGLONG collectTime;
		//// Copy the time into a quadword.
		//collectTime = (((ULONGLONG) ft.dwHighDateTime) << 32) + ft.dwLowDateTime;


		PreparedStatement st(m_conn);
		char *sql = "select DataID from final table (insert into BR_DATA(TerminalAddr,ConcentratorAddr,CollectTime,relaycnt,relayPosition,GetherUnitAddr,vValue,vAngValue,iValue,iAngValue) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?) )";
		st.prepare(sql);
		st.set_long(0, p.TerminalAddr);
		st.set_long( 1, p.ConcentratorAddr );
		st.set_bigInt(2, p.CollectTime);
		st.set_long( 3, p.relaycnt );
		st.set_long( 4, p.relayPosition );
		st.set_long( 5, p.GetherUnitAddr );
		st.set_long( 6, p.vValue );
		st.set_long( 7, p.vAngValue );
		st.set_long( 8, p.iValue );
		st.set_long( 9, p.iAngValue );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}

		int newID;
		newID = rs.get_long( 0 );
		rs.close();
		return newID;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}


BOOL CDATAOperate::DelCompany(int companyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_COMPANY where CompanyID = ?";
		st.prepare(sql);
		st.set_long( 0, companyID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelSubCompany(int subCompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_SUBCOMPANY where SubCompanyID = ?";
		st.prepare(sql);
		st.set_long( 0, subCompanyID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelAMSO(int AMSOID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_AMSO where AmsoID = ?";
		st.prepare(sql);
		st.set_long( 0, AMSOID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelRoute(int RouteID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_ROUTE where RouteID = ?";
		st.prepare(sql);
		st.set_long( 0, RouteID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelConcentrator(int ConcentratorID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_CONCENTRATOR where ConcentratorID = ?";
		st.prepare(sql);
		st.set_long( 0, ConcentratorID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelLine(int lineID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_LINE where LineID = ?";
		st.prepare(sql);
		st.set_long( 0, lineID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelTerminal(int TerminalID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_TERMINAL where TerminalID = ?";
		st.prepare(sql);
		st.set_long( 0, TerminalID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}
BOOL CDATAOperate::DelData(int TerminalID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "delete from BR_DATA where TerminalID = ?";
		st.prepare(sql);
		st.set_long( 0, TerminalID );
		st.execute();
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return FALSE;
	}
	return TRUE;
}

int CDATAOperate::ModifyCompany(COMPANY p, int CompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_COMPANY set CName=?,SVersion=? where CompanyID=?";
		st.prepare(sql);
		st.set_string( 0,p.strName );
		st.set_string( 1, p.strDescribe );
		st.set_long(2, CompanyID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::ModifySubCompany(SUBCOMPANY p, int SubCompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_SUBCOMPANY set SubNAME=?,SVersion=? where SubCompanyID=?";
		st.prepare(sql);
		st.set_string( 0,p.strName );
		st.set_string( 1, p.strDescribe );
		st.set_long(2, SubCompanyID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::ModifyAMSO(AMSO p, int AMSOID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_AMSO set AmsoNAME=?,SVersion=? where AmsoID=?";
		st.prepare(sql);
		st.set_string( 0,p.strName );
		st.set_string( 1, p.strDescribe );
		st.set_long(2, AMSOID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::ModifyRoute(ROUTE p, int RouteID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_ROUTE set RouteNAME=?,SVersion=? where RouteID=?";
		st.prepare(sql);
		st.set_string( 0,p.strName );
		st.set_string( 1, p.strDescribe );
		st.set_long(2, RouteID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::ModifyConcentrator(CONCENTRATOR p, int ConcentratorID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_CONCENTRATOR set ConcentratorNAME=?,DestAddr=?,DestPort=?,ConnectType=?,InstallPlace=?,APName=?,APProtocol=?,GetTerminalTimer=?,GetConcentratorTimer=?,HeartTimer=?,SimCardNumber=?,GPRSReConnectTimer=?,GPRSSignalStrength=?,SaveTimer=?,wirelessSearchTimer=?,ConcentratorAddr=?,ConcentratorCurrentTime=? where ConcentratorID=?";
		st.prepare(sql);
		st.set_string( 0, p.strName );
		st.set_string( 1, p.strDestIP );
		st.set_string( 2, p.strDestPort );
		st.set_string( 3, p.strConnectType );
		st.set_string( 4, p.strInstallPlace );
		st.set_string( 5, p.strAPName );
		st.set_string( 6, p.strAPProtocol );
		st.set_long( 7, p.TerminalTimer);
		st.set_long( 8, p.ConcentratorTimer);
		st.set_long( 9, p.HeartTimer);
		st.set_string( 10, p.strSimCard );
		st.set_long(11, p.GPRSReConnectTimer);
		st.set_long(12, p.GPRSSignalStrength);
		st.set_long(13, p.SaveTimer);
		st.set_long(14, p.wirelessSearchTimer);
		st.set_long(15, p.ConcentratorAddr);
		st.set_bigInt(16, p.ConcentratorCurrentTime);
		st.set_long(17, ConcentratorID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::ModifyLine(LINE p, int LineID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_LINE set LineNAME=?,LineType=?,WorkerID=? where LineID=?";
		st.prepare(sql);
		st.set_string( 0,p.strName );
		st.set_string( 1, p.strType );
		st.set_long(2, p.workerID);
		st.set_long(3, LineID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::ModifyTerminal(TERMINAL p, int TerminalID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "update BR_TERMINAL set TerminalNAME=?,TerminalTYPE=?,TerminalIndex=?,TerminalInstallTime=?,TerminalAddr=?,TerminalPreAddr=?,TerminalNextAddr=?,ConcentratorAddr=?,TerminalCurrentTime=?,RouteState1=?,RouteState2=?,RouteState3=?,RouteState4=?,RouteState5=?,RouteState6=? where TerminalID=?";
		st.prepare(sql);
		st.set_string( 0, p.strName );
		st.set_string( 1, p.strType );
		st.set_long(2, p.index);
		st.set_bigInt(3, p.installTime);
		st.set_long(4, p.addr);
		st.set_long(5, p.preAddr);
		st.set_long(6, p.nextAddr);
		st.set_long(7, p.ConcentratorAddr);
		st.set_bigInt(8, p.TerminalCurrentTime);
		st.set_long(9, p.RouteState1);
		st.set_long(10, p.RouteState2);
		st.set_long(11, p.RouteState3);
		st.set_long(12, p.RouteState4);
		st.set_long(13, p.RouteState5);
		st.set_long(14, p.RouteState6);
		st.set_long(15, TerminalID);
		st.execute();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}


int CDATAOperate::GetCompany(COMPANY &p, int CompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select CName,SVersion from BR_COMPANY where CompanyID = ?";
		st.prepare(sql);
		st.set_long( 0, CompanyID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.strName = rs.get_string(0);
		p.strDescribe = rs.get_string(1);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetSubCompany(SUBCOMPANY &p, int SubCompanyID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select CompanyID,SubNAME,SVersion from BR_SUBCOMPANY where SubCompanyID = ?";
		st.prepare(sql);
		st.set_long( 0, SubCompanyID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.companyID = rs.get_long(0);
		p.strName = rs.get_string(1);
		p.strDescribe = rs.get_string(2);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAMSO(AMSO &p, int AMSOID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select SubCompanyID,AmsoNAME,SVersion from BR_AMSO where AmsoID = ?";
		st.prepare(sql);
		st.set_long( 0, AMSOID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.subCompanyID = rs.get_long(0);
		p.strName = rs.get_string(1);
		p.strDescribe = rs.get_string(2);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetRoute(ROUTE &p, int RouteID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select AmsoID,RouteNAME,SVersion from BR_ROUTE where RouteID = ?";
		st.prepare(sql);
		st.set_long( 0, RouteID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.AMSOID = rs.get_long(0);
		p.strName = rs.get_string(1);
		p.strDescribe = rs.get_string(2);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}

int CDATAOperate::GetConcentrator(CONCENTRATOR &p, int ConcentratorID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select RouteID,ConcentratorNAME,DestAddr,DestPort,ConnectType,InstallPlace,APName,APProtocol,GetTerminalTimer,GetConcentratorTimer,HeartTimer,SimCardNumber,GPRSReConnectTimer,GPRSSignalStrength,SaveTimer,wirelessSearchTimer,ConcentratorAddr,ConcentratorCurrentTime from BR_CONCENTRATOR where ConcentratorID = ?";
		st.prepare(sql);
		st.set_long( 0, ConcentratorID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.routeID = rs.get_long(0);
		p.strName = rs.get_string(1);
		p.strDestIP = rs.get_string(2);
		p.strDestPort = rs.get_string(3);
		p.strConnectType = rs.get_string(4);
		p.strInstallPlace = rs.get_string(5);
		p.strAPName = rs.get_string(6);
		p.strAPProtocol = rs.get_string(7);
		p.TerminalTimer = rs.get_long(8);
		p.ConcentratorTimer = rs.get_long(9);
		p.HeartTimer = rs.get_long(10);
		p.strSimCard = rs.get_string(11);
		p.GPRSReConnectTimer = rs.get_long(12);
		p.GPRSSignalStrength = rs.get_long(13);
		p.SaveTimer = rs.get_long(14);
		p.wirelessSearchTimer = rs.get_long(15);
		p.ConcentratorAddr = rs.get_long(16);
		p.ConcentratorCurrentTime = rs.get_bigInt(17);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}

int CDATAOperate::GetLine(LINE &p, int LineID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select ConcentratorID,LineNAME,LineType,WorkerID from BR_LINE where LineID = ?";
		st.prepare(sql);
		st.set_long( 0, LineID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.ConcentratorID = rs.get_long(0);
		p.strName = rs.get_string(1);
		p.strType = rs.get_string(2);
		p.workerID = rs.get_long(3);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetTerminal(TERMINAL &p, int TerminalID)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select LineID,TerminalNAME,TerminalTYPE,TerminalIndex,TerminalInstallTime,TerminalAddr,TerminalPreAddr,TerminalNextAddr,ConcentratorAddr,TerminalCurrentTime,RouteState1,RouteState2,RouteState3,RouteState4,RouteState5,RouteState6 from BR_TERMINAL where TerminalID = ?";
		st.prepare(sql);
		st.set_long( 0, TerminalID );
		ADO_WRAPPER::ResultSet rs = st.execute();
		if( rs.db_eof() )
		{
			rs.close();
			return 0;
		}
		p.lineID = rs.get_long(0);
		p.strName = rs.get_string(1);
		p.strType = rs.get_string(2);
		p.index = rs.get_long(3);
		p.installTime = rs.get_bigInt(4);
		p.addr = rs.get_long(5);
		p.preAddr = rs.get_long(6);
		p.nextAddr = rs.get_long(7);
		p.ConcentratorAddr = rs.get_long(8);
		p.TerminalCurrentTime = rs.get_bigInt(9);
		p.RouteState1 = rs.get_long(10);
		p.RouteState2 = rs.get_long(11);
		p.RouteState3 = rs.get_long(12);
		p.RouteState4 = rs.get_long(13);
		p.RouteState5 = rs.get_long(14);
		p.RouteState6 = rs.get_long(15);
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}

int CDATAOperate::GetAllCompanyID(vector<COMPANY> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select CompanyID,CName,SVersion from BR_COMPANY";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			COMPANY p;
			p.companyID = rs.get_long(0);
			p.strName = rs.get_string(1);
			p.strDescribe = rs.get_string(2);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAllSubCompanyID(vector<SUBCOMPANY> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select SubCompanyID,CompanyID,SubNAME,SVersion from BR_SUBCOMPANY";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			SUBCOMPANY p;
			p.subCompanyID = rs.get_long(0);
			p.companyID = rs.get_long(1);
			p.strName = rs.get_string(2);
			p.strDescribe = rs.get_string(3);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAllAMSOID(vector<AMSO> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select AmsoID,SubCompanyID,AmsoNAME,SVersion from BR_AMSO";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			AMSO p;
			p.AMSOID = rs.get_long(0);
			p.subCompanyID = rs.get_long(1);
			p.strName = rs.get_string(2);
			p.strDescribe = rs.get_string(3);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAllRouteID(vector<ROUTE> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select RouteID,AmsoID,RouteNAME,SVersion from BR_ROUTE";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			ROUTE p;
			p.routeID = rs.get_long(0);
			p.AMSOID = rs.get_long(1);
			p.strName = rs.get_string(2);
			p.strDescribe = rs.get_string(3);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAllConcentratorID(vector<CONCENTRATOR> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select ConcentratorID,RouteID,ConcentratorNAME,DestAddr,DestPort,ConnectType,InstallPlace,APName,APProtocol,GetTerminalTimer,GetConcentratorTimer,HeartTimer,SimCardNumber,GPRSReConnectTimer,GPRSSignalStrength,SaveTimer,wirelessSearchTimer,ConcentratorAddr,ConcentratorCurrentTime from BR_CONCENTRATOR";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			CONCENTRATOR p;
			p.ConcentratorID = rs.get_long(0);
			p.routeID = rs.get_long(1);
			p.strName = rs.get_string(2);
			p.strDestIP = rs.get_string(3);
			p.strDestPort = rs.get_string(4);
			p.strConnectType = rs.get_string(5);
			p.strInstallPlace = rs.get_string(6);
			p.strAPName = rs.get_string(7);
			p.strAPProtocol = rs.get_string(8);
			p.TerminalTimer = rs.get_long(9);
			p.ConcentratorTimer = rs.get_long(10);
			p.HeartTimer = rs.get_long(11);
			p.strSimCard = rs.get_string(12);
			p.GPRSReConnectTimer = rs.get_long(13);
			p.GPRSSignalStrength = rs.get_long(14);
			p.SaveTimer = rs.get_long(15);
			p.wirelessSearchTimer = rs.get_long(16);
			p.ConcentratorAddr = rs.get_long(17);
			p.ConcentratorCurrentTime = rs.get_bigInt(18);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAllLineID(vector<LINE> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select LineID,ConcentratorID,LineNAME,LineType,WorkerID from BR_LINE";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			LINE p;
			p.lineID = rs.get_long(0);
			p.ConcentratorID = rs.get_long(1);
			p.strName = rs.get_string(2);
			p.strType = rs.get_string(3);
			p.workerID = rs.get_long(4);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetAllTerminalID(vector<TERMINAL> &v)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select TerminalID,LineID,TerminalNAME,TerminalTYPE,TerminalIndex,TerminalInstallTime,TerminalAddr,TerminalPreAddr,TerminalNextAddr,ConcentratorAddr,TerminalCurrentTime,RouteState1,RouteState2,RouteState3,RouteState4,RouteState5,RouteState6 from BR_TERMINAL";
		st.prepare(sql);
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			TERMINAL p;
			p.TerminalID = rs.get_long(0);
			p.lineID = rs.get_long(1);
			p.strName = rs.get_string(2);
			p.strType = rs.get_string(3);
			p.index = rs.get_long(4);
			p.installTime = rs.get_bigInt(5);
			p.addr = rs.get_long(6);
			p.preAddr = rs.get_long(7);
			p.nextAddr = rs.get_long(8);
			p.ConcentratorAddr = rs.get_long(9);
			p.TerminalCurrentTime = rs.get_bigInt(10);
			p.RouteState1 = rs.get_long(11);
			p.RouteState2 = rs.get_long(12);
			p.RouteState3 = rs.get_long(13);
			p.RouteState4 = rs.get_long(14);
			p.RouteState5 = rs.get_long(15);
			p.RouteState6 = rs.get_long(16);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}

int CDATAOperate::GetDatabyConcentratorID(vector<DATA> &v, int ConAddr)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select DataID,TerminalAddr,ConcentratorAddr,CollectTime,relaycnt,relayPosition,GetherUnitAddr,vValue,vAngValue,iValue,iAngValue from BR_DATA where ConcentratorAddr = ?";
		st.prepare(sql);
		st.set_long( 0, ConAddr );
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			DATA p;
			p.DataID = rs.get_long(0);
			p.TerminalAddr = rs.get_long(1);
			p.ConcentratorAddr = rs.get_long(2);
			p.CollectTime = rs.get_bigInt(3);
			p.relaycnt = rs.get_long(4);
			p.relayPosition = rs.get_long(5);
			p.GetherUnitAddr = rs.get_long(6);
			p.vValue = rs.get_long(7);
			p.vAngValue = rs.get_long(8);
			p.iValue = rs.get_long(9);
			p.iAngValue = rs.get_long(10);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}
int CDATAOperate::GetDatabyTerminalID(vector<DATA> &v, int ConAddr, int TerminalAddr)
{
	try
	{
		PreparedStatement st(m_conn);
		char *sql = "select DataID,TerminalAddr,ConcentratorAddr,CollectTime,relaycnt,relayPosition,GetherUnitAddr,vValue,vAngValue,iValue,iAngValue from BR_DATA where TerminalAddr = ? and ConcentratorAddr = ?";
		st.prepare(sql);
		st.set_long( 0, TerminalAddr );
		st.set_long( 1, ConAddr );
		ADO_WRAPPER::ResultSet rs = st.execute();
		v.clear();
		while( !rs.db_eof() )
		{
			DATA p;
			p.DataID = rs.get_long(0);
			p.TerminalAddr = rs.get_long(1);
			p.ConcentratorAddr = rs.get_long(2);
			p.CollectTime = rs.get_bigInt(3);
			p.relaycnt = rs.get_long(4);
			p.relayPosition = rs.get_long(5);
			p.GetherUnitAddr = rs.get_long(6);
			p.vValue = rs.get_long(7);
			p.vAngValue = rs.get_long(8);
			p.iValue = rs.get_long(9);
			p.iAngValue = rs.get_long(10);
			v.push_back(p);
			rs.move_next();
		}
		rs.close();
		return 1;
	}
	catch (_com_error& e)
	{
		OutputDebugString(e.Description());
		return 0;
	}
	return 0;
}