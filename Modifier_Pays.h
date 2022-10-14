#pragma once


// Modifer_Pays dialog

class Modifier_Pays : public CDialogEx
{
	DECLARE_DYNAMIC(Modifier_Pays)

public:
	Modifier_Pays(CWnd* pParent = NULL);   // standard constructor
	virtual ~Modifier_Pays();

// Dialog Data
	enum { IDD = IDD_PAYS_MODIFIER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedMfcbutton2();
};
