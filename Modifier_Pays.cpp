// Modifer_Pays.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Modifier_Pays.h"
#include "afxdialogex.h"


// Modifer_Pays dialog

IMPLEMENT_DYNAMIC(Modifier_Pays, CDialogEx)

Modifier_Pays::Modifier_Pays(CWnd* pParent /*=NULL*/)
	: CDialogEx(Modifier_Pays::IDD, pParent)
{

}

Modifier_Pays::~Modifier_Pays()
{
}

void Modifier_Pays::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Modifier_Pays, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Modifier_Pays::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &Modifier_Pays::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// Modifer_Pays message handlers


void Modifier_Pays::OnBnClickedMfcbutton1()
{
	CDaoDatabase database;
	CDaoRecordset recset( &database );

	CString SqlString1;
	database.Open(L"GestionVacances.mdb");  
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Pays",NULL);

	CString codeC,nomP,codeP,codeContinent,nomPays,codePays ;
	 
	   GetDlgItemText(IDC_Code_Pays,codeP);                            
	   GetDlgItemText(IDC_Nom_Pays,nomP);                       nomP.Remove(' ');
	   GetDlgItemText(IDC_Code_Continent,codeC);				codeP.Remove(' ');

       codePays = codeP ; nomPays= nomP; codeContinent=codeC;
	   codePays.Remove(' '); nomPays.Remove(' ');codeContinent.Remove(' ');
				
	   if( codePays.IsEmpty()  || nomPays.IsEmpty() ||codeContinent.IsEmpty()) { 
	      AfxMessageBox(L"Il faut remplir les champs !!");
		  return ;
		}
	    // SqlString1.Format(L"Delete from PAYS where no_pays='"+codeV+"'"); 
	   SqlString1.Format( L"UPDATE Pays set nomPays= '"+nomP+"' , no_continent='"+codeC+"' where no_pays='"+codeP+"'");
       database.Execute(SqlString1) ; 
	   AfxMessageBox(L"Les champs ont été bien modifiés !!",MB_ICONINFORMATION|MB_OK);
	   database.Close();

	   Sleep(1000);
	   SetDlgItemText(IDC_Code_Pays,L"");                           
	   SetDlgItemText(IDC_Nom_Pays,L"");                      
	   SetDlgItemText(IDC_Code_Continent,L"");

}




void Modifier_Pays::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
