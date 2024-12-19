// DormMemberDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "DormMemberDlg.h"
#include"Live_Login.h"

//COLUMN_DATA DormMemberInfo[] =
//{
//	{ "学号",			100 },
//	{ "姓名",			100 },
//	{ "性别",	40 },
//	{ "专业",		160 },
//	{ "班级",			120 },
//	{ "宿舍号",		80 },
//	{ "寝楼",		150 },
//	{ "联系电话",		160 }
//
//};

// CDormMemberDlg 对话框

IMPLEMENT_DYNAMIC(CDormMemberDlg, CDialogEx)

CDormMemberDlg::CDormMemberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DORM_MEMBER_DIALOG, pParent)
{

}

CDormMemberDlg::~CDormMemberDlg()
{
}

void CDormMemberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DORM_MEMBER_INFO_LIST, m_DormMemberInfoList);
}


BEGIN_MESSAGE_MAP(CDormMemberDlg, CDialogEx)
END_MESSAGE_MAP()


// CDormMemberDlg 消息处理程序


BOOL CDormMemberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//for (int i = 0; i < sizeof(DormMemberInfo) / sizeof(COLUMN_DATA); i++)
	//{
	//	m_DormMemberInfoList.InsertColumn(i, DormMemberInfo[i].TitleData, LVCFMT_CENTER, DormMemberInfo[i].TitleWidth);
	//}
	//m_DormMemberInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_DormMemberInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_DormMemberInfoList.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 140);	// 插入第1列的列名
	m_DormMemberInfoList.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 140);	// 插入第2列的列名
	m_DormMemberInfoList.InsertColumn(2, _T("性别"), LVCFMT_LEFT, 100);	// 插入第3列的列名
	m_DormMemberInfoList.InsertColumn(3, _T("专业"), LVCFMT_LEFT, 180);	// 插入第4列的列名
	m_DormMemberInfoList.InsertColumn(4, _T("班级"), LVCFMT_LEFT, 140);	// 插入第5列的列名
	m_DormMemberInfoList.InsertColumn(5, _T("宿舍号"), LVCFMT_LEFT, 140);	// 插入第6列的列名
	m_DormMemberInfoList.InsertColumn(6, _T("宿舍楼"), LVCFMT_LEFT, 140);	// 插入第7列的列名
	m_DormMemberInfoList.InsertColumn(7, _T("联系方式"), LVCFMT_LEFT, 140);	// 插入第8列的列名

	//连接数据库
	if (SQL.ConnectMysql()) {
		Info = SQL.Get_SameStuID_info(Global::L_Username.c_str());

		for (int i = 0; i < Info.size(); i++) {
			m_DormMemberInfoList.InsertItem(i, _T(""));						// 插入行
			m_DormMemberInfoList.SetItemText(i, 0, Info[i]._studentID.c_str());//插入第一列"学号"
			m_DormMemberInfoList.SetItemText(i, 1, Info[i]._name.c_str());		//插入第二列"姓名"		
			m_DormMemberInfoList.SetItemText(i, 2, Info[i]._sex.c_str());		//插入第三列"性别"		
			m_DormMemberInfoList.SetItemText(i, 3, Info[i]._major.c_str());	//插入第四列"专业"			
			m_DormMemberInfoList.SetItemText(i, 4, Info[i]._stuclass.c_str());	//插入第五列"班级"	
			m_DormMemberInfoList.SetItemText(i, 5, Info[i]._dormitoryNumber.c_str());	//插入第六列"宿舍号"
			m_DormMemberInfoList.SetItemText(i, 6, Info[i]._dormBuilding.c_str());		//插入第七列"宿舍楼"
			m_DormMemberInfoList.SetItemText(i, 7, Info[i]._phone.c_str());	//插入第八列"联系方式"
		}
	}
	else {
		return true;
	};


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
