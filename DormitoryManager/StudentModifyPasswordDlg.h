#pragma once
#include "afxdialogex.h"
#include "SQLinterface.h"


// CStudentModifyPasswordDlg 对话框

class CStudentModifyPasswordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentModifyPasswordDlg)

public:
	CStudentModifyPasswordDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStudentModifyPasswordDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_MODIFY_PASSWORD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CFont font;
	afx_msg void OnBnClickedStudentModifyPasswordButton();
	
	virtual BOOL OnInitDialog();
	CString oldpassword;
	CString newpassword;
	SQLinterface SQL;
};
