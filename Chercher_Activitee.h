#pragma once
#include "afxcmn.h"


// Chercher_Activitee dialog

class Chercher_Activitee : public CDialogEx
{
	DECLARE_DYNAMIC(Chercher_Activitee)

public:
	Chercher_Activitee(CWnd* pParent = NULL);   // standard constructor
	virtual ~Chercher_Activitee();

// Dialog Data
	enum { IDD = IDD_CHERCHER_ACTIVITEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_activite;
	afx_msg void OnBnClickedChercherActivite();
	CString code_Activite;
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedChercherActivite2();
};
