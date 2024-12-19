
// DormitoryManagerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DormitoryManager.h"
#include "DormitoryManagerDlg.h"
#include "afxdialogex.h"
#include"ErrorDialog.h"
#include"StudentDlg.h"
#include "Live_Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDormitoryManagerDlg 对话框



CDormitoryManagerDlg::CDormitoryManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DORMITORYMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CDormitoryManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_HEADING_STATIC, m_MainDlg);
}

BEGIN_MESSAGE_MAP(CDormitoryManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN_BUTTON, &CDormitoryManagerDlg::OnBnClickedLoginButton)
	ON_BN_CLICKED(IDC_RESET_BUTTON, &CDormitoryManagerDlg::OnBnClickedResetButton)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDormitoryManagerDlg 消息处理程序

BOOL CDormitoryManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	font.CreatePointFont(200, _T("微软雅黑"), NULL);
	GetDlgItem(IDC_HEADING_STATIC)->SetFont(&font);

	SQL.ConnectMysql();//连接数据库

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDormitoryManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}

}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDormitoryManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		//注释该语句：防止重复调用重画函数
		//CDialogEx::OnPaint();

		//添加代码对话框背景贴图
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                                
		CDC   dcBmp;                                         
		dcBmp.CreateCompatibleDC(&dc);                       
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_JETT_BITMAP);           
		BITMAP   m_bitmap;                                   
		bmpBackground.GetBitmap(&m_bitmap);                  
		CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
			m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
		//dc.SetStretchBltMode(COLORONCOLOR);    //解决图片严重失真问题
		
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDormitoryManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDormitoryManagerDlg::OnBnClickedLoginButton()
{

	SQL.ConnectMysql();
	StuInfo = SQL.Get_AllLogin_info();
	DormInfo = SQL.Get_AllMasterLogin_info();
	// TODO: 在此添加控件通知处理程序代码
	CEdit* edit1;
	edit1 = (CEdit*)GetDlgItem(IDC_USER_NAME_EDIT);
	CString v1;
	edit1->GetWindowText(v1);

	CEdit* edit2;
	edit2 = (CEdit*)GetDlgItem(IDC_PASSWORD_EDIT);
	CString v2;
	edit2->GetWindowText(v2);

	// 将用户名和密码存储到全局变量中
	Global::L_Username = CT2A(v1);
	Global::L_Password = CT2A(v2);

	for (int i = 0; i < StuInfo.size(); i++) {
		if (StuInfo[i]._account == Global::L_Username && StuInfo[i]._password == Global::L_Password) {
			

		/*	CDialogEx::OnOK();*/
			
			//CStudentDlg* Dialog = new CStudentDlg(this);
			//// 设置父窗口为该窗口的桌面
			//Dialog->Create(IDD_STUDENT_INTERFACE_DIALOG, GetDesktopWindow());    //非模态IDD_STUDENT_INTERFACE_DIALOG
			//Dialog->ShowWindow(SW_SHOW);
			
			CDialogEx::OnOK();
			CStudentDlg dlg;
			dlg.DoModal();

			
			return;
		}
	}
	for (int i = 0; i < DormInfo.size(); i++) {
	    if (DormInfo[i]._account == Global::L_Username && DormInfo[i]._password == Global::L_Password) {
			

			/*CDialogEx::OnOK();*/
			
		    //CManagerDlg* Dialog = new CManagerDlg(this);
		    //// 设置父窗口为该窗口的桌面
		    //Dialog->Create(IDD_MANAGER_DIALOG, GetDesktopWindow());    //非模态
		    //Dialog->ShowWindow(SW_SHOW);
			
			CDialogEx::OnOK();
			CManagerDlg dlg;
			dlg.DoModal();
			
		    return;
	    }
    }  
	 AfxMessageBox(_T("登录失败！请重新输入账号密码！"));
	
	//if (v1 == "宿管员" && v2 == "123123")
	//{
	//	CManagerDlg* Dialog = new CManagerDlg(this);
	//	// 设置父窗口为该窗口的桌面
	//	Dialog->Create(IDD_MANAGER_DIALOG, GetDesktopWindow());    //非模态
	//	Dialog->ShowWindow(SW_SHOW);
	//}
	//else if(v1 == "S001" && v2 == "111111")
	//{
	//	CStudentDlg* Dialog = new CStudentDlg(this);
	//	// 设置父窗口为该窗口的桌面
	//	Dialog->Create(IDD_STUDENT_INTERFACE_DIALOG, GetDesktopWindow());    //非模态
	//	Dialog->ShowWindow(SW_SHOW);
	//}
	//else
	//{

	//	::MessageBox(NULL, "登录失败，请重新登录！", "消息", NULL);
	//	///*CErrorDialog Object;
	//	//Object.DoModal();*/    //模态
	//	////动态窗口  
	//	//CErrorDialog* Dialog = new CErrorDialog(this);
	//	//// 设置父窗口为该窗口的桌面
	//	//Dialog->Create(IDD_LOGIN_ERROR_DIALOG, GetDesktopWindow());    //非模态
	//	//Dialog->ShowWindow(SW_SHOW);
	//}

}


void CDormitoryManagerDlg::OnBnClickedResetButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_USER_NAME_EDIT)->SetWindowText("");
	GetDlgItem(IDC_PASSWORD_EDIT)->SetWindowText("");
}


void CDormitoryManagerDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//EndDialog(0);
	ExitProcess(0);
	CDialogEx::OnClose();
}
