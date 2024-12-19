// StudentModifyPasswordDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "StudentModifyPasswordDlg.h"
#include "Live_Login.h"
#include"common.h"
#include"DormitoryManagerDlg.h"


// CStudentModifyPasswordDlg 对话框

IMPLEMENT_DYNAMIC(CStudentModifyPasswordDlg, CDialogEx)

CStudentModifyPasswordDlg::CStudentModifyPasswordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_MODIFY_PASSWORD_DIALOG, pParent)
	, oldpassword(_T(""))
	, newpassword(_T(""))
{

}

CStudentModifyPasswordDlg::~CStudentModifyPasswordDlg()
{
}

void CStudentModifyPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STUDENT_OLD_PASSWORD_EDIT, oldpassword);
	DDX_Text(pDX, IDC_STUDENT_NEW_PASSWORD_EDIT, newpassword);
}


BEGIN_MESSAGE_MAP(CStudentModifyPasswordDlg, CDialogEx)
	ON_BN_CLICKED(ID_STUDENT_MODIFY_PASSWORD_BUTTON, &CStudentModifyPasswordDlg::OnBnClickedStudentModifyPasswordButton)
END_MESSAGE_MAP()


// CStudentModifyPasswordDlg 消息处理程序


void CStudentModifyPasswordDlg::OnBnClickedStudentModifyPasswordButton()
{

	SQL.ConnectMysql();

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
	if (oldpassword.GetBuffer() != Global::L_Password) {
		MessageBox(TEXT("您的输入的原密码错误！请重新输入！"), TEXT("提示"));
		return;
	}
	else if(SQL.Update_Stu_Login(Global::L_Username.c_str(),newpassword ))
	{
		MessageBox(TEXT("您已修改成功！请重新登录！"), TEXT("提示"));

		/*HWND v1 = ::FindWindow(NULL, _T("学生界面"));
		::SendMessage(v1, UM_CLOSE_STUDENT_DLG, NULL, NULL);*/

		CDormitoryManagerDlg* Dialog = new CDormitoryManagerDlg(this);
		// 设置父窗口为该窗口的桌面
		Dialog->Create(IDD_DORMITORYMANAGER_DIALOG, GetDesktopWindow());    //非模态IDD_STUDENT_INTERFACE_DIALOG
		Dialog->ShowWindow(SW_SHOW);

	}

}


BOOL CStudentModifyPasswordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	font.CreatePointFont(200, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_STUDENT_MODIFY_PASSWORD_STATIC)->SetFont(&font);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
