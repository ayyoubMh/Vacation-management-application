// Modifier_Langue.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Modifier_Langue.h"
#include "afxdialogex.h"


// Modifier_Langue dialog

IMPLEMENT_DYNAMIC(Modifier_Langue, CDialogEx)

Modifier_Langue::Modifier_Langue(CWnd* pParent /*=NULL*/)
	: CDialogEx(Modifier_Langue::IDD, pParent)
{

}

Modifier_Langue::~Modifier_Langue()
{
}

void Modifier_Langue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Modifier_Langue, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Modifier_Langue::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Modifier_Langue::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Modifier_Langue::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Modifier_Langue message handlers


void Modifier_Langue::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1,SqlString2;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM ACTIVITE",NULL);

	CString codeA,nomA,codeG,codeV,CodeActivitee,NomActivitee,GRATUITE,CodeVillage ;
	 
	   GetDlgItemText(IDC_Code_Langue,codeA);                             codeV.Remove(' ');
	   GetDlgItemText(IDC_Nom_Langue,nomA);                       nomA.Remove(' ');
	   GetDlgItemText(IDC_Code_Village,codeV);
       CodeActivitee = codeA ; NomActivitee= nomA; CodeVillage=codeV;
	   CodeActivitee.Remove(' '); NomActivitee.Remove(' '); CodeVillage.Remove(' ');
				
	   if( CodeActivitee.IsEmpty()  || NomActivitee.IsEmpty() ||  CodeVillage.IsEmpty()) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	      SqlString1.Format( L"UPDATE LANGUE  set nomLangue='"+nomA+"', no_village='"+codeV+"' where no_langue='"+codeA+"'");
	   database.Execute(SqlString1) ; 
	  
	   	   SqlString2.Format( L"UPDATE VILLAGE_LANGUE set no_village='"+codeV+"'   where no_langue='"+codeA+"'");
		database.Execute(SqlString2) ; 
		AfxMessageBox(L"Les champs ont été bien modifiés !!",MB_ICONINFORMATION|MB_OK);
	

	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Nom_Langue,L"");                           
	   SetDlgItemText(IDC_Code_Village,L"");                      
	   SetDlgItemText(IDC_Code_Village,L"");  
}


//void Modifier_Langue::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Modifier_Langue::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
