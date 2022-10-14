
// Gestion_GarageDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxbutton.h"


// CGestion_GarageDlg dialog
class CGestion_GarageDlg : public CDialogEx
{
// Construction
public:
	CGestion_GarageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GESTION_GARAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	afx_msg void OnClickedCreateDb();
	CListCtrl m_list;
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedContinents();
	afx_msg void OnBnClickedPays();
	afx_msg void OnBnClickedVillages();
	afx_msg void OnBnClickedActivites();
	afx_msg void OnBnClickedLangues();
	afx_msg void OnBnClickedHome();
	afx_msg void OnAjouterUnVillage();
	afx_msg void OnSupprimmerUnVillage();
//	afx_msg void OnModifierVillage();
	afx_msg void OnAjouterUnPays();
	afx_msg void OnModifierUnPays();
	afx_msg void OnModifierVillage();
	afx_msg void OnModifierUnVillage();
	afx_msg void OnSupprimmerUnPays();
	afx_msg void OnAjouterUneActivitee();
	afx_msg void OnModifierUneActivitee();
	afx_msg void OnSupprimmerUneActivitee();
	afx_msg void OnAjouterUneLangue();
	afx_msg void OnModifierUneLangue();
	afx_msg void OnSupprimmerUneLangue();
	afx_msg void OnChercherPays();
	afx_msg void OnChercherVillage();
	afx_msg void OnChercherActivit32810();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CMFCButton Continent;
	CMFCButton Pays;
	CMFCButton Village;
	CMFCButton Activitée;
	CMFCButton Langue;
	CMFCButton DB;
	CMFCButton About;
	CMFCButton Exit;
};
