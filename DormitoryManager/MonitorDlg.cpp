// MonitorDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "MonitorDlg.h"


// CMonitorDlg 对话框

IMPLEMENT_DYNAMIC(CMonitorDlg, CDialogEx)

CMonitorDlg::CMonitorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DORM_MONITOR_DIALOG, pParent)
{

}

CMonitorDlg::~CMonitorDlg()
{
}

void CMonitorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMonitorDlg, CDialogEx)
END_MESSAGE_MAP()


// CMonitorDlg 消息处理程序
