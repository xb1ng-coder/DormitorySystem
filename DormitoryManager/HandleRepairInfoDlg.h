#pragma once
#include "afxdialogex.h"
#include"QueryStudentInfoDlg.h"




// CHandleRepairInfoDlg 对话框

class CHandleRepairInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHandleRepairInfoDlg)

public:
	CHandleRepairInfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHandleRepairInfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HANDLE_REPAIR_INFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_RepairInfoList;
	virtual BOOL OnInitDialog();
	CString m_HandleNumberEdit;
	CString m_HandleStatusEdit;
	CFont font;

	SQLinterface SQL;
	vector<Repair_Info>Info;
	CString m_repairNumber;
	afx_msg void OnBnClickedHandleButton2();
	afx_msg void OnBnClickedHandleDeletButton();

	void UpdateList();

};
