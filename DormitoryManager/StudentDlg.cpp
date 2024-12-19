// StudentDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "StudentDlg.h"


// CStudentDlg 对话框

IMPLEMENT_DYNAMIC(CStudentDlg, CDialogEx)

CStudentDlg::CStudentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_INTERFACE_DIALOG, pParent)
{

}

CStudentDlg::~CStudentDlg()
{
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CStudentDlg::OnTcnSelchangeTab1)
	ON_MESSAGE(UM_CLOSE_STUDENT_DLG, CloseStudentDlg)
END_MESSAGE_MAP()


// CStudentDlg 消息处理程序


BOOL CStudentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_tab.InsertItem(0, _T("寝室人员"));
	m_tab.InsertItem(1, _T("报修"));
	m_tab.InsertItem(2, _T("修改密码"));



	DormMemberDlg.Create(IDD_DORM_MEMBER_DIALOG, &m_tab);
	ReportRepairDlg.Create(IDD_REPORT_REPAIR_DIALOG, &m_tab);
	StudentModifyPasswordDlg.Create(IDD_STUDENT_MODIFY_PASSWORD_DIALOG, &m_tab);



	//设定在Tab内显示的范围
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	DormMemberDlg.MoveWindow(&rc);
	ReportRepairDlg.MoveWindow(&rc);
	StudentModifyPasswordDlg.MoveWindow(&rc);


	//把对话框对象指针保存起来
	pDialog[0] = &DormMemberDlg;
	pDialog[1] = &ReportRepairDlg;
	pDialog[2] = &StudentModifyPasswordDlg;

	//显示初始页面
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);

	//保存当前选择
	m_CurSelTab = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CStudentDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
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

LRESULT CStudentDlg::CloseStudentDlg(WPARAM parameter1, LPARAM parameter2)
{
	DestroyWindow();
	return LRESULT();
}
