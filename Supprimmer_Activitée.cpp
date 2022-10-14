// Supprimmer_Activitée.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Supprimmer_Activitée.h"
#include "afxdialogex.h"


// Supprimmer_Activitée dialog

IMPLEMENT_DYNAMIC(Supprimmer_Activitée, CDialogEx)

Supprimmer_Activitée::Supprimmer_Activitée(CWnd* pParent /*=NULL*/)
	: CDialogEx(Supprimmer_Activitée::IDD, pParent)
{

}

Supprimmer_Activitée::~Supprimmer_Activitée()
{
}

void Supprimmer_Activitée::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Supprimmer_Activitée, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Supprimmer_Activitée::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Supprimmer_Activitée::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Supprimmer_Activitée::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Supprimmer_Activitée message handlers


void Supprimmer_Activitée::OnBnClickedMfcbutton1()
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
	   AfxMessageBox(L"Les champs ont été bien supprimés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Activitee,L"");                                             


}


//void Supprimmer_Activitée::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Supprimmer_Activitée::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
