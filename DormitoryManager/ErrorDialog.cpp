// ErrorDialog.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "ErrorDialog.h"


// CErrorDialog 对话框

IMPLEMENT_DYNAMIC(CErrorDialog, CDialogEx)

CErrorDialog::CErrorDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_ERROR_DIALOG, pParent)
{

}

CErrorDialog::~CErrorDialog()
{
}

void CErrorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CErrorDialog, CDialogEx)
	ON_BN_CLICKED(ID_LOGIN_ERROR_OK, &CErrorDialog::OnBnClickedLoginErrorOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CErrorDialog 消息处理程序


void CErrorDialog::OnBnClickedLoginErrorOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (IsWindowVisible())  //当前主对话框是否是显示状态
	{
		//窗口不显示
		ShowWindow(SW_HIDE);
	}

}


void CErrorDialog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}
