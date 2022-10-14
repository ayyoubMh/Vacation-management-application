// Ajouter_Village.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Ajouter_Village.h"
#include "afxdialogex.h"
#include <afxdao.h>


// Ajouter_Village dialog

IMPLEMENT_DYNAMIC(Ajouter_Village, CDialogEx)

Ajouter_Village::Ajouter_Village(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ajouter_Village::IDD, pParent)
{

}

Ajouter_Village::~Ajouter_Village()
{
}

void Ajouter_Village::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Ajouter_Village, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Ajouter_Village::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Ajouter_Village::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Ajouter_Village::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Ajouter_Village message handlers


void Ajouter_Village::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE",NULL);

	CString codeV,nomV,codeP,codeVillage,nomVillage,codePays ;
	 
	   GetDlgItemText(IDC_Code_Village,codeV);                             codeV.Remove(' ');
	   GetDlgItemText(IDC_Nom_Village,nomV);                       nomV.Remove(' ');
	   GetDlgItemText(IDC_Code_Pays_Village,codeP);
       codeVillage = codeV ; nomVillage= nomV; codePays = codeP;
	   codeVillage.Remove(' '); nomVillage.Remove(' '); codePays.Remove(' ');
				
	   if( codeVillage.IsEmpty()  || nomVillage.IsEmpty() || codePays.IsEmpty() ) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}

	   SqlString1.Format( L"INSERT INTO VILLAGE (no_village,nomVillage,no_pays) VALUES ('"+codeV+"','"+nomV+"','"+codeP+"')");
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien ajoutés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Village,L"");                           
	   SetDlgItemText(IDC_Nom_Village,L"");                      
	   SetDlgItemText(IDC_Code_Pays_Village,L"");
}


//void Ajouter_Village::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Ajouter_Village::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
