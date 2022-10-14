// Chercher_Activitee.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Chercher_Activitee.h"
#include "afxdialogex.h"


// Chercher_Activitee dialog

IMPLEMENT_DYNAMIC(Chercher_Activitee, CDialogEx)

Chercher_Activitee::Chercher_Activitee(CWnd* pParent /*=NULL*/)
	: CDialogEx(Chercher_Activitee::IDD, pParent)
	, code_Activite(_T(""))
{

}

Chercher_Activitee::~Chercher_Activitee()
{
}

void Chercher_Activitee::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_activite);
	DDX_Text(pDX, IDC_Code_Activite, code_Activite);
}


BEGIN_MESSAGE_MAP(Chercher_Activitee, CDialogEx)
	ON_BN_CLICKED(IDC_CHERCHER_ACTIVITE, &Chercher_Activitee::OnBnClickedChercherActivite)
//	ON_BN_CLICKED(IDC_EXIT, &Chercher_Activitee::OnBnClickedExit)
ON_BN_CLICKED(IDC_CHERCHER_ACTIVITE2, &Chercher_Activitee::OnBnClickedChercherActivite2)
END_MESSAGE_MAP()


// Chercher_Activitee message handlers


void Chercher_Activitee::OnBnClickedChercherActivite()
{
	// TODO: Add your control notification handler code here
	//m_list_activite
	CString SqlString1,codep,nomp,codec;
	  
	CString codeP;
	GetDlgItemText(IDC_Code_Activite,codeP);
	int nColumnCount = m_list_activite.GetHeaderCtrl()->GetItemCount();
    for (int i=0; i < nColumnCount; i++) m_list_activite.DeleteColumn(0);
	
	 

	m_list_activite.InsertColumn(0,L"Code Activité",LVCFMT_CENTER,130,-1); 
	m_list_activite.InsertColumn(1,L"Code Village",LVCFMT_CENTER,130,-1); 
	m_list_activite.InsertColumn(2,L"Nom Activité",LVCFMT_CENTER,130,-1); 
	m_list_activite.InsertColumn(3,L"Gratuité",LVCFMT_CENTER,130,-1);
	ListView_SetExtendedListViewStyle(m_list_activite,LVS_EX_GRIDLINES); 

	CDaoDatabase database;
	CDaoRecordset recset( &database );
	CDaoRecordset recset2( &database );
  
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
	 m_list_activite.DeleteAllItems();
	database.Open(L"GestionVacances.mdb");
	//AfxMessageBox(L""+codeP);
	 recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM ACTIVITE where no_activite = '"+codeP+"'",NULL);
	 recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE_ACTIVITE where no_activite = '"+codeP+"'",NULL);
	while(!recset.IsEOF() && !recset2.IsEOF())//do until eof
   {int i=0;
    recset.GetFieldValue(L"no_activite", var);
	codep.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list_activite.InsertItem(i,codep,0);

	recset.GetFieldValue(L"no_village",var);
	nomp=(LPCWSTR)var.pbstrVal;
	m_list_activite.SetItemText(i,1,nomp);

	recset.GetFieldValue(L"nomActivite",var);
	codec=(LPCWSTR)var.pbstrVal;
	m_list_activite.SetItemText(i,2,codec);

	recset2.GetFieldValue(L"gratuité",var);
	codec=(LPCWSTR)var.pbstrVal;
	m_list_activite.SetItemText(i,3,codec);

	i=i++;
	recset2.MoveNext();
	}
}


//void Chercher_Activitee::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Chercher_Activitee::OnBnClickedChercherActivite2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
