#pragma once
#include "afxdialogex.h"
#include "HandleRepairInfoDlg.h"
#include"QueryStudentInfoDlg.h"
#include "SQLinterface.h"



// CManageStudentAccountDlg 对话框

class CManageStudentAccountDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManageStudentAccountDlg)

public:
	CManageStudentAccountDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CManageStudentAccountDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGE_STUDENT_ACCOUNT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_StudentAccountList;
	CString m_StudentAccountEdit;
	CString m_StudentPasswordEdit;
	afx_msg void OnBnClickedAddAccountButton();
	afx_msg void OnBnClickedDeleteAccountButton();
	virtual BOOL OnInitDialog();
	CFont font;

	SQLinterface SQL;
	vector<Student_Login>Info;
	CString m_account;
	CString m_password;

	void UpdateList();
};
