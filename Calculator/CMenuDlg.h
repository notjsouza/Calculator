#pragma once


// CMenuDlg dialog

class CMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(CMenuDlg)

public:
	CMenuDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMenuDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
