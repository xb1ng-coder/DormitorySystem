#pragma once
#include "afxdialogex.h"


// CMonitorDlg 对话框

class CMonitorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMonitorDlg)

public:
	CMonitorDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMonitorDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DORM_MONITOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
