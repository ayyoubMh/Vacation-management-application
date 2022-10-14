// Modifier_Activitée.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Modifier_Activitée.h"
#include "afxdialogex.h"


// Modifier_Activitée dialog

IMPLEMENT_DYNAMIC(Modifier_Activitée, CDialogEx)

Modifier_Activitée::Modifier_Activitée(CWnd* pParent /*=NULL*/)
	: CDialogEx(Modifier_Activitée::IDD, pParent)
{

}

Modifier_Activitée::~Modifier_Activitée()
{
}

void Modifier_Activitée::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Modifier_Activitée, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Modifier_Activitée::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Modifier_Activitée::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Modifier_Activitée::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Modifier_Activitée message handlers


void Modifier_Activitée::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
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
	      SqlString1.Format( L"UPDATE ACTIVITE  set no_village='"+codeV+"', nomActivite='"+nomA+"'  where no_activite='"+codeA+"'");
	   database.Execute(SqlString1) ; 
	  
	   	   SqlString2.Format( L"UPDATE VILLAGE_ACTIVITE set no_village='"+codeV+"'  , gratuité = '"+codeG+"' where no_activite='"+codeA+"'");
		database.Execute(SqlString2) ; 
		AfxMessageBox(L"Les champs ont été bien modifiés !!",MB_ICONINFORMATION|MB_OK);
	

	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Activitee,L"");                           
	   SetDlgItemText(IDC_Nom_Activitee,L"");                      
	   SetDlgItemText(IDC_GRATUITE,L"");  
	   SetDlgItemText(IDC_Code_Village,L"");  

		

}


//void Modifier_Activitée::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Modifier_Activitée::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
