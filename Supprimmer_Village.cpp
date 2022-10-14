// Supprimmer_Village.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Supprimmer_Village.h"
#include "afxdialogex.h"


// Supprimmer_Village dialog

IMPLEMENT_DYNAMIC(Supprimmer_Village, CDialogEx)

Supprimmer_Village::Supprimmer_Village(CWnd* pParent /*=NULL*/)
	: CDialogEx(Supprimmer_Village::IDD, pParent)
{

}

Supprimmer_Village::~Supprimmer_Village()
{
}

void Supprimmer_Village::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Supprimmer_Village, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Supprimmer_Village::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Supprimmer_Village::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Supprimmer_Village::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Supprimmer_Village message handlers


void Supprimmer_Village::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2,SqlString3,SqlString4,SqlString5;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE",NULL);

	CString codeV,codeVillage ;
	 
	   GetDlgItemText(IDC_Code_Village,codeV);                             codeV.Remove(' ');

       codeVillage = codeV ; 
	   codeVillage.Remove(' '); 
				
	   if( codeVillage.IsEmpty() ) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	

	      SqlString5.Format(L"Delete from VILLAGE_LANGUE where no_village='"+codeV+"'"); 
       database.Execute(SqlString5) ;
	     SqlString3.Format(L"Delete from LANGUE where no_village='"+codeV+"'"); 
       database.Execute(SqlString3) ; 
	        SqlString4.Format(L"Delete from VILLAGE_ACTIVITE where no_village='"+codeV+"'"); 
       database.Execute(SqlString4) ;
	      SqlString2.Format(L"Delete from ACTIVITE where no_village='"+codeV+"'"); 
       database.Execute(SqlString2) ;
	  
	  SqlString1.Format(L"Delete from VILLAGE where no_village='"+codeV+"'"); 
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien supprimés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();
	 
	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Village,L"");                           
       

}


//void Supprimmer_Village::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Supprimmer_Village::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
