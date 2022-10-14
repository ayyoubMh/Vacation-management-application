#pragma once


// Supprimmer_Activitée dialog

class Supprimmer_Activitée : public CDialogEx
{
	DECLARE_DYNAMIC(Supprimmer_Activitée)

public:
	Supprimmer_Activitée(CWnd* pParent = NULL);   // standard constructor
	virtual ~Supprimmer_Activitée();

// Dialog Data
	enum { IDD = IDD_ACTIVITEE_SUPPRIMMER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
