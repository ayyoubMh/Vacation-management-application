#pragma once


// Modifier_Langue dialog

class Modifier_Langue : public CDialogEx
{
	DECLARE_DYNAMIC(Modifier_Langue)

public:
	Modifier_Langue(CWnd* pParent = NULL);   // standard constructor
	virtual ~Modifier_Langue();

// Dialog Data
	enum { IDD = IDD_LANGUE_MODIFIER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
