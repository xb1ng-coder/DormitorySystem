#pragma once
#include "afxdialogex.h"


// CErrorDialog 对话框

class CErrorDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CErrorDialog)

public:
	CErrorDialog(CWnd* pParent = nullptr);   // 标准构造函数

	virtual ~CErrorDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_ERROR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoginErrorOk();
	afx_msg void OnClose();
};
