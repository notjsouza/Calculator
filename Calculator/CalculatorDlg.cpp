
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "CMenuDlg.h"

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


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, num1("0")
	, num2("0")
	, m_calc(0)
	, m_result("0")
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM1, num1);
	DDX_Text(pDX, IDC_NUM2, num2);
	DDX_Radio(pDX, IDC_RADIO_ADDITION, m_calc);
	DDX_Text(pDX, IDC_RESULT, m_result);
	DDX_Control(pDX, IDC_CALCULATE, m_calculate);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULATE, &CCalculatorDlg::OnBnClickedCalculate)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CStatic* pPicture1 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_PICTURE1));
	pPicture1->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture1->SetBitmap(hb);

	CStatic* pPicture2 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_PICTURE2));
	pPicture2->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb1 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture2->SetBitmap(hb1);

	CStatic* pPicture3 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_PICTURE3));
	pPicture3->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb2 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture3->SetBitmap(hb2);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedCalculate()
{

	/*
		RADIO BUTTON CONTROLS
	*/

	CButton* pRadio1 = reinterpret_cast<CButton*>(GetDlgItem(IDC_RADIO_ADDITION));
	int radio1 = pRadio1->GetCheck();

	CButton* pRadio2 = reinterpret_cast<CButton*>(GetDlgItem(IDC_RADIO_SUBTRACTION));
	int radio2 = pRadio2->GetCheck();

	CButton* pRadio3 = reinterpret_cast<CButton*>(GetDlgItem(IDC_RADIO_MULTIPICATION));
	int radio3 = pRadio3->GetCheck();

	CButton* pRadio4 = reinterpret_cast<CButton*>(GetDlgItem(IDC_RADIO_DIVISION));
	int radio4 = pRadio4->GetCheck();

	/*
		EDIT CONTROLS
	*/

	CString mNum1;
	CEdit* pNum1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_NUM1));
	pNum1->GetWindowText(mNum1);

	CString mNum2;
	CEdit* pNum2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_NUM2));
	pNum2->GetWindowText(mNum2);

	double fNum1 = _ttof(mNum1);
	double fNum2 = _ttof(mNum2);

	double output = 0;

	if (radio1 == BST_CHECKED) {

		output = fNum1 + fNum2;

	} else if (radio2 == BST_CHECKED) {
	
		output = fNum1 - fNum2;
	
	} else if (radio3 == BST_CHECKED) {
	
		output = fNum1 * fNum2;
	
	} else if (radio4 == BST_CHECKED) {
	
		output = fNum1 / fNum2;
	
	}

	m_result.Format(_T("%f"), output);

	UpdateData(FALSE);

}
