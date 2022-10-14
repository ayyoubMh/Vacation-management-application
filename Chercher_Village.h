#pragma once
#include "afxcmn.h"


// Chercher_Village dialog

class Chercher_Village : public CDialogEx
{
	DECLARE_DYNAMIC(Chercher_Village)

public:
	Chercher_Village(CWnd* pParent = NULL);   // standard constructor
	virtual ~Chercher_Village();

// Dialog Data
	enum { IDD = IDD_CHERCHER_VILLAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_village;
	afx_msg void OnBnClickedChercherVillage();
	CString code_Village;
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedChercherVillage2();
};
