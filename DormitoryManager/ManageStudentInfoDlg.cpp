// ManageStudentInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "ManageStudentInfoDlg.h"

//#define IDC_ADD_DORMITORY_HALL_EDIT     1020
//#define IDC_ADD_CLASS_EDIT              1021
//#define IDC_ADD_SEX_EDIT                1022
//#define IDC_ADD_NAME_EDIT               1023
//#define IDC_ADD_MAJORITY_EDIT           1024
//#define IDC_ADD_DORM_NUM_EDIT           1025
//#define IDC_ADD_PHONE_NUMBER_EDIT       1026
//#define IDC_STUDENT_NUMBER_EDIT         1027

//m_StudentNumberEdit;
//m_StudentNameEdit;
//m_StudentSexEdit;
//m_StudentMajorityEdit;
//m_StudentClassEdit;
//m_StudentDormNumEdit;
//m_StudentDormHallEdit;
//m_StudentPhoneNumberEdit;
// CManageStudentInfoDlg 对话框

IMPLEMENT_DYNAMIC(CManageStudentInfoDlg, CDialogEx)

CManageStudentInfoDlg::CManageStudentInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGE_STUDENT_INFO_DIALOG, pParent)
	, m_studentID(_T(""))
	, _name(_T(""))
	, m_sex(_T(""))
	, m_major(_T(""))
	, m_stuclass(_T(""))
	, m_dormitoryNumber(_T(""))
	, m_dormBuilding(_T(""))
	, m_phone(_T(""))
	, md_studentID(_T(""))
	, up_studentID(_T(""))
	, up_name(_T(""))
	, up_sex(_T(""))
	, up_major(_T(""))
	, up_class(_T(""))
	, up_dormNumber(_T(""))
	, up_dormBuilding(_T(""))
	, up_phone(_T(""))
{
	CEdit* edit1;

	/*edit1 = (CEdit*)GetDlgItem(IDC_STUDENT_NUMBER_EDIT);
	edit1->GetWindowText(m_StudentNumberEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_NAME_EDIT);
	edit1->GetWindowText(m_StudentNameEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_SEX_EDIT);
	edit1->GetWindowText(m_StudentSexEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_MAJORITY_EDIT);
	edit1->GetWindowText(m_StudentMajorityEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_CLASS_EDIT);
	edit1->GetWindowText(m_StudentClassEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_DORM_NUM_EDIT);
	edit1->GetWindowText(m_StudentDormNumEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_DORMITORY_HALL_EDIT);
	edit1->GetWindowText(m_StudentDormHallEdit);

	edit1 = (CEdit*)GetDlgItem(IDC_ADD_PHONE_NUMBER_EDIT);
	edit1->GetWindowText(m_StudentPhoneNumberEdit);


	edit1 = (CEdit*)GetDlgItem(IDC_STUDENT_NUMBER_EDIT);
	edit1->GetWindowText(m_DeleteStudentNumber);*/
	

}

CManageStudentInfoDlg::~CManageStudentInfoDlg()
{
}

void CManageStudentInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_ADD_NUMBER_EDIT, m_StudentNumberEdit);
	DDX_Control(pDX, IDC_ADD_NAME_EDIT, m_StudentNameEdit);
	DDX_Control(pDX, IDC_ADD_SEX_EDIT, m_StudentSexEdit);
	DDX_Control(pDX, IDC_ADD_MAJORITY_EDIT, m_StudentMajorityEdit);
	DDX_Control(pDX, IDC_ADD_CLASS_EDIT, m_StudentClassEdit);
	DDX_Control(pDX, IDC_ADD_DORM_NUM_EDIT, m_StudentDormNumEdit);
	DDX_Control(pDX, IDC_ADD_DORMITORY_HALL_EDIT, m_StudentDormHallEdit);

	DDX_Control(pDX, IDC_ADD_PHONE_NUMBER_EDIT, m_StudentPhoneNumberEdit);*/
	DDX_Text(pDX, IDC_ADD_NUMBER_EDIT, m_studentID);
	DDX_Text(pDX, IDC_ADD_NAME_EDIT, _name);
	DDX_Text(pDX, IDC_ADD_SEX_EDIT, m_sex);
	DDX_Text(pDX, IDC_ADD_MAJORITY_EDIT, m_major);
	DDX_Text(pDX, IDC_ADD_CLASS_EDIT, m_stuclass);
	DDX_Text(pDX, IDC_ADD_DORM_NUM_EDIT, m_dormitoryNumber);
	DDX_Text(pDX, IDC_ADD_DORMITORY_HALL_EDIT, m_dormBuilding);
	DDX_Text(pDX, IDC_ADD_PHONE_NUMBER_EDIT, m_phone);
	DDX_Text(pDX, IDC_STUDENT_NUMBER_EDIT, md_studentID);
	DDX_Text(pDX, IDC_ADD_NUMBER_EDIT2, up_studentID);
	DDX_Text(pDX, IDC_ADD_NAME_EDIT2, up_name);
	DDX_Text(pDX, IDC_ADD_SEX_EDIT2, up_sex);
	DDX_Text(pDX, IDC_ADD_MAJORITY_EDIT2, up_major);
	DDX_Text(pDX, IDC_ADD_CLASS_EDIT2, up_class);
	DDX_Text(pDX, IDC_ADD_DORM_NUM_EDIT2, up_dormNumber);
	DDX_Text(pDX, IDC_ADD_DORMITORY_HALL_EDIT2, up_dormBuilding);
	DDX_Text(pDX, IDC_ADD_PHONE_NUMBER_EDIT2, up_phone);
}


BEGIN_MESSAGE_MAP(CManageStudentInfoDlg, CDialogEx)
	ON_BN_CLICKED(ID_ADD_STUDENT_BUTTON, &CManageStudentInfoDlg::OnBnClickedAddStudentButton)
	ON_BN_CLICKED(ID_RESET_STUDENT_BUTTON, &CManageStudentInfoDlg::OnBnClickedResetStudentButton)
	ON_BN_CLICKED(IDC_DELETE_STUDENT_BUTTON, &CManageStudentInfoDlg::OnBnClickedDeleteStudentButton)
	ON_BN_CLICKED(IDC_BUTTON1, &CManageStudentInfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(ID_RESET_STUDENT_BUTTON3, &CManageStudentInfoDlg::OnBnClickedResetStudentButton3)
	ON_BN_CLICKED(ID_RESET_STUDENT_BUTTON2, &CManageStudentInfoDlg::OnBnClickedResetStudentButton2)
END_MESSAGE_MAP()


// CManageStudentInfoDlg 消息处理程序





void CManageStudentInfoDlg::OnBnClickedResetStudentButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_ADD_NUMBER_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_DORMITORY_HALL_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_CLASS_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_SEX_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_NAME_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_MAJORITY_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_DORM_NUM_EDIT)->SetWindowText("");
	GetDlgItem(IDC_ADD_PHONE_NUMBER_EDIT)->SetWindowText("");
	
}





BOOL CManageStudentInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	font1.CreatePointFont(180, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_ADD_INFO_STATIC)->SetFont(&font1);


	font2.CreatePointFont(180, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_DELETE_STUDENT_STATIC)->SetFont(&font2);

	font3.CreatePointFont(180, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_ADD_INFO_STATIC2)->SetFont(&font2);
	 // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE

	SQL.ConnectMysql();
	return TRUE;
}

void CManageStudentInfoDlg::OnBnClickedAddStudentButton()  //该函数所需各种数据都已定义为类成员，且已在构造函数中初始化(注释掉了)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_studentID == TEXT("") || _name == TEXT("") || m_sex == TEXT("") ||
		m_major == TEXT("") || m_stuclass == TEXT("") || m_dormitoryNumber == TEXT("") ||
		m_dormBuilding == TEXT("") || m_phone == TEXT(""))
	{
		MessageBox(TEXT("您的输入的信息有为空！请重新输入！"), TEXT("提示"));
		return;
	}

	Student_Info Info1(m_studentID.GetBuffer(), _name.GetBuffer(), m_sex.GetBuffer(),
		m_major.GetBuffer(), m_stuclass.GetBuffer(), m_dormitoryNumber.GetBuffer(), m_dormBuilding.GetBuffer(), m_phone.GetBuffer());

	if (SQL.Add_Stu_info(Info1))
	{
		MessageBox(TEXT("您已添加成功！"), TEXT("提示"));
	}

}


void CManageStudentInfoDlg::OnBnClickedDeleteStudentButton()  //该函数所需数据已定义为类成员，且已在构造函数中初始化(注释掉了)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (md_studentID == TEXT(""))
	{
		MessageBox(TEXT("您的输入的信息为空！请重新输入！"), TEXT("提示"));
		return;
	}
	if (SQL.Delet_Stu_info(md_studentID.GetBuffer()))
	{
		MessageBox(TEXT("您已删除成功！"), TEXT("提示"));
	}

}

void CManageStudentInfoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (up_studentID == TEXT(""))
	{
		MessageBox(TEXT("请输入您要修改的学生学号！"), TEXT("提示"));
		return;
	}
	vector<Student_Info> upInfo = SQL.Search_StuID_info(up_studentID);
	if (upInfo.empty()) {
		MessageBox(TEXT("查无此人！请重新输入！"), TEXT("提示"));
		return;
	}
	for (int i = 0; i < upInfo.size(); i++) {
		GetDlgItem(IDC_ADD_NAME_EDIT2)->SetWindowTextA(upInfo[i]._name.c_str());
		GetDlgItem(IDC_ADD_SEX_EDIT2)->SetWindowTextA(upInfo[i]._sex.c_str());
		GetDlgItem(IDC_ADD_MAJORITY_EDIT2)->SetWindowTextA(upInfo[i]._major.c_str());
		GetDlgItem(IDC_ADD_CLASS_EDIT2)->SetWindowTextA(upInfo[i]._stuclass.c_str());
		GetDlgItem(IDC_ADD_DORM_NUM_EDIT2)->SetWindowTextA(upInfo[i]._dormitoryNumber.c_str());
		GetDlgItem(IDC_ADD_DORMITORY_HALL_EDIT2)->SetWindowTextA(upInfo[i]._dormBuilding.c_str());
		GetDlgItem(IDC_ADD_PHONE_NUMBER_EDIT2)->SetWindowTextA(upInfo[i]._phone.c_str());
	}
	MessageBox(TEXT("您已查找成功！"), TEXT("提示"));

}


void CManageStudentInfoDlg::OnBnClickedResetStudentButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_ADD_NUMBER_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_DORMITORY_HALL_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_CLASS_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_SEX_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_NAME_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_MAJORITY_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_DORM_NUM_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_ADD_PHONE_NUMBER_EDIT2)->SetWindowText("");
}


void CManageStudentInfoDlg::OnBnClickedResetStudentButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (up_studentID == TEXT("")|| up_name == TEXT("") || up_sex == TEXT("")
		|| up_major == TEXT("") || up_class == TEXT("") || up_dormNumber == TEXT("") ||
		up_dormBuilding == TEXT("") || up_phone == TEXT("")  )
	{
		MessageBox(TEXT("您要修改的信息不能为空！"), TEXT("提示"));
		return;
	}

	Student_Info upInfo(up_studentID.GetBuffer(), up_name.GetBuffer(), up_sex.GetBuffer(),
		up_major.GetBuffer(), up_class.GetBuffer(), up_dormNumber.GetBuffer(),
		up_dormBuilding.GetBuffer(), up_phone.GetBuffer());

	if (SQL.Update_Stu_info(upInfo))
	{
		MessageBox(TEXT("您已修改成功！"), TEXT("提示"));
	}

}


