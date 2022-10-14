#pragma once


// Ajouter_Pays dialog

class Ajouter_Pays : public CDialogEx
{
	DECLARE_DYNAMIC(Ajouter_Pays)

public:
	Ajouter_Pays(CWnd* pParent = NULL);   // standard constructor
	virtual ~Ajouter_Pays();

// Dialog Data
	enum { IDD = IDD_PAYS_AJOUTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
