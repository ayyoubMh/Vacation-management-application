// Supprimmer_Activit�e.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Supprimmer_Activit�e.h"
#include "afxdialogex.h"


// Supprimmer_Activit�e dialog

IMPLEMENT_DYNAMIC(Supprimmer_Activit�e, CDialogEx)

Supprimmer_Activit�e::Supprimmer_Activit�e(CWnd* pParent /*=NULL*/)
	: CDialogEx(Supprimmer_Activit�e::IDD, pParent)
{

}

Supprimmer_Activit�e::~Supprimmer_Activit�e()
{
}

void Supprimmer_Activit�e::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Supprimmer_Activit�e, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Supprimmer_Activit�e::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Supprimmer_Activit�e::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Supprimmer_Activit�e::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Supprimmer_Activit�e message handlers


void Supprimmer_Activit�e::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM ACTIVITE",NULL);

	CString codeA,codeActivitee ;
	 
	   GetDlgItemText(IDC_Code_Activitee,codeA);                             codeA.Remove(' ');
	   

       codeActivitee = codeA ; 
	   codeActivitee.Remove(' ');
				
	   if( codeActivitee.IsEmpty()) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	//SqlString2.Format( L"Alter table PAYS drop foreign key no_continent, drop column no_pays where no_pays="+codeV);
	  //database.Execute(SqlString2) ;
	   	    SqlString2.Format(L"Delete from VILLAGE_ACTIVITE where no_activite='"+codeA+"'"); 
       database.Execute(SqlString2) ; 
	  SqlString1.Format(L"Delete from ACTIVITE where no_activite='"+codeA+"'"); 
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont �t� bien supprim�s !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Activitee,L"");                                             


}


//void Supprimmer_Activit�e::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Supprimmer_Activit�e::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
