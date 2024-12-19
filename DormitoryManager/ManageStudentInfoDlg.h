#pragma once
#include "afxdialogex.h"
#include"QueryStudentInfoDlg.h"
#include "SQLinterface.h"

// CManageStudentInfoDlg 对话框

class CManageStudentInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManageStudentInfoDlg)

public:
	CManageStudentInfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CManageStudentInfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGE_STUDENT_INFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CFont font1;
	CFont font2;
	CFont font3;
	/*CEdit m_StudentNumberEdit;
	CEdit m_StudentNameEdit;
	CEdit m_StudentSexEdit;
	CEdit m_StudentMajorityEdit;
	CEdit m_StudentClassEdit;
	CEdit m_StudentDormNumEdit;
	CEdit m_StudentDormHallEdit;
	CEdit m_StudentPhoneNumberEdit;*/
	CString m_StudentNumberEdit;
	CString m_StudentNameEdit;
	CString m_StudentSexEdit;
	CString m_StudentMajorityEdit;
	CString m_StudentClassEdit;
	CString m_StudentDormNumEdit;
	CString m_StudentDormHallEdit;
	CString m_StudentPhoneNumberEdit;

	CString m_DeleteStudentNumber;
	afx_msg void OnBnClickedAddStudentButton();
	afx_msg void OnBnClickedResetStudentButton();
	afx_msg void OnBnClickedDeleteStudentButton();
	virtual BOOL OnInitDialog();
	CString m_studentID;
	CString _name;
	CString m_sex;
	CString m_major;
	CString m_stuclass;
	CString m_dormitoryNumber;
	CString m_dormBuilding;
	CString m_phone;

	SQLinterface SQL;
	CString md_studentID;
	afx_msg void OnBnClickedButton1();
	CString up_studentID;
	afx_msg void OnBnClickedResetStudentButton3();
	afx_msg void OnBnClickedResetStudentButton2();
	CString up_name;
	CString up_sex;
	CString up_major;
	CString up_class;
	CString up_dormNumber;
	CString up_dormBuilding;
	CString up_phone;
};
