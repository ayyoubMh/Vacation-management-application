#pragma once


// Supprimmer_Activit�e dialog

class Supprimmer_Activit�e : public CDialogEx
{
	DECLARE_DYNAMIC(Supprimmer_Activit�e)

public:
	Supprimmer_Activit�e(CWnd* pParent = NULL);   // standard constructor
	virtual ~Supprimmer_Activit�e();

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
