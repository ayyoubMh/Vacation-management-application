#pragma once


// Modifier_Activit�e dialog

class Modifier_Activit�e : public CDialogEx
{
	DECLARE_DYNAMIC(Modifier_Activit�e)

public:
	Modifier_Activit�e(CWnd* pParent = NULL);   // standard constructor
	virtual ~Modifier_Activit�e();

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
