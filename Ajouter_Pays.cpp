// Ajouter_Pays.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Ajouter_Pays.h"
#include "afxdialogex.h"


// Ajouter_Pays dialog

IMPLEMENT_DYNAMIC(Ajouter_Pays, CDialogEx)

Ajouter_Pays::Ajouter_Pays(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ajouter_Pays::IDD, pParent)
{

}

Ajouter_Pays::~Ajouter_Pays()
{
}

void Ajouter_Pays::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Ajouter_Pays, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Ajouter_Pays::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Ajouter_Pays::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Ajouter_Pays::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Ajouter_Pays message handlers


void Ajouter_Pays::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Pays",NULL);

	CString codeV,nomV,codeP,codeVillage,nomVillage,codePays ;
	 
	   GetDlgItemText(IDC_Code_Pays,codeV);                             codeV.Remove(' ');
	   GetDlgItemText(IDC_Nom_Pays,nomV);                       nomV.Remove(' ');
	   GetDlgItemText(IDC_Code_Continent,codeP);
       codeVillage = codeV ; nomVillage= nomV; codePays = codeP;
	   codeVillage.Remove(' '); nomVillage.Remove(' '); codePays.Remove(' ');
				
	   if( codeVillage.IsEmpty()  || nomVillage.IsEmpty() || codePays.IsEmpty() ) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	  
	   SqlString1.Format( L"INSERT INTO PAYS (no_pays,nomPays,no_continent) VALUES ('"+codeV+"','"+nomV+"','"+codeP+"')");
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien ajoutés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Pays,L"");                           
	   SetDlgItemText(IDC_Nom_Pays,L"");                      
	   SetDlgItemText(IDC_Code_Continent,L"");



}


//void Ajouter_Pays::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Ajouter_Pays::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
