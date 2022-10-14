#pragma once


// Ajouter_Langue dialog

class Ajouter_Langue : public CDialogEx
{
	DECLARE_DYNAMIC(Ajouter_Langue)

public:
	Ajouter_Langue(CWnd* pParent = NULL);   // standard constructor
	virtual ~Ajouter_Langue();

// Dialog Data
	enum { IDD = IDD_LANGUE_AJOUTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
