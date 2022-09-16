// CMenuDlg.cpp : implementation file
//

#include "pch.h"
#include "Calculator.h"
#include "CMenuDlg.h"
#include "afxdialogex.h"


// CMenuDlg dialog

IMPLEMENT_DYNAMIC(CMenuDlg, CDialog)

CMenuDlg::CMenuDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CALCULATOR_DIALOG, pParent)
{

}

CMenuDlg::~CMenuDlg()
{
}

void CMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMenuDlg, CDialog)
END_MESSAGE_MAP()


// CMenuDlg message handlers


