// Gestion_GarageDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Gestion_Garage.h"
#include "Gestion_GarageDlg.h"
#include "afxdialogex.h"
#include "Ajouter_Village.h"
#include "Supprimmer_Village.h"
#include "Village_Modifier.h"
#include "Ajouter_Pays.h"
#include "Modifier_Pays.h"
#include "Supprimmer_Pays.h"
#include "Ajouter_Activitée.h"
#include "Modifier_Activitée.h"
#include "Supprimmer_Activitée.h"
#include "Ajouter_Langue.h"
#include "Modifier_Langue.h"
#include "Supprimmer_Langue.h"
#include "Chercher_Pays.h"
#include "Chercher_Village.h"
#include "Chercher_Activitee.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
CDaoDatabase db;
CDaoRecordset recset(&db);

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGestion_GarageDlg dialog




CGestion_GarageDlg::CGestion_GarageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGestion_GarageDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGestion_GarageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_CONTINENTS, Continent);
	DDX_Control(pDX, IDC_PAYS, Pays);
	DDX_Control(pDX, IDC_VILLAGES, Village);
	DDX_Control(pDX, IDC_ACTIVITES, Activitée);
	DDX_Control(pDX, IDC_LANGUES, Langue);
	DDX_Control(pDX, IDC_CREATE_DB, DB);
	DDX_Control(pDX, IDC_ABOUT, About);
	DDX_Control(pDX, IDC_EXIT, Exit);
}

BEGIN_MESSAGE_MAP(CGestion_GarageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CGestion_GarageDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_CREATE_DB, &CGestion_GarageDlg::OnClickedCreateDb)
	ON_BN_CLICKED(IDC_ABOUT, &CGestion_GarageDlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_CONTINENTS, &CGestion_GarageDlg::OnBnClickedContinents)
	ON_BN_CLICKED(IDC_PAYS, &CGestion_GarageDlg::OnBnClickedPays)
	ON_BN_CLICKED(IDC_VILLAGES, &CGestion_GarageDlg::OnBnClickedVillages)
	ON_BN_CLICKED(IDC_ACTIVITES, &CGestion_GarageDlg::OnBnClickedActivites)
	ON_BN_CLICKED(IDC_LANGUES, &CGestion_GarageDlg::OnBnClickedLangues)
	ON_COMMAND(ID_AJOUTER_Un_Village, &CGestion_GarageDlg::OnAjouterUnVillage)
	ON_COMMAND(ID_SUPPRIMMER_UN_VILLAGE, &CGestion_GarageDlg::OnSupprimmerUnVillage)
//	ON_COMMAND(ID_MODIFIER_VILLAGE, &CGestion_GarageDlg::OnModifierVillage)
	ON_COMMAND(ID_AJOUTER_UN_PAYS, &CGestion_GarageDlg::OnAjouterUnPays)
	ON_COMMAND(ID_MODIFIER_UN_PAYS, &CGestion_GarageDlg::OnModifierUnPays)
	//ON_COMMAND(ID_MODIFIER_VILLAGE, &CGestion_GarageDlg::OnModifierVillage)
	ON_COMMAND(ID_MODIFIER_UN_VILLAGE, &CGestion_GarageDlg::OnModifierUnVillage)
	ON_COMMAND(ID_SUPPRIMMER_UN_PAYS, &CGestion_GarageDlg::OnSupprimmerUnPays)
	ON_COMMAND(ID_AJOUTER_UNE_ACTIVITEE, &CGestion_GarageDlg::OnAjouterUneActivitee)
	ON_COMMAND(ID_MODIFIER_UNE_ACTIVITEE, &CGestion_GarageDlg::OnModifierUneActivitee)
	ON_COMMAND(ID_SUPPRIMMER_UNE_ACTIVITEE, &CGestion_GarageDlg::OnSupprimmerUneActivitee)
	ON_COMMAND(ID_AJOUTER_UNE_LANGUE, &CGestion_GarageDlg::OnAjouterUneLangue)
	ON_COMMAND(ID_MODIFIER_UNE_LANGUE, &CGestion_GarageDlg::OnModifierUneLangue)
	ON_COMMAND(ID_SUPPRIMMER_UNE_LANGUE, &CGestion_GarageDlg::OnSupprimmerUneLangue)
	ON_COMMAND(ID_CHERCHER_PAYS, &CGestion_GarageDlg::OnChercherPays)
	ON_COMMAND(ID_CHERCHER_VILLAGE, &CGestion_GarageDlg::OnChercherVillage)
	//ON_UPDATE_COMMAND_UI(ID_CHERCHER_VILLAGE, &CGestion_GarageDlg::OnUpdateChercherVillage)
	ON_COMMAND(ID_CHERCHER_ACTIVIT32810, &CGestion_GarageDlg::OnChercherActivit32810)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CGestion_GarageDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CGestion_GarageDlg message handlers

BOOL CGestion_GarageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);
	m_list.SetBkColor(RGB(220, 220, 225));
	// Set small icon
	Continent.SetFaceColor(RGB(223, 230, 232),TRUE);
	Pays.SetFaceColor(RGB(223, 230, 232),TRUE);
	Village.SetFaceColor(RGB(223, 230, 232),TRUE);
	Activitée.SetFaceColor(RGB(223, 230, 232),TRUE);
	Langue.SetFaceColor(RGB(223, 230, 232),TRUE);
	DB.SetFaceColor(RGB(223, 230, 232),TRUE);
	About.SetFaceColor(RGB(223, 230, 232),TRUE);
	Exit.SetFaceColor(RGB(223, 230, 232),TRUE);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGestion_GarageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGestion_GarageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGestion_GarageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGestion_GarageDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CGestion_GarageDlg::OnClickedCreateDb()
{
	// TODO: Add your control notification handler code here
	CString lpszFile =L"GestionVacances.mdb";
db.Create(lpszFile);

CString creation_table_Continent=L"CREATE TABLE CONTINENT(no_continent VARCHAR(20) NOT NULL PRIMARY KEY,nomContinent varchar(30) NOT NULL);";
CString creation_table_Pays=L"CREATE TABLE PAYS(no_pays varchar(20) NOT NULL PRIMARY KEY,nomPays varchar(30) NOT NULL,no_continent VARCHAR(20),FOREIGN KEY (no_continent) REFERENCES CONTINENT(no_continent));";
CString creation_table_Village=L"CREATE TABLE VILLAGE(no_village varchar(20) NOT NULL PRIMARY KEY,nomVillage varchar(20) NOT NULL,no_pays varchar(20),FOREIGN KEY (no_pays) REFERENCES PAYS(no_pays) );";
CString creation_table_Langues=L"CREATE TABLE LANGUE(no_langue varchar(20) NOT NULL PRIMARY KEY ,nomLangue varchar(30) NOT NULL,no_village varchar(20) ,FOREIGN KEY (no_village) REFERENCES VILLAGE(no_village));";
CString creation_table_VillageLangue=L"CREATE TABLE VILLAGE_LANGUE(no_village varchar(20),no_langue varchar(20),FOREIGN KEY(no_village) REFERENCES VILLAGE(no_village),FOREIGN KEY(no_langue) REFERENCES LANGUE(no_langue), PRIMARY KEY(no_village, no_langue));";
CString creation_table_Activites=L"CREATE TABLE ACTIVITE(no_activite varchar(20) NOT NULL PRIMARY KEY,nomActivite varchar(30) NOT NULL,no_village varchar(20), FOREIGN KEY (no_village) REFERENCES VILLAGE(no_village));";
CString creation_table_VillageActivite=L"CREATE TABLE VILLAGE_ACTIVITE(no_village varchar(20),no_activite varchar(20),gratuité varchar(10), FOREIGN KEY(no_village) REFERENCES VILLAGE(no_village), FOREIGN KEY (no_activite) references ACTIVITE(no_activite), PRIMARY KEY(no_village, no_activite));";

db.Execute(creation_table_Continent);
db.Execute(creation_table_Pays);
db.Execute(creation_table_Village);
db.Execute(creation_table_Langues);
db.Execute(creation_table_VillageLangue);
db.Execute(creation_table_Activites);
db.Execute(creation_table_VillageActivite);
db.Close();
}






void CGestion_GarageDlg::OnBnClickedAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}



void CGestion_GarageDlg::OnBnClickedContinents()
{
int nColumnCount = m_list.GetHeaderCtrl()->GetItemCount();
    for (int i=0; i < nColumnCount; i++) m_list.DeleteColumn(0);

	m_list.InsertColumn(0,L"Code Continent",LVCFMT_CENTER,345,-1); 
	m_list.InsertColumn(1,L"Nom Continent",LVCFMT_CENTER,345,-1); 
	ListView_SetExtendedListViewStyle(m_list,LVS_EX_GRIDLINES); 

    CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString Numero_Continent,NomContinent;//end variables
   
   m_list.DeleteAllItems();//clear list
   db.Open(L"GestionVacances.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM CONTINENT",NULL);
   while(!recset.IsEOF())//do until eof
   {int i=0;
    recset.GetFieldValue(L"no_continent", var);
	Numero_Continent.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list.InsertItem(i,Numero_Continent,0);

    recset.GetFieldValue(L"nomContinent",var);
	NomContinent=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,1,NomContinent);
	i=i++;
	recset.MoveNext();  //aller d’un enregistrement à un autre
}

}
void CGestion_GarageDlg::OnBnClickedPays()
{
	
	int nColumnCount = m_list.GetHeaderCtrl()->GetItemCount();
     for (int i=0; i < nColumnCount; i++) m_list.DeleteColumn(0);

	m_list.InsertColumn(0,L"Code Pays",LVCFMT_CENTER,230,-1); 
	m_list.InsertColumn(1,L"Nom Pays",LVCFMT_CENTER,230,-1); 
	m_list.InsertColumn(2,L"Code Continent",LVCFMT_CENTER,230,-1);
	ListView_SetExtendedListViewStyle(m_list,LVS_EX_GRIDLINES); 
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString Numero_Pays,NomPays, NumeroContinent;//end variables
   
   m_list.DeleteAllItems();//clear list
   db.Open(L"GestionVacances.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM PAYS ",NULL);
   while(!recset.IsEOF())//do until eof
   {int i=0;
    recset.GetFieldValue(L"no_pays", var);
	Numero_Pays.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list.InsertItem(i,Numero_Pays,0);

    recset.GetFieldValue(L"nomPays",var);
	NomPays=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,1,NomPays);

	recset.GetFieldValue(L"no_continent",var);
	NumeroContinent=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,2,NumeroContinent);
	i=i++;
	recset.MoveNext();  //aller d’un enregistrement à un autre
   }
   
   recset.Close();
   db.Close();
}


void CGestion_GarageDlg::OnBnClickedVillages()
{
	// TODO: Add your control notification handler code here
		int nColumnCount = m_list.GetHeaderCtrl()->GetItemCount();
     for (int i=0; i < nColumnCount; i++) m_list.DeleteColumn(0);

	m_list.InsertColumn(0,L"Code Village",LVCFMT_CENTER,230,-1); 
	m_list.InsertColumn(1,L"Nom Village",LVCFMT_CENTER,230,-1); 
	m_list.InsertColumn(2,L"Code Pays",LVCFMT_CENTER,230,-1);
	ListView_SetExtendedListViewStyle(m_list,LVS_EX_GRIDLINES); 
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString Numero_Village,NomVillage, NumeroPays;//end variables
   
   m_list.DeleteAllItems();//clear list
   db.Open(L"GestionVacances.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM VILLAGE ",NULL);
   while(!recset.IsEOF())//do until eof
   {int i=0;
    recset.GetFieldValue(L"no_village", var);
	Numero_Village.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list.InsertItem(i,Numero_Village,0);

    recset.GetFieldValue(L"nomVillage",var);
	NomVillage=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,1,NomVillage);

	recset.GetFieldValue(L"no_pays",var);
	NumeroPays=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,2,NumeroPays);
	i=i++;
	recset.MoveNext();  //aller d’un enregistrement à un autre
   }
   
   recset.Close();
   db.Close();
}


void CGestion_GarageDlg::OnBnClickedActivites()
{
	// TODO: Add your control notification handler code here
	int nColumnCount = m_list.GetHeaderCtrl()->GetItemCount();
     for (int i=0; i < nColumnCount; i++) m_list.DeleteColumn(0);

	m_list.InsertColumn(0,L"Code Activité",LVCFMT_CENTER,172,-1); 
	m_list.InsertColumn(1,L"Nom Activité",LVCFMT_CENTER,172,-1); 
	m_list.InsertColumn(2,L"Code Village",LVCFMT_CENTER,172,-1);
	m_list.InsertColumn(3,L"Gratuité",LVCFMT_CENTER,172,-1);
	ListView_SetExtendedListViewStyle(m_list,LVS_EX_GRIDLINES); 
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString Numero_Activite,Numero_Village,NomActivite, Gratuité;//end variables
   
   m_list.DeleteAllItems();//clear list
   db.Open(L"GestionVacances.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT ACTIVITE.nomActivite,ACTIVITE.no_activite,VILLAGE.no_village,gratuité from ACTIVITE, VILLAGE, VILLAGE_ACTIVITE where ACTIVITE.no_activite=VILLAGE_ACTIVITE.no_activite and VILLAGE.no_village=VILLAGE_ACTIVITE.no_village",NULL);
   while(!recset.IsEOF())//do until eof
   {int i=0;
    recset.GetFieldValue(L"no_activite", var);
	Numero_Activite.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list.InsertItem(i,Numero_Activite,0);

    recset.GetFieldValue(L"nomActivite",var);
	NomActivite=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,1,NomActivite);

	recset.GetFieldValue(L"no_village",var);
	Numero_Village=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,2,Numero_Village);

	recset.GetFieldValue(L"gratuité",var);
	Gratuité=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,3,Gratuité);
	i=i++;
	recset.MoveNext();  //aller d’un enregistrement à un autre
}

}
void CGestion_GarageDlg::OnBnClickedLangues()
{
	// TODO: Add your control notification handler code here
int nColumnCount = m_list.GetHeaderCtrl()->GetItemCount();
     for (int i=0; i < nColumnCount; i++) m_list.DeleteColumn(0);

	m_list.InsertColumn(0,L"Code Langue",LVCFMT_CENTER,230,-1); 
	m_list.InsertColumn(1,L"Langue",LVCFMT_CENTER,230,-1); 
	m_list.InsertColumn(2,L"Code Village",LVCFMT_CENTER,230,-1);
	ListView_SetExtendedListViewStyle(m_list,LVS_EX_GRIDLINES); 
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString Numero_Langue,Langue, NumeroVillage;//end variables
   
   m_list.DeleteAllItems();//clear list
   db.Open(L"GestionVacances.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT LANGUE.nomLangue,LANGUE.no_langue,VILLAGE.no_village from LANGUE, VILLAGE, VILLAGE_LANGUE where LANGUE.no_langue=VILLAGE_LANGUE.no_langue and VILLAGE.no_village=VILLAGE_LANGUE.no_village",NULL);
   while(!recset.IsEOF())//do until eof
   {int i=0;
    recset.GetFieldValue(L"no_langue", var);
	Numero_Langue.Format(L"%s",(LPCWSTR)var.pbstrVal);
	m_list.InsertItem(i,Numero_Langue,0);

    recset.GetFieldValue(L"nomLangue",var);
	Langue=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,1,Langue);

	recset.GetFieldValue(L"no_village",var);
	NumeroVillage=(LPCWSTR)var.pbstrVal;
	m_list.SetItemText(i,2,NumeroVillage);
	i=i++;
	recset.MoveNext();  //aller d’un enregistrement à un autre
   }
   
   recset.Close();
   db.Close();
}
void CGestion_GarageDlg::OnBnClickedHome()
{
	// TODO: Add your control notification handler code here

}


void CGestion_GarageDlg::OnAjouterUnVillage()
{

	// TODO: Add your command handler code here

	Ajouter_Village ADDVillage;
	ADDVillage.DoModal();
}


void CGestion_GarageDlg::OnSupprimmerUnVillage()
{
	// TODO: Add your command handler code here
	Supprimmer_Village DELETEVillage;
	DELETEVillage.DoModal();

}



void CGestion_GarageDlg::OnAjouterUnPays()
{
	// TODO: Add your command handler code here
	Ajouter_Pays ADDPays;
	ADDPays.DoModal();

}


void CGestion_GarageDlg::OnModifierUnPays()
{
	// TODO: Add your command handler code here
	Modifier_Pays UpdatePays;
	UpdatePays.DoModal();
}




void CGestion_GarageDlg::OnModifierUnVillage()
{
	// TODO: Add your command handler code here
	Village_Modifier UpdateVillage;
	UpdateVillage.DoModal();
}


void CGestion_GarageDlg::OnSupprimmerUnPays()
{
	// TODO: Add your command handler code here
	Supprimmer_Pays DeletePays;
	DeletePays.DoModal();
}


void CGestion_GarageDlg::OnAjouterUneActivitee()
{
	// TODO: Add your command handler code here
	Ajouter_Activitée ADDActivitée;
	ADDActivitée.DoModal();
}


void CGestion_GarageDlg::OnModifierUneActivitee()
{
	// TODO: Add your command handler code here
	Modifier_Activitée UpdateActivitée;
	UpdateActivitée.DoModal();
}


void CGestion_GarageDlg::OnSupprimmerUneActivitee()
{
	// TODO: Add your command handler code here
	Supprimmer_Activitée DeleteActivitée;
	DeleteActivitée.DoModal();
}


void CGestion_GarageDlg::OnAjouterUneLangue()
{
	// TODO: Add your command handler code here
	Ajouter_Langue ADDLangue;
	ADDLangue.DoModal();
}


void CGestion_GarageDlg::OnModifierUneLangue()
{
	// TODO: Add your command handler code here
	Modifier_Langue UPDATELangue;
	UPDATELangue.DoModal();
}


void CGestion_GarageDlg::OnSupprimmerUneLangue()
{
	// TODO: Add your command handler code here
	Supprimmer_Langue DELETELangue;
	DELETELangue.DoModal();
}


void CGestion_GarageDlg::OnChercherPays()
{
	// TODO: Add your command handler code here
	Chercher_Pays SearchPays;
	SearchPays.DoModal();
}


void CGestion_GarageDlg::OnChercherVillage()
{
	// TODO: Add your command handler code here
	Chercher_Village SearchVillage;
	SearchVillage.DoModal();
}







void CGestion_GarageDlg::OnChercherActivit32810()
{
	// TODO: Add your command handler code here
	Chercher_Activitee SearchActivitee;
	SearchActivitee.DoModal();

}


void CGestion_GarageDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
