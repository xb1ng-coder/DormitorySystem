#pragma once
#include "afxdialogex.h"
#include"DormMemberDlg.h"
#include"ReportRepairDlg.h"
#include"StudentModifyPasswordDlg.h"
#include"common.h"



// CStudentDlg 对话框

class CStudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentDlg)

public:
	CStudentDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStudentDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_INTERFACE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	int m_CurSelTab;
	CDormMemberDlg DormMemberDlg;
	CReportRepairDlg ReportRepairDlg;
	CStudentModifyPasswordDlg StudentModifyPasswordDlg;
	
	CDialog* pDialog[3];

	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT CloseStudentDlg(WPARAM parameter1, LPARAM parameter2);
};
