#pragma once


// Ajouter_Activitée dialog

class Ajouter_Activitée : public CDialogEx
{
	DECLARE_DYNAMIC(Ajouter_Activitée)

public:
	Ajouter_Activitée(CWnd* pParent = NULL);   // standard constructor
	virtual ~Ajouter_Activitée();

// Dialog Data
	enum { IDD = IDD_ACTIVITEE_AJOUTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
