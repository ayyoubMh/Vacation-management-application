#pragma once


// Ajouter_Activit�e dialog

class Ajouter_Activit�e : public CDialogEx
{
	DECLARE_DYNAMIC(Ajouter_Activit�e)

public:
	Ajouter_Activit�e(CWnd* pParent = NULL);   // standard constructor
	virtual ~Ajouter_Activit�e();

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
