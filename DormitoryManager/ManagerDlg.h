#pragma once
#include "afxdialogex.h"
#include"QueryStudentInfoDlg.h"
#include"ManageStudentInfoDlg.h"
#include"HandleRepairInfoDlg.h"
#include"ManageStudentAccountDlg.h"
#include"ModifyPasswordDlg.h"


// CManagerDlg 对话框

class CManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerDlg)

public:
	CManagerDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CManagerDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGER_DIALOG };
#endif

	



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	int m_CurSelTab;
	CQueryStudentInfoDlg QueryInfoDlg;
	CManageStudentInfoDlg ManageStudentInfoDlg;
	CHandleRepairInfoDlg HandleRepairInfoDlg;
	CManageStudentAccountDlg ManageAccountDlg;
	CModifyPasswordDlg ModifyPasswordDlg;
	CDialog* pDialog[5];






	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeManagerTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT CloseManagerDlg(WPARAM parameter1, LPARAM parameter2);
	//afx_msg void OnClose();
};
