// Chercher_Pays.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Chercher_Pays.h"
#include "afxdialogex.h"


// Chercher_Pays dialog

IMPLEMENT_DYNAMIC(Chercher_Pays, CDialogEx)

Chercher_Pays::Chercher_Pays(CWnd* pParent /*=NULL*/)
	: CDialogEx(Chercher_Pays::IDD, pParent)
	, code_Pays(_T(""))
{

}

Chercher_Pays::~Chercher_Pays()
{
}

void Chercher_Pays::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_Code_Pays, code_Pays);
	DDX_Control(pDX, IDC_LIST2, m_list_pays);
	DDX_Text(pDX, IDC_Code_Pays, code_Pays);
}


BEGIN_MESSAGE_MAP(Chercher_Pays, CDialogEx)
//	ON_BN_CLICKED(IDC_CHERCHER_PAYS, &Chercher_Pays::OnBnClickedChercherPays)
	ON_EN_CHANGE(IDC_Code_Pays, &Chercher_Pays::OnEnChangeCodePays)
//	ON_BN_CLICKED(IDC_EXIT, &Chercher_Pays::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON1, &Chercher_Pays::OnBnClickedMfcbutton1)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Chercher_Pays::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Chercher_Pays message handlers




//void Chercher_Pays::OnBnClickedChercherPays()
//{
//	// TODO: Add your control notification handler code here
//	//code_Pays
//	//m_list_pays
//	
//
//	CString SqlString1,codep,nomp,codec,nomv;
//	  
//	CString codeP;
//	GetDlgItemText(IDC_Code_Pays,codeP);
//	int nColumnCount = m_list_pays.GetHeaderCtrl()->GetItemCount();
//    for (int i=0; i < nColumnCount; i++) m_list_pays.DeleteColumn(0);
//	
//	m_list_pays.InsertColumn(0,L"Code Pays",LVCFMT_CENTER,130,-1); 
//	m_list_pays.InsertColumn(1,L"Code Continent",LVCFMT_CENTER,130,-1); 
//	m_list_pays.InsertColumn(2,L"Nom Pays",LVCFMT_CENTER,130,-1); 
//	m_list_pays.InsertColumn(3,L"Nom Village",LVCFMT_CENTER,130,-1);
//	ListView_SetExtendedListViewStyle(m_list_pays,LVS_EX_GRIDLINES); 
//
//	CDaoDatabase database;
//	CDaoRecordset recset( &database );
//	CDaoRecordset recset2( &database );
//  
//	COleVariant var;//start Variables
//	var.ChangeType(VT_BSTR,NULL);
//	 m_list_pays.DeleteAllItems();
//	database.Open(L"GestionVacances.mdb");
//	//AfxMessageBox(L""+code_Pays);
//	 recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM PAYS where no_pays = '"+codeP+"'",NULL);
//	 recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE where no_pays = '"+codeP+"'",NULL);
//	while(!recset.IsEOF() && !recset2.IsEOF())//do until eof
//   {int i=0;
//    
//	recset.GetFieldValue(L"no_pays",var);
//	codep.Format(L"%s",(LPCWSTR)var.pbstrVal);
//	m_list_pays.InsertItem(i,codep,0);
//
//	recset.GetFieldValue(L"no_continent", var);
//	nomp=(LPCWSTR)var.pbstrVal;
//	m_list_pays.SetItemText(i,1,nomp);
//
//	recset.GetFieldValue(L"nomPays",var);
//	codec=(LPCWSTR)var.pbstrVal;
//	m_list_pays.SetItemText(i,2,codec);
//
//	recset2.GetFieldValue(L"nomVillage",var);
//	nomv=(LPCWSTR)var.pbstrVal;
//	m_list_pays.SetItemText(i,3,nomv);
//	i=i++;
//	recset2.MoveNext();
//	}
//}


void Chercher_Pays::OnEnChangeCodePays()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


//void Chercher_Pays::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Chercher_Pays::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CString SqlString1,codep,nomp,codec,nomv;
	  
	CString codeP;
	GetDlgItemText(IDC_Code_Pays,codeP);
	int nColumnCount = m_list_pays.GetHeaderCtrl()->GetItemCount();
    for (int i=0; i < nColumnCount; i++) m_list_pays.DeleteColumn(0);
	
	m_list_pays.InsertColumn(0,L"Code Pays",LVCFMT_CENTER,130,-1); 
	m_list_pays.InsertColumn(1,L"Code Continent",LVCFMT_CENTER,130,-1); 
	m_list_pays.InsertColumn(2,L"Nom Pays",LVCFMT_CENTER,130,-1); 
	m_list_pays.InsertColumn(3,L"Nom Village",LVCFMT_CENTER,130,-1);
	ListView_SetExtendedListViewStyle(m_list_pays,LVS_EX_GRIDLINES); 

	CDaoDatabase database;
	CDaoRecordset recset( &database );
	CDaoRecordset recset2( &database );
  
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
	 m_list_pays.DeleteAllItems();
	database.Open(L"GestionVacances.mdb");
	//AfxMessageBox(L""+code_Pays);
	 recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM PAYS where no_pays = '"+codeP+"'",NULL);
	 recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE where no_pays = '"+codeP+"'",NULL);
	while(!recset.IsEOF() && !recset2.IsEOF())//do until eof
   {int i=0;
    
	recset.GetFieldValue(L"no_pays",var);
	codep.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list_pays.InsertItem(i,codep,0);

	recset.GetFieldValue(L"no_continent", var);
	nomp=(LPCWSTR)var.pbstrVal;
	m_list_pays.SetItemText(i,1,nomp);

	recset.GetFieldValue(L"nomPays",var);
	codec=(LPCWSTR)var.pbstrVal;
	m_list_pays.SetItemText(i,2,codec);

	recset2.GetFieldValue(L"nomVillage",var);
	nomv=(LPCWSTR)var.pbstrVal;
	m_list_pays.SetItemText(i,3,nomv);
	i=i++;
	recset2.MoveNext();
	}
}


void Chercher_Pays::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
