// ModifyPasswordDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "ModifyPasswordDlg.h"
#include"DormitoryManagerDlg.h"
#include "Live_Login.h"
using namespace std;


// CModifyPasswordDlg 对话框

IMPLEMENT_DYNAMIC(CModifyPasswordDlg, CDialogEx)

CModifyPasswordDlg::CModifyPasswordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODIFY_PASSWORD_DIALOG, pParent)
	, m_OldPasswordEdit(_T(""))
	, m_NewPasswordEdit(_T(""))
	, oldpassword(_T(""))
	, newpassword(_T(""))
{

}

CModifyPasswordDlg::~CModifyPasswordDlg()
{
}

void CModifyPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	

	DDX_Text(pDX, IDC_OLD_PASSWORD_EDIT, oldpassword);
	DDX_Text(pDX, IDC_NEW_PASSWORD_EDIT, newpassword);
}


BEGIN_MESSAGE_MAP(CModifyPasswordDlg, CDialogEx)
	ON_BN_CLICKED(ID_MODIFY_PASSWORD_BUTTON, &CModifyPasswordDlg::OnBnClickedModifyPasswordButton)
	ON_MESSAGE(UM_ON_RETURN, OnReturn)
END_MESSAGE_MAP()


// CModifyPasswordDlg 消息处理程序


void CModifyPasswordDlg::OnBnClickedModifyPasswordButton()
{
	// TODO: 在此添加控件通知处理程序代码


	SQL.ConnectMysql();

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if (oldpassword.GetBuffer() != Global::L_Password) {
		MessageBox(TEXT("您的输入的原密码错误！请重新输入！"), TEXT("提示"));
		return;
	}
	else if (SQL.Update_Dorm_Login(Global::L_Username.c_str(), newpassword))
	{
		MessageBox(TEXT("您已修改成功！请重新登录！"), TEXT("提示"));


		HWND v1 = ::FindWindow(NULL, _T("宿管员界面"));
		::SendMessage(v1, UM_CLOSE_MANAGER_DLG, 0, 0);

		//CDormitoryManagerDlg* Dialog = new CDormitoryManagerDlg(this);
		//// 设置父窗口为该窗口的桌面
		//Dialog->Create(IDD_DORMITORYMANAGER_DIALOG, GetDesktopWindow());    //非模态IDD_STUDENT_INTERFACE_DIALOG
		//Dialog->ShowWindow(SW_SHOW);

		CDormitoryManagerDlg Object;
		Object.DoModal();
		

	}
	
	//DestroyWindow();
	//PostQuitMessage(0);
	//CDormitoryManagerDlg* Dialog = new CDormitoryManagerDlg(this);
	//// 设置父窗口为该窗口的桌面
	//Dialog->Create(IDD_DORMITORYMANAGER_DIALOG, GetDesktopWindow());    //非模态
	//Dialog->ShowWindow(SW_SHOW);
}


BOOL CModifyPasswordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	font.CreatePointFont(200, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_MODIFY_PASSWORD_STATIC)->SetFont(&font);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CModifyPasswordDlg::OnReturn(WPARAM parameter1,LPARAM parameter2)
{
	
	CDormitoryManagerDlg* Dialog = new CDormitoryManagerDlg(this);
	// 设置父窗口为该窗口的桌面
	Dialog->Create(IDD_DORMITORYMANAGER_DIALOG, GetDesktopWindow());    //非模态IDD_STUDENT_INTERFACE_DIALOG
	Dialog->ShowWindow(SW_SHOW);



	
	
	return 0;
}
