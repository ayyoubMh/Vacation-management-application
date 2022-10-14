#pragma once


// Ajouter_Village dialog

class Ajouter_Village : public CDialogEx
{
	DECLARE_DYNAMIC(Ajouter_Village)

public:
	Ajouter_Village(CWnd* pParent = NULL);   // standard constructor
	virtual ~Ajouter_Village();

// Dialog Data
	enum { IDD = IDD_VILLAGE_AJOUTER};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
