// HandleRepairInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "DormitoryManager.h"
#include "afxdialogex.h"
#include "HandleRepairInfoDlg.h"
//COLUMN_DATA RepairInfo[] =
//{
//	{ "报修编号",			60 },
//	{ "寝楼",			160 },
//	{ "宿舍号",	60 },
//	{ "时间",		160 },
//	{ "问题",			150 },
//	{ "状况",		130 }
//};

// CHandleRepairInfoDlg 对话框

IMPLEMENT_DYNAMIC(CHandleRepairInfoDlg, CDialogEx)

CHandleRepairInfoDlg::CHandleRepairInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HANDLE_REPAIR_INFO_DIALOG, pParent)
	, m_HandleNumberEdit(_T(""))
	, m_HandleStatusEdit(_T(""))
	, m_repairNumber(_T(""))
{

}

CHandleRepairInfoDlg::~CHandleRepairInfoDlg()
{
}

void CHandleRepairInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HANDLE_REPAIR_INFO_LIST, m_RepairInfoList);

	DDX_Text(pDX, IDC_HANDLE_NUMBER_EDIT, m_repairNumber);
}


BEGIN_MESSAGE_MAP(CHandleRepairInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_HANDLE_BUTTON2, &CHandleRepairInfoDlg::OnBnClickedHandleButton2)
	ON_BN_CLICKED(IDC_HANDLE_DELET_BUTTON, &CHandleRepairInfoDlg::OnBnClickedHandleDeletButton)
	
END_MESSAGE_MAP()


// CHandleRepairInfoDlg 消息处理程序


BOOL CHandleRepairInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/*for (int i = 0; i < sizeof(RepairInfo) / sizeof(COLUMN_DATA); i++)
	{
		m_RepairInfoList.InsertColumn(i, RepairInfo[i].TitleData, LVCFMT_CENTER, RepairInfo[i].TitleWidth);
	}
	m_RepairInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT);*/

	font.CreatePointFont(200, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_HANDLE_REPAIR_STATIC)->SetFont(&font);
	GetDlgItem(IDC_HANDLE_STATIC)->SetFont(&font);

	m_RepairInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_RepairInfoList.InsertColumn(0, _T("报修序号"), LVCFMT_LEFT, 150);	// 插入第1列的列名
	m_RepairInfoList.InsertColumn(1, _T("宿舍楼"), LVCFMT_LEFT, 150);	// 插入第2列的列名
	m_RepairInfoList.InsertColumn(2, _T("宿舍号"), LVCFMT_LEFT, 150);	// 插入第3列的列名
	m_RepairInfoList.InsertColumn(3, _T("报修时间"), LVCFMT_LEFT, 150);	// 插入第4列的列名
	m_RepairInfoList.InsertColumn(4, _T("问题"), LVCFMT_LEFT, 150);	// 插入第5列的列名
	m_RepairInfoList.InsertColumn(5, _T("处理状况"), LVCFMT_LEFT, 150);	// 插入第6列的列名

	//连接数据库
	if (SQL.ConnectMysql()) {
		
		UpdateList();

	}
	else {
		return true;
	};
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CHandleRepairInfoDlg::OnBnClickedHandleButton2()
{

	UpdateData(TRUE);
	CString str;
	GetDlgItem(IDC_COMBO1)->GetWindowText(str);
	if (m_repairNumber == TEXT(""))
	{
		MessageBox(TEXT("您的输入的信息为空！请重新输入！"), TEXT("提示"));
		return;
	}
	if (str == TEXT(""))
	{
		MessageBox(TEXT("请输入对报修状态的更改！"), TEXT("提示"));
		return;
	}
	if (SQL.Update_Repair_info(m_repairNumber.GetBuffer(),str.GetBuffer()))
	{
		MessageBox(TEXT("您已更改成功成功！"), TEXT("提示"));
		UpdateList();
	}
}

void CHandleRepairInfoDlg::OnBnClickedHandleDeletButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_repairNumber == TEXT(""))
	{
		MessageBox(TEXT("您的输入的信息为空！请重新输入！"), TEXT("提示"));
		return;
	}
	if (SQL.Delet_Repair_info(m_repairNumber.GetBuffer()))
	{
		MessageBox(TEXT("您已删除成功！"), TEXT("提示"));
		UpdateList();
	}
}

void CHandleRepairInfoDlg::UpdateList()
{
	Info = SQL.Get_AllRepair_info();
	m_RepairInfoList.DeleteAllItems();
	for (int i = 0; i < Info.size(); i++) {
		m_RepairInfoList.InsertItem(i, _T(""));						// 插入行
		m_RepairInfoList.SetItemText(i, 0, Info[i]._repairNumber.c_str());//插入第一列
		m_RepairInfoList.SetItemText(i, 1, Info[i]._dormBuilding.c_str());		//插入第二列	
		m_RepairInfoList.SetItemText(i, 2, Info[i]._dormitoryNumber.c_str());		//插入第三列		
		m_RepairInfoList.SetItemText(i, 3, Info[i]._repair_time.c_str());	//插入第四列			
		m_RepairInfoList.SetItemText(i, 4, Info[i]._question.c_str());	//插入第五列	
		m_RepairInfoList.SetItemText(i, 5, Info[i]._situation.c_str());	//插入第六列
	}
}

