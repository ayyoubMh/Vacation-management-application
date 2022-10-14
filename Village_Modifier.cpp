// Village_Modifier.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Village_Modifier.h"
#include "afxdialogex.h"


// Village_Modifier dialog

IMPLEMENT_DYNAMIC(Village_Modifier, CDialogEx)

Village_Modifier::Village_Modifier(CWnd* pParent /*=NULL*/)
	: CDialogEx(Village_Modifier::IDD, pParent)
{

}

Village_Modifier::~Village_Modifier()
{
}

void Village_Modifier::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Village_Modifier, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Village_Modifier::OnBnClickedMfcbutton1)
//	ON_BN_CLICKED(IDC_EXIT, &Village_Modifier::OnBnClickedExit)
ON_BN_CLICKED(IDC_MFCBUTTON2, &Village_Modifier::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Village_Modifier message handlers


void Village_Modifier::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE",NULL);

	CString codeV,nomV,codeP,CodeVillage,NomVillage,codePays ;
	 
	   GetDlgItemText(IDC_Code_Village,codeV);                            
	   GetDlgItemText(IDC_Nom_Village,nomV);                       nomV.Remove(' ');
	   GetDlgItemText(IDC_Code_Pays,codeP);				codeP.Remove(' ');

       CodeVillage = codeV ; NomVillage= nomV; codePays=codeP;
	   CodeVillage.Remove(' '); NomVillage.Remove(' ');codePays.Remove(' ');
				
	   if( CodeVillage.IsEmpty()  || NomVillage.IsEmpty() ||codePays.IsEmpty()) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	    // SqlString1.Format(L"Delete from PAYS where no_pays='"+codeV+"'"); 
	   SqlString1.Format( L"UPDATE VILLAGE set nomVillage= '"+nomV+"' , no_pays='"+codeP+"' where no_village='"+codeV+"'");
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien modifiés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Village,L"");                           
	   SetDlgItemText(IDC_Nom_Village,L"");                      
	   SetDlgItemText(IDC_Code_Pays,L"");
}


//void Village_Modifier::OnBnClickedExit()
//{
//	// TODO: Add your control notification handler code here
//	OnOK();
//}


void Village_Modifier::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
