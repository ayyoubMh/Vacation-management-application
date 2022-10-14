// Ajouter_Langue.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Ajouter_Langue.h"
#include "afxdialogex.h"


// Ajouter_Langue dialog

IMPLEMENT_DYNAMIC(Ajouter_Langue, CDialogEx)

Ajouter_Langue::Ajouter_Langue(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ajouter_Langue::IDD, pParent)
{

}

Ajouter_Langue::~Ajouter_Langue()
{
}

void Ajouter_Langue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Ajouter_Langue, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Ajouter_Langue::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Ajouter_Langue::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Ajouter_Langue::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Ajouter_Langue message handlers


void Ajouter_Langue::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM LANGUE",NULL);

	CString codeL,nomL,codeV,CodeLangue,NomLangue,CodeVillage ;
	 
	   GetDlgItemText(IDC_Code_Langue,codeL);                             codeL.Remove(' ');
	   GetDlgItemText(IDC_Nom_Langue,nomL);                       nomL.Remove(' ');
	   GetDlgItemText(IDC_Code_Village,codeV);
       CodeLangue = codeL ; NomLangue= nomL; CodeVillage = codeV;
	   CodeLangue.Remove(' '); NomLangue.Remove(' ');CodeVillage.Remove(' ');
				
	   if( CodeLangue.IsEmpty()  || NomLangue.IsEmpty() || CodeVillage.IsEmpty()) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}

	   SqlString1.Format( L"INSERT INTO LANGUE (no_langue,nomLangue,no_village) VALUES ('"+codeL+"','"+nomL+"','"+codeV+"')");
	   database.Execute(SqlString1) ; 
	   SqlString2.Format( L"INSERT INTO VILLAGE_LANGUE (no_village,no_langue) VALUES ('"+codeV+"','"+codeL+"')");
	   database.Execute(SqlString2) ; 
	   AfxMessageBox(L"Les champs ont été bien ajoutés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Langue,L"");                           
	   SetDlgItemText(IDC_Nom_Langue,L"");                       
	   SetDlgItemText(IDC_Code_Village,L"");  

}


//void Ajouter_Langue::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Ajouter_Langue::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
