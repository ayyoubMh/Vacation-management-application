// Ajouter_Activitée.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Ajouter_Activitée.h"
#include "afxdialogex.h"


// Ajouter_Activitée dialog

IMPLEMENT_DYNAMIC(Ajouter_Activitée, CDialogEx)

Ajouter_Activitée::Ajouter_Activitée(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ajouter_Activitée::IDD, pParent)
{

}

Ajouter_Activitée::~Ajouter_Activitée()
{
}

void Ajouter_Activitée::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Ajouter_Activitée, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Ajouter_Activitée::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Ajouter_Activitée::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Ajouter_Activitée::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Ajouter_Activitée message handlers


void Ajouter_Activitée::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	
		///
CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM ACTIVITE",NULL);

	CString codeA,nomA,codeG,codeV,CodeActivitee,NomActivitee,GRATUITE,CodeVillage ;
	 
	   GetDlgItemText(IDC_Code_Activitee,codeA);                             codeV.Remove(' ');
	   GetDlgItemText(IDC_Nom_Activitee,nomA);                       nomA.Remove(' ');
	   GetDlgItemText(IDC_GRATUITE,codeG);
	   GetDlgItemText(IDC_Code_Village,codeV);
       CodeActivitee = codeA ; NomActivitee= nomA; GRATUITE = codeG; CodeVillage=codeV;
	   CodeActivitee.Remove(' '); NomActivitee.Remove(' '); GRATUITE.Remove(' ');CodeVillage.Remove(' ');
				
	   if( CodeActivitee.IsEmpty()  || NomActivitee.IsEmpty() || GRATUITE.IsEmpty() || CodeVillage.IsEmpty()) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}

	   SqlString1.Format( L"INSERT INTO ACTIVITE (no_activite,nomActivite,no_village) VALUES ('"+codeA+"','"+nomA+"','"+codeV+"')");
	   database.Execute(SqlString1) ; 
	   SqlString2.Format( L"INSERT INTO VILLAGE_ACTIVITE (no_village,no_activite,gratuité) VALUES ('"+codeV+"','"+codeA+"','"+codeG+"')");
	   database.Execute(SqlString2) ; 
	   AfxMessageBox(L"Les champs ont été bien ajoutés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Activitee,L"");                           
	   SetDlgItemText(IDC_Nom_Activitee,L"");                      
	   SetDlgItemText(IDC_GRATUITE,L"");  
	   SetDlgItemText(IDC_Code_Village,L"");  

		



}


//void Ajouter_Activitée::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Ajouter_Activitée::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
