
// StrategyPatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StrategyPattern.h"
#include "StrategyPatternDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CStrategyPatternDlg dialog



CStrategyPatternDlg::CStrategyPatternDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STRATEGYPATTERN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStrategyPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStrategyPatternDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STRATEGY_PATTERN, &CStrategyPatternDlg::OnBnClickedBtnStrategyPattern)
END_MESSAGE_MAP()


// CStrategyPatternDlg message handlers

BOOL CStrategyPatternDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStrategyPatternDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStrategyPatternDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStrategyPatternDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStrategyPatternDlg::OnBnClickedBtnStrategyPattern()
{
	//------ ��{design pattern ���� Strategy Pattern(�����Ҧ�)
	//       Strategy Pattern�O�t�~�@�ظѨM��k�����

	//------ "Head First Design pattern"���Ѥ������Ҧ����w�q�O
	//       �w�q�F�t��k�a�ڡA�ӧO�ʸ˰_�ӡA���L�̤��e�i�H���۴����A���Ҧ����t��k���ܰʿW�ߩ�ϥξާ@�����󤧥~
	
	//------ �����Ҧ���h: 
	//       1. �N�ܰʳ����ʸ˰_�� 2. �w�虜���g�{���A���O�w����g�{�� 3. �h�ΦX���A�֥��~��
	//       �]�N�O���A���Ҽ{����| "�ݭn���վ㲧�ʪ�����" �A�N����������W�ߥX�ӫإ����O�A
	//
	//------ reference: https://dotblogs.com.tw/joysdw12/2013/03/07/95769
	//       reference: http://monkeycoding.com/?p=958

	//----- Initial ...
	CString          Msg_cstr = _T("");
	
	Attack_Type_CS   *Attack_Type1_pr = new Attack_Normal_CS();   // decide what kind of attach need to implement
	Attack_Type_CS   *Attack_Type2_pr = new Attack_Magic_CS();
	Fly_Type_CS      *Fly_Type1_pr = new Fly_Nowing_CS();         // decide what kind of fly need to implement
	Fly_Type_CS      *Fly_Type2_pr = new Fly_Wing_CS();

	Warrior_CS       Warrior_cs(Attack_Type1_pr, Fly_Type1_pr);
	DragonRidor_CS   DragonRidor_cs(Attack_Type2_pr, Fly_Type2_pr);

	//-----------------------------------------
	MessageBox(_T("Initial Warrior setting"));
	Warrior_cs.Attack_Fn();
	Warrior_cs.Fly_Fn();

	MessageBox(_T("New Warrior setting"));
	Warrior_cs.Set_Attack_Type_Fn(Attack_Type2_pr);
	Warrior_cs.Set_Fly_Type_Fn(Fly_Type2_pr);
	Warrior_cs.Attack_Fn();
	Warrior_cs.Fly_Fn();


	MessageBox(_T("Initial DragonRidor setting"));
	DragonRidor_cs.Attack_Fn();
	DragonRidor_cs.Fly_Fn();

	MessageBox(_T("New DragonRidor setting"));
	DragonRidor_cs.Set_Attack_Type_Fn(Attack_Type1_pr);
	DragonRidor_cs.Set_Fly_Type_Fn(Fly_Type1_pr);
	DragonRidor_cs.Attack_Fn();
	DragonRidor_cs.Fly_Fn();


	delete Attack_Type1_pr;
	delete Attack_Type2_pr;
	delete Fly_Type1_pr;
	delete Fly_Type2_pr;
}
