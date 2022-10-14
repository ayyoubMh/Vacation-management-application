// Supprimmer_Pays.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Supprimmer_Pays.h"
#include "afxdialogex.h"


// Supprimmer_Pays dialog

IMPLEMENT_DYNAMIC(Supprimmer_Pays, CDialogEx)

Supprimmer_Pays::Supprimmer_Pays(CWnd* pParent /*=NULL*/)
	: CDialogEx(Supprimmer_Pays::IDD, pParent)
{

}

Supprimmer_Pays::~Supprimmer_Pays()
{
}

void Supprimmer_Pays::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Supprimmer_Pays, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Supprimmer_Pays::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Supprimmer_Pays::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Supprimmer_Pays::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Supprimmer_Pays message handlers



void Supprimmer_Pays::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2,SqlString3,SqlString5,SqlString4,SqlString6;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Pays",NULL);

	CString codeV,nomV,codeP,codeVillage,nomVillage,codePays ;
	 
	   GetDlgItemText(IDC_Code_Pays,codeV);					codeV.Remove(' ');

       codePays = codeV ;
	   codePays.Remove(' '); 
				
	   if( codePays.IsEmpty() ) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;}
	     SqlString5.Format(L"Delete from VILLAGE_LANGUE where no_village in ( select no_Village from village where VILLAGE.no_pays='"+codeV+"')"); 
       database.Execute(SqlString5) ;
	     SqlString3.Format(L"Delete from LANGUE where no_village in ( select no_Village from village where VILLAGE.no_pays='"+codeV+"')"); 
       database.Execute(SqlString3) ; 
	        SqlString4.Format(L"Delete from VILLAGE_ACTIVITE where no_village in ( select no_Village from village where VILLAGE.no_pays='"+codeV+"')"); 
       database.Execute(SqlString4) ;
	      SqlString6.Format(L"Delete from ACTIVITE where no_village in (select no_village from VILLAGE where VILLAGE.no_pays='"+codeV+"')"); 
       database.Execute(SqlString6) ;

	    SqlString2.Format(L"Delete from VILLAGE where no_pays='"+codeV+"'"); 
       database.Execute(SqlString2) ; 

	  
	  SqlString1.Format(L"Delete from PAYS where no_pays='"+codeV+"'"); 
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien supprimés !!",MB_ICONINFORMATION|MB_OK);
	    
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Pays,L"");                           
}


//void Supprimmer_Pays::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Supprimmer_Pays::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
