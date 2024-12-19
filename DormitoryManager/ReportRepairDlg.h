#pragma once
#include "afxdialogex.h"
#include"QueryStudentInfoDlg.h"
#include"Live_Login.h"

// CReportRepairDlg 对话框

class CReportRepairDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CReportRepairDlg)

public:
	CReportRepairDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CReportRepairDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REPORT_REPAIR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_StudentRepairInfoList;
	afx_msg void OnBnClickedReportRepairButton();
	virtual BOOL OnInitDialog();

	SQLinterface SQL;
	vector<Repair_Info>Info;
	CString m_dormBuilding;
	CString m_dorimitoryNumber;
	CString m_question;
	CString m_repair_time;

	void Updata_List();
};
