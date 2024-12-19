#pragma once
#include "afxdialogex.h"
#include "SQLinterface.h"


typedef struct
{
	char* TitleData;          //列表的名称
	int		TitleWidth;            //列表的宽度
}COLUMN_DATA;



// CQueryStudentInfoDlg 对话框

class CQueryStudentInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQueryStudentInfoDlg)

public:
	CQueryStudentInfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CQueryStudentInfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUERY_STUDENT_INFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_StudentInfoList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSearchDormitoryButton();
	CFont font;
	SQLinterface SQL;
	vector<Student_Info>Info;
	CString m_studentID;
	afx_msg void OnBnClickedButton1();
};
