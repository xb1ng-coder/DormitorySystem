// ManagerDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "ManagerDlg.h"


// CManagerDlg 对话框

IMPLEMENT_DYNAMIC(CManagerDlg, CDialogEx)

CManagerDlg::CManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGER_DIALOG, pParent)
{

}

CManagerDlg::~CManagerDlg()
{
}

void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MANAGER_TAB, m_tab);
}


BEGIN_MESSAGE_MAP(CManagerDlg, CDialogEx)
	//ON_NOTIFY(TCN_SELCHANGE, IDC_MANAGER_TAB, &CManagerDlg::OnTcnSelchangeManagerTab)
	ON_NOTIFY(TCN_SELCHANGE, IDC_MANAGER_TAB, &CManagerDlg::OnTcnSelchangeManagerTab)
	ON_MESSAGE(UM_CLOSE_MANAGER_DLG, CloseManagerDlg)
	ON_WM_CLOSE()
END_MESSAGE_MAP()




BOOL CManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	m_tab.InsertItem(0, _T("查看学生住宿信息"));
	m_tab.InsertItem(1, _T("管理学生住宿信息"));
	m_tab.InsertItem(2, _T("处理报修信息"));
	m_tab.InsertItem(3, _T("管理学生账号"));
	m_tab.InsertItem(4, _T("修改密码"));


	QueryInfoDlg.Create(IDD_QUERY_STUDENT_INFO_DIALOG, &m_tab);
	ManageStudentInfoDlg.Create(IDD_MANAGE_STUDENT_INFO_DIALOG, &m_tab);
	HandleRepairInfoDlg.Create(IDD_HANDLE_REPAIR_INFO_DIALOG, &m_tab);
	ManageAccountDlg.Create(IDD_MANAGE_STUDENT_ACCOUNT_DIALOG, &m_tab);
	ModifyPasswordDlg.Create(IDD_MODIFY_PASSWORD_DIALOG, &m_tab);
	
	
	//设定在Tab内显示的范围
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 20;
	rc.left += 20;
	rc.right -= 20;
	QueryInfoDlg.MoveWindow(&rc);
	ManageStudentInfoDlg.MoveWindow(&rc);
	HandleRepairInfoDlg.MoveWindow(&rc);
	ManageAccountDlg.MoveWindow(&rc);
	ModifyPasswordDlg.MoveWindow(&rc);

	//把对话框对象指针保存起来
	pDialog[0] = &QueryInfoDlg;
	pDialog[1] = &ManageStudentInfoDlg;
	pDialog[2] = &HandleRepairInfoDlg;
	pDialog[3] = &ManageAccountDlg;
	pDialog[4] = &ModifyPasswordDlg;
	//显示初始页面
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);
	pDialog[4]->ShowWindow(SW_HIDE);
	//保存当前选择
	m_CurSelTab = 0;







	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CManagerDlg::OnTcnSelchangeManagerTab(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	//把当前的页面隐藏起来
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_CurSelTab = m_tab.GetCurSel();
	//把新的页面显示出来
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);

	*pResult = 0;
}

LRESULT CManagerDlg::CloseManagerDlg(WPARAM parameter1, LPARAM parameter2)
{
	DestroyWindow();
	return 0;
}


//void CManagerDlg::OnClose()
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	DestroyWindow();
//	CDialogEx::OnClose();
//}
