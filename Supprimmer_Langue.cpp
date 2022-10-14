// Supprimmer_Langue.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Supprimmer_Langue.h"
#include "afxdialogex.h"


// Supprimmer_Langue dialog

IMPLEMENT_DYNAMIC(Supprimmer_Langue, CDialogEx)

Supprimmer_Langue::Supprimmer_Langue(CWnd* pParent /*=NULL*/)
	: CDialogEx(Supprimmer_Langue::IDD, pParent)
{

}

Supprimmer_Langue::~Supprimmer_Langue()
{
}

void Supprimmer_Langue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Supprimmer_Langue, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Supprimmer_Langue::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Supprimmer_Langue::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Supprimmer_Langue::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Supprimmer_Langue message handlers


void Supprimmer_Langue::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM ACTIVITE",NULL);

	CString codeL,codeLangue ;
	 
	   GetDlgItemText(IDC_Code_Langue,codeL);                             codeL.Remove(' ');

	   

       codeLangue = codeL ; 
	   codeLangue.Remove(' '); 
				
	   if( codeLangue.IsEmpty() ) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	//SqlString2.Format( L"Alter table PAYS drop foreign key no_continent, drop column no_pays where no_pays="+codeV);
	  //database.Execute(SqlString2) ;
	   	    SqlString2.Format(L"Delete from VILLAGE_LANGUE where no_langue='"+codeL+"'"); 
       database.Execute(SqlString2) ; 
	  SqlString1.Format(L"Delete from VILLAGE_LANGUE where no_langue='"+codeL+"'"); 
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien supprimés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Langue,L"");                           
}


//void Supprimmer_Langue::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Supprimmer_Langue::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
