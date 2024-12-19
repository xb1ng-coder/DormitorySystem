#pragma once
#include "afxdialogex.h"
#include "SQLinterface.h"
#include"common.h"

// CModifyPasswordDlg 对话框

class CModifyPasswordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyPasswordDlg)

public:
	CModifyPasswordDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CModifyPasswordDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODIFY_PASSWORD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_OldPasswordEdit;
	CString m_NewPasswordEdit;
	CFont font;
	afx_msg void OnBnClickedModifyPasswordButton();
	virtual BOOL OnInitDialog();

	CString oldpassword;
	CString newpassword;
	SQLinterface SQL;
	afx_msg LRESULT OnReturn(WPARAM parameter1,LPARAM parameter2);
};
