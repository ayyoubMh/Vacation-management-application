// Chercher_Village.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Chercher_Village.h"
#include "afxdialogex.h"


// Chercher_Village dialog

IMPLEMENT_DYNAMIC(Chercher_Village, CDialogEx)

Chercher_Village::Chercher_Village(CWnd* pParent /*=NULL*/)
	: CDialogEx(Chercher_Village::IDD, pParent)
	, code_Village(_T(""))
{

}

Chercher_Village::~Chercher_Village()
{
}

void Chercher_Village::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_village);
	DDX_Text(pDX, IDC_Code_Village, code_Village);
}


BEGIN_MESSAGE_MAP(Chercher_Village, CDialogEx)
	ON_BN_CLICKED(IDC_CHERCHER_VILLAGE, &Chercher_Village::OnBnClickedChercherVillage)
//	ON_BN_CLICKED(IDC_EXIT, &Chercher_Village::OnBnClickedExit)
ON_BN_CLICKED(IDC_CHERCHER_VILLAGE2, &Chercher_Village::OnBnClickedChercherVillage2)
END_MESSAGE_MAP()


// Chercher_Village message handlers


void Chercher_Village::OnBnClickedChercherVillage()
{
	// TODO: Add your control notification handler code here
	//m_list_village
	//code_Village
	CString SqlString1,codep,nomp,codec,nomA;
	  
	CString codeP;
	GetDlgItemText(IDC_Code_Village,codeP);
	int nColumnCount = m_list_village.GetHeaderCtrl()->GetItemCount();
    for (int i=0; i < nColumnCount; i++) m_list_village.DeleteColumn(0);
	
	
	m_list_village.InsertColumn(0,L"Code Village",LVCFMT_CENTER,130,-1); 
	m_list_village.InsertColumn(1,L"Code Pays",LVCFMT_CENTER,130,-1); 
	m_list_village.InsertColumn(2,L"Nom Village",LVCFMT_CENTER,130,-1); 
	m_list_village.InsertColumn(3,L"La Langue",LVCFMT_CENTER,130,-1); 
	ListView_SetExtendedListViewStyle(m_list_village,LVS_EX_GRIDLINES); 

	CDaoDatabase database;
	CDaoRecordset recset( &database );
	CDaoRecordset recset2( &database );
  
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
	 m_list_village.DeleteAllItems();
	database.Open(L"GestionVacances.mdb");
	//AfxMessageBox(L""+code_Pays);
	 recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE where no_village = '"+codeP+"'",NULL);
	 recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM LANGUE where no_village = '"+codeP+"'",NULL);
	while(!recset.IsEOF() && !recset2.IsEOF())//do until eof
   {int i=0;

	recset.GetFieldValue(L"no_village", var);
	codec=(LPCWSTR)var.pbstrVal;
	m_list_village.InsertItem(i,codec,0);

    recset.GetFieldValue(L"no_pays",var);
	codep.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list_village.SetItemText(i,1,codep);

	recset.GetFieldValue(L"nomVillage",var);
	nomp=(LPCWSTR)var.pbstrVal;
	m_list_village.SetItemText(i,2,nomp);

	recset2.GetFieldValue(L"nomLangue",var);
	nomA=(LPCWSTR)var.pbstrVal;
	m_list_village.SetItemText(i,3,nomA);
	i=i++;
	recset2.MoveNext();
	}
}


//void Chercher_Village::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Chercher_Village::OnBnClickedChercherVillage2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
