// ManageStudentAccountDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include"ManageStudentAccountDlg.h"
#include "afxdialogex.h"

//COLUMN_DATA AccountInfo[] =
//{
//	{ "账号",			160 },
//	{ "密码",			160 },
//	
//};

// CManageStudentAccountDlg 对话框

IMPLEMENT_DYNAMIC(CManageStudentAccountDlg, CDialogEx)

CManageStudentAccountDlg::CManageStudentAccountDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGE_STUDENT_ACCOUNT_DIALOG, pParent)
	, m_StudentAccountEdit(_T(""))
	, m_StudentPasswordEdit(_T(""))
	, m_account(_T(""))
	, m_password(_T(""))
{

}

CManageStudentAccountDlg::~CManageStudentAccountDlg()
{
}

void CManageStudentAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENT_ACCOUNT_LIST, m_StudentAccountList);
	/*DDX_Control(pDX, IDC_ACCOUNT_EDIT, m_StudentAccountEdit);
	DDX_Control(pDX, IDC_PASSWORD_EDIT, m_StudentPasswordEdit);*/
	DDX_Text(pDX, IDC_ACCOUNT_EDIT, m_account);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_password);
}


BEGIN_MESSAGE_MAP(CManageStudentAccountDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_ACCOUNT_BUTTON, &CManageStudentAccountDlg::OnBnClickedAddAccountButton)
	ON_BN_CLICKED(IDC_DELETE_ACCOUNT_BUTTON, &CManageStudentAccountDlg::OnBnClickedDeleteAccountButton)
END_MESSAGE_MAP()


// CManageStudentAccountDlg 消息处理程序


void CManageStudentAccountDlg::OnBnClickedAddAccountButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_account == TEXT("") || m_password == TEXT("") )
	{
		MessageBox(TEXT("您的输入的信息有为空！请重新输入！"), TEXT("提示"));
		return;
	}


	if (SQL.Add_Stu_Account(Student_Login(m_account.GetBuffer(), m_password.GetBuffer())))
	{
		MessageBox(TEXT("您已添加成功！"), TEXT("提示"));
	}
	UpdateList();

}


void CManageStudentAccountDlg::OnBnClickedDeleteAccountButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_account == TEXT("") )
	{
		MessageBox(TEXT("您的输入的账户为空！请重新输入！"), TEXT("提示"));
		return;
	}


	if (SQL.Delete_Stu_Account(m_account.GetBuffer()))
	{
		MessageBox(TEXT("您已删除成功！"), TEXT("提示"));
	}
	UpdateList();
}


BOOL CManageStudentAccountDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//for (int i = 0; i < sizeof(AccountInfo) / sizeof(COLUMN_DATA); i++)
	//{
	//	m_StudentAccountList.InsertColumn(i, AccountInfo[i].TitleData, LVCFMT_CENTER, AccountInfo[i].TitleWidth);
	//}
	//m_StudentAccountList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	font.CreatePointFont(200, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_MANAGE_STUDENT_ACCOUNT_STATIC)->SetFont(&font);
	GetDlgItem(IDC_MANAGE_ACCOUNT_STATIC)->SetFont(&font);

	m_StudentAccountList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_StudentAccountList.InsertColumn(0, _T("学生账号"), LVCFMT_LEFT, 150);	// 插入第1列的列名
	m_StudentAccountList.InsertColumn(1, _T("密码"), LVCFMT_LEFT, 150);	// 插入第2列的列名


	//连接数据库
	if (SQL.ConnectMysql()) {
		UpdateList();
	}
	else {
		return true;
	};

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CManageStudentAccountDlg::UpdateList()
{
	m_StudentAccountList.DeleteAllItems();
	Info = SQL.Get_AllLogin_info();

	for (int i = 0; i < Info.size(); i++) {
		m_StudentAccountList.InsertItem(i, _T(""));						// 插入行
		m_StudentAccountList.SetItemText(i, 0, Info[i]._account.c_str());//插入第一列
		m_StudentAccountList.SetItemText(i, 1, Info[i]._password.c_str());		//插入第二列	
	}
}

