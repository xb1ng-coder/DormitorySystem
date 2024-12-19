#pragma once
#include "afxdialogex.h"
#include"QueryStudentInfoDlg.h"
#include "SQLinterface.h"

// CDormMemberDlg 对话框

class CDormMemberDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDormMemberDlg)

public:
	CDormMemberDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDormMemberDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DORM_MEMBER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_DormMemberInfoList;
	virtual BOOL OnInitDialog();

	SQLinterface SQL;
	vector<Student_Info>Info;
};
