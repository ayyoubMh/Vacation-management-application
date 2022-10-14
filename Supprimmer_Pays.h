#pragma once


// Supprimmer_Pays dialog

class Supprimmer_Pays : public CDialogEx
{
	DECLARE_DYNAMIC(Supprimmer_Pays)

public:
	Supprimmer_Pays(CWnd* pParent = NULL);   // standard constructor
	virtual ~Supprimmer_Pays();

// Dialog Data
	enum { IDD = IDD_PAYS_SUPPRIMMER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
