#pragma once


// Supprimmer_Langue dialog

class Supprimmer_Langue : public CDialogEx
{
	DECLARE_DYNAMIC(Supprimmer_Langue)

public:
	Supprimmer_Langue(CWnd* pParent = NULL);   // standard constructor
	virtual ~Supprimmer_Langue();

// Dialog Data
	enum { IDD = IDD_LANGUE_SUPPRIMMER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
