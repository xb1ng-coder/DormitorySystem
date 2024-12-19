// QueryStudentInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "QueryStudentInfoDlg.h"



//COLUMN_DATA StudentDormitoryInfo[] =
//{
//	{ "学号",			120 },
//	{ "姓名",			160 },
//	{ "性别",	50 },
//	{ "专业",		180 },
//	{ "班级",			150 },
//	{ "宿舍号",		81 },
//	{ "寝楼",			160 },
//	{ "联系电话",			155 }
//};

// CQueryStudentInfoDlg 对话框

IMPLEMENT_DYNAMIC(CQueryStudentInfoDlg, CDialogEx)

CQueryStudentInfoDlg::CQueryStudentInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUERY_STUDENT_INFO_DIALOG, pParent)
	, m_studentID(_T(""))
{

}

CQueryStudentInfoDlg::~CQueryStudentInfoDlg()
{
}

void CQueryStudentInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENT_DORMITORY_INFO_LIST, m_StudentInfoList);
	DDX_Text(pDX, IDC_SEARCH_DORMITORY_EDIT, m_studentID);
}


BEGIN_MESSAGE_MAP(CQueryStudentInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH_DORMITORY_BUTTON, &CQueryStudentInfoDlg::OnBnClickedSearchDormitoryButton)
	ON_BN_CLICKED(IDC_BUTTON1, &CQueryStudentInfoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CQueryStudentInfoDlg 消息处理程序


BOOL CQueryStudentInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	font.CreatePointFont(170, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_QUERY_INFO_STATIC)->SetFont(&font);


	/*for (int i = 0; i < sizeof(StudentDormitoryInfo) / sizeof(COLUMN_DATA); i++)
	{
		m_StudentInfoList.InsertColumn(i, StudentDormitoryInfo[i].TitleData, LVCFMT_CENTER, StudentDormitoryInfo[i].TitleWidth);
	}
	m_StudentInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT);*/
	m_StudentInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_StudentInfoList.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 150);	// 插入第1列的列名
	m_StudentInfoList.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 150);	// 插入第2列的列名
	m_StudentInfoList.InsertColumn(2, _T("性别"), LVCFMT_LEFT, 150);	// 插入第3列的列名
	m_StudentInfoList.InsertColumn(3, _T("专业"), LVCFMT_LEFT, 250);	// 插入第4列的列名
	m_StudentInfoList.InsertColumn(4, _T("班级"), LVCFMT_LEFT, 150);	// 插入第5列的列名
	m_StudentInfoList.InsertColumn(5, _T("宿舍号"), LVCFMT_LEFT, 150);	// 插入第6列的列名
	m_StudentInfoList.InsertColumn(6, _T("宿舍楼"), LVCFMT_LEFT, 150);	// 插入第7列的列名
	m_StudentInfoList.InsertColumn(7, _T("联系方式"), LVCFMT_LEFT, 150);	// 插入第8列的列名

	//连接数据库
	if (SQL.ConnectMysql()) {
		Info = SQL.Get_AllStu_info();

		for (int i = 0; i < Info.size(); i++) {
			m_StudentInfoList.InsertItem(i, _T(""));						// 插入行
			m_StudentInfoList.SetItemText(i, 0, Info[i]._studentID.c_str());//插入第一列"学号"
			m_StudentInfoList.SetItemText(i, 1, Info[i]._name.c_str());		//插入第二列"姓名"		
			m_StudentInfoList.SetItemText(i, 2, Info[i]._sex.c_str());		//插入第三列"性别"		
			m_StudentInfoList.SetItemText(i, 3, Info[i]._major.c_str());	//插入第四列"专业"			
			m_StudentInfoList.SetItemText(i, 4, Info[i]._stuclass.c_str());	//插入第五列"班级"	
			m_StudentInfoList.SetItemText(i, 5, Info[i]._dormitoryNumber.c_str());	//插入第六列"宿舍号"
			m_StudentInfoList.SetItemText(i, 6, Info[i]._dormBuilding.c_str());		//插入第七列"宿舍楼"
			m_StudentInfoList.SetItemText(i, 7, Info[i]._phone.c_str());	//插入第八列"联系方式"
		}
	}
	else {
		return true;
	};

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CQueryStudentInfoDlg::OnBnClickedSearchDormitoryButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_studentID == TEXT("")) {
		MessageBox(TEXT("您的输入为空！请重新输入！"), TEXT("提示"));
		return;
	}
	
	//连接数据库

	Info = SQL.Search_StuID_info(m_studentID);
	if (Info.empty()) {
		MessageBox(TEXT("查无此人！请重新输入！"), TEXT("提示"));
		return;
	}
	m_StudentInfoList.DeleteAllItems();

	for (int i = 0; i < Info.size(); i++) {
		m_StudentInfoList.InsertItem(i, _T(""));						// 插入行
		m_StudentInfoList.SetItemText(i, 0, Info[i]._studentID.c_str());//插入第一列"学号"
		m_StudentInfoList.SetItemText(i, 1, Info[i]._name.c_str());		//插入第二列"姓名"		
		m_StudentInfoList.SetItemText(i, 2, Info[i]._sex.c_str());		//插入第三列"性别"		
		m_StudentInfoList.SetItemText(i, 3, Info[i]._major.c_str());	//插入第四列"专业"			
		m_StudentInfoList.SetItemText(i, 4, Info[i]._stuclass.c_str());	//插入第五列"班级"	
		m_StudentInfoList.SetItemText(i, 5, Info[i]._dormitoryNumber.c_str());	//插入第六列"宿舍号"
		m_StudentInfoList.SetItemText(i, 6, Info[i]._dormBuilding.c_str());		//插入第七列"宿舍楼"
		m_StudentInfoList.SetItemText(i, 7, Info[i]._phone.c_str());	//插入第八列"联系方式"
	}
}


void CQueryStudentInfoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_StudentInfoList.DeleteAllItems();
	Info = SQL.Get_AllStu_info();

	for (int i = 0; i < Info.size(); i++) {
		m_StudentInfoList.InsertItem(i, _T(""));						// 插入行
		m_StudentInfoList.SetItemText(i, 0, Info[i]._studentID.c_str());//插入第一列"学号"
		m_StudentInfoList.SetItemText(i, 1, Info[i]._name.c_str());		//插入第二列"姓名"		
		m_StudentInfoList.SetItemText(i, 2, Info[i]._sex.c_str());		//插入第三列"性别"		
		m_StudentInfoList.SetItemText(i, 3, Info[i]._major.c_str());	//插入第四列"专业"			
		m_StudentInfoList.SetItemText(i, 4, Info[i]._stuclass.c_str());	//插入第五列"班级"	
		m_StudentInfoList.SetItemText(i, 5, Info[i]._dormitoryNumber.c_str());	//插入第六列"宿舍号"
		m_StudentInfoList.SetItemText(i, 6, Info[i]._dormBuilding.c_str());		//插入第七列"宿舍楼"
		m_StudentInfoList.SetItemText(i, 7, Info[i]._phone.c_str());	//插入第八列"联系方式"
	}
}
