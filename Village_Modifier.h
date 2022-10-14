#pragma once


// Village_Modifier dialog

class Village_Modifier : public CDialogEx
{
	DECLARE_DYNAMIC(Village_Modifier)

public:
	Village_Modifier(CWnd* pParent = NULL);   // standard constructor
	virtual ~Village_Modifier();

// Dialog Data
	enum { IDD = IDD_VILLAGE_MODIFIER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
//	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMfcbutton2();
};
