#pragma once


// Modifier_Activitée dialog

class Modifier_Activitée : public CDialogEx
{
	DECLARE_DYNAMIC(Modifier_Activitée)

public:
	Modifier_Activitée(CWnd* pParent = NULL);   // standard constructor
	virtual ~Modifier_Activitée();

// Dialog Data
	enum { IDD = IDD_ACTIVITEE_MODIFIER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
