#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Chercher_Pays dialog

class Chercher_Pays : public CDialogEx
{
	DECLARE_DYNAMIC(Chercher_Pays)

public:
	Chercher_Pays(CWnd* pParent = NULL);   // standard constructor
	virtual ~Chercher_Pays();

// Dialog Data
	enum { IDD = IDD_CHERCHER_PAYS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CEdit code_Pays;
//	afx_msg void OnBnClickedChercherPays();
	CListCtrl m_list_pays;
	afx_msg void OnEnChangeCodePays();
	CString code_Pays;
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedMfcbutton2();
};
