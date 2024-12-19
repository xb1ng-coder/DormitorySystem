// ReportRepairDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "ReportRepairDlg.h"

//COLUMN_DATA StudentReportRepairInfo[] =
//{
//	{ "报修编号",			30 },
//	{ "寝楼",			150 },
//	{ "宿舍号",	40 },
//	{ "时间",		160 },
//	{ "问题",			150 },
//	{ "状况",		100 }
//
//
//};
// CReportRepairDlg 对话框

IMPLEMENT_DYNAMIC(CReportRepairDlg, CDialogEx)

CReportRepairDlg::CReportRepairDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REPORT_REPAIR_DIALOG, pParent)
	, m_dormBuilding(_T(""))
	, m_dorimitoryNumber(_T(""))
	, m_question(_T(""))
	, m_repair_time(_T(""))
{

}

CReportRepairDlg::~CReportRepairDlg()
{
}

void CReportRepairDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENT_REPORT_REPAIR_LIST, m_StudentRepairInfoList);
	DDX_Text(pDX, IDC_STUDENT_REPORT_REPAIR_EDIT, m_dormBuilding);
	DDX_Text(pDX, IDC_STUDENT_DORM_NUM_EDIT, m_dorimitoryNumber);
	DDX_Text(pDX, IDC_STUDENT_QUESTION_EDIT, m_question);
	DDX_Text(pDX, IDC_STUDENT_REPORT_TIME_EDIT, m_repair_time);
}


BEGIN_MESSAGE_MAP(CReportRepairDlg, CDialogEx)
	ON_BN_CLICKED(IDC_REPORT_REPAIR_BUTTON, &CReportRepairDlg::OnBnClickedReportRepairButton)
END_MESSAGE_MAP()


// CReportRepairDlg 消息处理程序





BOOL CReportRepairDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//for (int i = 0; i < sizeof(StudentReportRepairInfo) / sizeof(COLUMN_DATA); i++)
	//{
	//	m_StudentRepairInfoList.InsertColumn(i, StudentReportRepairInfo[i].TitleData, LVCFMT_CENTER, StudentReportRepairInfo[i].TitleWidth);
	//}
	//m_StudentRepairInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_StudentRepairInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_StudentRepairInfoList.InsertColumn(0, _T("报修序号"), LVCFMT_LEFT, 150);	// 插入第1列的列名
	m_StudentRepairInfoList.InsertColumn(1, _T("宿舍楼"), LVCFMT_LEFT, 150);	// 插入第2列的列名
	m_StudentRepairInfoList.InsertColumn(2, _T("宿舍号"), LVCFMT_LEFT, 150);	// 插入第3列的列名
	m_StudentRepairInfoList.InsertColumn(3, _T("报修时间"), LVCFMT_LEFT, 150);	// 插入第4列的列名
	m_StudentRepairInfoList.InsertColumn(4, _T("问题"), LVCFMT_LEFT, 150);	// 插入第5列的列名
	m_StudentRepairInfoList.InsertColumn(5, _T("处理状况"), LVCFMT_LEFT, 150);	// 插入第6列的列名

	//连接数据库
	if (SQL.ConnectMysql()) {
		Info = SQL.Search_StuRepair_info(Global::L_Username.c_str());
		Updata_List();
	}
	else {
		return true;
	};

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CReportRepairDlg::OnBnClickedReportRepairButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_dormBuilding == TEXT("") || m_dorimitoryNumber == TEXT("") || m_repair_time == TEXT("") || m_question == TEXT("")) {
		MessageBox(TEXT("您的输入的信息有为空！请重新输入！"), TEXT("提示"));
		return;
	}
	string _test01 = "null";
	Repair_Info Info1(_test01, m_dormBuilding.GetBuffer(), m_dorimitoryNumber.GetBuffer(),
		m_repair_time.GetBuffer(), m_question.GetBuffer(), _test01);


	if (SQL.Add_Repair_info(Info1))
	{
		MessageBox(TEXT("您已报修成功！"), TEXT("提示"));
		Info.push_back(Info1);
		Updata_List();
	}
}

void CReportRepairDlg::Updata_List()
{
	m_StudentRepairInfoList.DeleteAllItems();
	for (int i = 0; i < Info.size(); i++) {
		m_StudentRepairInfoList.InsertItem(i, _T(""));						// 插入行
		m_StudentRepairInfoList.SetItemText(i, 0, Info[i]._repairNumber.c_str());//插入第一列
		m_StudentRepairInfoList.SetItemText(i, 1, Info[i]._dormBuilding.c_str());		//插入第二列	
		m_StudentRepairInfoList.SetItemText(i, 2, Info[i]._dormitoryNumber.c_str());		//插入第三列		
		m_StudentRepairInfoList.SetItemText(i, 3, Info[i]._repair_time.c_str());	//插入第四列			
		m_StudentRepairInfoList.SetItemText(i, 4, Info[i]._question.c_str());	//插入第五列	
		m_StudentRepairInfoList.SetItemText(i, 5, Info[i]._situation.c_str());	//插入第六列
	}
}
