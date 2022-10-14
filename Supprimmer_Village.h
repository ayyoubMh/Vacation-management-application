#pragma once


// Supprimmer_Village dialog

class Supprimmer_Village : public CDialogEx
{
	DECLARE_DYNAMIC(Supprimmer_Village)

public:
	Supprimmer_Village(CWnd* pParent = NULL);   // standard constructor
	virtual ~Supprimmer_Village();

// Dialog Data
	enum { IDD = IDD_VILLAGE_SUPPRIMMER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
