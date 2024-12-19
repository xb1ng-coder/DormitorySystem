
// DormitoryManagerDlg.h: 头文件
//
#include"Resource.h"
#include"ManagerDlg.h"
#include "SQLinterface.h"
#pragma once


// CDormitoryManagerDlg 对话框
class CDormitoryManagerDlg : public CDialogEx
{
// 构造
public:
	CDormitoryManagerDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DORMITORYMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CFont font;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoginButton();
	afx_msg void OnBnClickedResetButton();
	SQLinterface SQL;
	vector<Student_Login>StuInfo;
	vector<Dorm_Master>DormInfo;
	CStatic m_MainDlg;
	afx_msg void OnClose();
};

