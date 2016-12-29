// Win32Project1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project1.h"
#include "my.h"
#include<Commctrl.h>
#include<math.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
/****************************************************************/
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);  //����
INT_PTR CALLBACK    FEEDBACK(HWND, UINT, WPARAM, LPARAM);  //����
/****************************************************************/
INT_PTR CALLBACK    RECOVERY(HWND, UINT, WPARAM, LPARAM);  //���ݻָ�
/****************************************************************/
INT_PTR CALLBACK    categoryq(HWND, UINT, WPARAM, LPARAM); //������Ϣ��ѯ
INT_PTR CALLBACK    gameq(HWND, UINT, WPARAM, LPARAM);     //��Ϸ��Ϣ��ѯ
INT_PTR CALLBACK    playerq(HWND, UINT, WPARAM, LPARAM);   //�����Ϣ��ѯ
INT_PTR CALLBACK    categoryq2(HWND, UINT, WPARAM, LPARAM);  //��ʾ��ѯ�ķ���
INT_PTR CALLBACK    gameq2(HWND, UINT, WPARAM, LPARAM);  //��ʾ��ѯ����Ϸ
INT_PTR CALLBACK    playerq2(HWND, UINT, WPARAM, LPARAM);  //��ʾ��ѯ�����
/****************************************************************/
INT_PTR CALLBACK    add_c(HWND, UINT, WPARAM, LPARAM); //¼�������Ϣ
INT_PTR CALLBACK    maintain_c(HWND, UINT, WPARAM, LPARAM);  //�޸ķ�����Ϣ 
INT_PTR CALLBACK    see_c(HWND, UINT, WPARAM, LPARAM); //ά��������Ϣ
INT_PTR CALLBACK    add_g(HWND, UINT, WPARAM, LPARAM); //¼����Ϸ��Ϣ
INT_PTR CALLBACK    maintain_g(HWND, UINT, WPARAM, LPARAM); //�޸���Ϸ��Ϣ
INT_PTR CALLBACK    see_g(HWND, UINT, WPARAM, LPARAM); //ά����Ϸ��Ϣ
INT_PTR CALLBACK    add_p(HWND, UINT, WPARAM, LPARAM); //¼�������Ϣ
INT_PTR CALLBACK    maintain_p(HWND, UINT, WPARAM, LPARAM); //�޸������Ϣ
INT_PTR CALLBACK    see_p(HWND, UINT, WPARAM, LPARAM); //ά�������Ϣ
/***********************************************************************/
INT_PTR CALLBACK    s1(HWND, UINT, WPARAM, LPARAM);  //ͳ��һ
INT_PTR CALLBACK    si2(HWND, UINT, WPARAM, LPARAM);//ͳ�ƶ�
INT_PTR CALLBACK    s2(HWND, UINT, WPARAM, LPARAM); //ͳ�ƶ�
INT_PTR CALLBACK    s3(HWND, UINT, WPARAM, LPARAM);//ͳ����
INT_PTR CALLBACK    s4(HWND, UINT, WPARAM, LPARAM);//ͳ����
INT_PTR CALLBACK    s5(HWND, UINT, WPARAM, LPARAM);//ͳ����
/**********************************************************************/


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,                //////��������ڣ����г�ʼ������������Ϣѭ��
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))          //��Ϣѭ��
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)         //ע�ᴰ��
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SMALL));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)        //ʵ�������ڲ���ʾ
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, NULL,
      CW_USEDEFAULT, 0, 820, 550, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)      //�����ڻص�����
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:           /*************�˵��Ͱ�ť�¼�*************/
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_32773:		 /////���� 
			backup();
			MessageBox(hWnd, "���ݳɹ����ļ�������ͬĿ¼�£��ļ���Ϊ��ǰϵͳʱ��", "����", MB_OK);
			break;
		case ID_32774:     //�ָ�
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, RECOVERY);
			break;
		case ID_32775:       //����
			savedata();
			isSaved = 1;
			MessageBox(hWnd,"���ݱ���ɹ�","����",MB_OK);
			break;
		case IDM_EXIT: //�˳�
			if (isSaved)
			{
				if (MessageBox(hWnd, "ȷ���˳���", "�˳�", MB_YESNO) == IDYES)
				{
					DestroyWindow(hWnd);

				}
			}
			else
			{
				switch (MessageBox(hWnd, "����δ���棬�Ƿ�Ҫ���棿\n��Ҫ���沢�˳�ѡ�ǣ��粻���沢�˳�ѡ���粻�˳�ѡȡ��", "�˳�", MB_YESNOCANCEL))
				{
				case IDYES:
					savedata();
					DestroyWindow(hWnd);
					break;
				case IDNO:
					DestroyWindow(hWnd);
					break;
				case IDCANCEL:
					break;
				}
			}
			break;
		case ID_32802:  //������Ϸ������Ϣά��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG7), hWnd, see_c);
			break;
		case ID_32803:   //��Ϸ������Ϣά��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG10), hWnd, see_g);
			break;
		case ID_32804:  //��Ϸ��һ�����Ϣά��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG13), hWnd, see_p);
			break;
		case ID_32779: //������Ϸ������Ϣ��ѯ
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, categoryq);
			break;
		case ID_32780:  //��Ϸ������Ϣ��ѯ
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG4), hWnd, gameq);
			break;
		case ID_32781:  //��Ϸ��һ�����Ϣ��ѯ
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG16), hWnd, playerq);
			break;
		case ID_32782:  //������Ϸ��Ϣͳ��                            /**************************************************/
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG18), hWnd, s1);
			break;
		case ID_32783:  //ָ����Ϸ�������Ϣͳ��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG23), hWnd, si2);
			break;
		case ID_32784:  //����Ϸ������Ϣͳ��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG20), hWnd, s3);
			break;
		case ID_32785:  //����Ϸ��ҵ���Ϣͳ��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG21), hWnd, s4);
			break;
		case ID_32786:  //�������������Ϸͳ��
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG22), hWnd,s5);
			break;
		case ID_32787:    //����                                     /*******************************************
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, FEEDBACK);
			break;
		case IDM_ABOUT:  ///����
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:           /************��������¼�************/
		HBRUSH mybrush;
		mybrush = CreateSolidBrush(RGB(223, 242, 245));           //�б����ɫ
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		RECT rect,rect2;	
		rect.left = 0;
		rect.right = 900;
		rect.bottom = 450;
		rect.top = 0;
		FillRect(hdc, &rect, mybrush);
		SetTextColor(hdc, RGB(240, 255, 210));       ///����������ɫ
		SetBkMode(hdc, TRANSPARENT);         //���ñ���ɫ͸��
		mybrush = CreateSolidBrush(RGB(150,160,180));           //�ײ�ɫ��
		rect2.top = 450;
		rect2.bottom = 550;
		rect2.left = 0;
		rect2.right = 820;
		FillRect(hdc, &rect2, mybrush);
		TextOut(hdc,280,470,TEXT("��ӭʹ��������Ϸ��Ϣ����ϵͳ"),28);  //�ײ���ӭ
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:             /********���������¼�**********/
		PostQuitMessage(0);
		break;
	case WM_CREATE:       /********���崴���¼�***************/
	{
		int sw, sh;
		sw = GetSystemMetrics(SM_CXSCREEN);
		sh = GetSystemMetrics(SM_CYSCREEN);
		SetWindowPos(hWnd, HWND_TOPMOST, (sw - 820) / 2, (sh - 550) / 2, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		if (loaddata())       /******��������******/
		{
			MessageBox(hWnd, TEXT("  ��ӭʹ�ã�"), TEXT("������Ϸ��Ϣ����ϵͳ"), MB_OK);
		}
		else
		{
			MessageBox(hWnd, TEXT("  ��ӭʹ�ã�\n  ���ݲ����ڣ��������������ļ���"), TEXT("������Ϸ��Ϣ����ϵͳ"), MB_OK);
			creatdata();
			loaddata();
		}
		//������Ϣ��ʾ����
		listview1 = CreateWindow(WC_LISTVIEW, NULL, WS_CHILD |WS_VISIBLE|LVS_REPORT, 0, 40, 820, 350, hWnd, NULL, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),NULL);
		SendMessage(listview1, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT);
		LV_COLUMN LVC;
		LV_ITEM LVI;
		memset(&LVC, 0, sizeof(LVC));
		memset(&LVI, 0, sizeof(LVI));
		LVC.cx = 200;
		LVC.pszText = "��Ϸ���";
		LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 310;
		LVC.pszText = "��Ϸ����";
		SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVC.cx = 310;
		LVC.pszText = "�������";
		SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
		LVI.mask = LVIF_TEXT|LVIF_STATE;
		LVI.cchTextMax = 100;
		int ci=c,gi,pi,q=-1;
		category *cnow=chead; 
		game *gnow;
		player *pnow;
		while (ci--)               //////��ӡ��Ϣ����Ϣ��ʾ����
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while(gi--)
			{
				pi = gnow->p;
				pnow = gnow->phead;
				while(pi--)
				{
					q++;       //��ʾ���
					LVI.iItem = q;
					LVI.iSubItem = 0;
					LVI.pszText = cnow->code;
					SendMessage(listview1, LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
					LVI.iSubItem = 1;
					LVI.pszText = gnow->name;
					SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
					LVI.iSubItem = 2;
					LVI.pszText = pnow->pname;
					SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
					pnow = pnow->next;
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
		break;
	}
	case WM_MOUSEMOVE:                                        /******����ƶ��¼�********/
		
		break;
	case WM_MOUSEWHEEL:        //�������¼�
		
		break;
	default:        /*******δ��׽�����¼�***********/
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.//******************************************************************************************************************************************//
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)         //����  �Ի���Ļص�����
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:                       //��ʼ���Ի���	
		return (INT_PTR)TRUE;

	case WM_COMMAND:         //�Ի���ť�¼�
		if (LOWORD(wParam) == IDOK||LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	case WM_PAINT:         //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);  //���ñ���ɫ͸��
		EndPaint(hDlg, &ps);
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK FEEDBACK(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)        //����   �Ի���Ļص�����
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��
		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		return (INT_PTR)TRUE;

	case WM_COMMAND:           //�Ի���ť�¼�
		if (LOWORD(wParam) == IDOK||LOWORD(wParam)==IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//****************************************************************************************************************************************************************//
INT_PTR CALLBACK RECOVERY(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)        //�ָ�   �Ի���Ļص�����
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��
		HBRUSH mybrush;
		mybrush = CreateSolidBrush(RGB(223, 242, 245));
		RECT rect;
		GetWindowRect(hDlg, &rect);
		rect.bottom = rect.bottom - rect.top;
		rect.right = rect.right - rect.left;
		rect.left = 0;
		rect.top = 0;
		FillRect(hdc, &rect, mybrush);
		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		char path[100];
		GetCurrentDirectory(100, path);
		strcat(path, "\\*.rec");
		DlgDirList(hDlg, path, IDC_LIST1, NULL, DDL_ARCHIVE);
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
			int index;
			char tagtext[50];
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDOK:      //���ݻָ�
			index = SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);
			if (index != LB_ERR)
			{
				if (MessageBox(hDlg, "�ָ���Ϊ�����ǵ�ǰ�������ļ���ɾ����ǰѡ�еı����ļ���ȷ��Ҫ�ָ���", "�ָ�", MB_OKCANCEL) == IDOK)
				{
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETTEXT, index, (LPARAM)tagtext);
					remove("game.dat");
					rename(tagtext, "game.dat");
					char path[100];
					GetCurrentDirectory(100, path);
					strcat(path, "\\*.rec");
					DlgDirList(hDlg, path, IDC_LIST1, NULL, DDL_ARCHIVE);
					loaddata();
					MessageBox(hDlg, "�ָ��ɹ�", "�ָ�", MB_OK);
				}
			}
			break;
		case IDDEL:       //ɾ������
			index = SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);
			if (index != LB_ERR)
			{
				if (MessageBox(hDlg,"���������棬ȷ��ɾ����","����ɾ��",MB_OKCANCEL)==IDOK)
				{				
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETTEXT, index, (LPARAM)tagtext);
					remove(tagtext);
					char path[100];
					GetCurrentDirectory(100, path);
					strcat(path, "\\*.rec");
					DlgDirList(hDlg, path, IDC_LIST1, NULL, DDL_ARCHIVE);
				}
			}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//****************************************************************************************************************************************************************//
INT_PTR CALLBACK categoryq(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)        //������Ϸ������Ϣ��ѯ  
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��
		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci = c,s=-1;
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		LVC.mask = LVCF_TEXT| LVCF_SUBITEM | LVCF_WIDTH;
		LVC.cx = 90;
		LVC.iSubItem = 0;
		LVC.pszText = "������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1),LVM_INSERTCOLUMN, (WPARAM)0,(LPARAM)&LVC);
		LVC.cx = 170;
		LVC.iSubItem = 1;
		LVC.pszText = "�������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVI.mask = LVIF_TEXT;
		category *cnow = chead;
		while (ci--)
		{
			s++;
			LVI.iItem = s;
			LVI.iSubItem = 0;
			LVI.pszText = cnow->code;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 1;
			LVI.pszText = cnow->description;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			char tepc[20];
			strcpy(tepc, cnow->code);
			SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)s, (LPARAM)tepc);
			strcpy(tepc, cnow->description);
			SendMessage(GetDlgItem(hDlg, IDC_COMBO4), CB_ADDSTRING, (WPARAM)s, (LPARAM)tepc);
			cnow = cnow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDC_BUTTON1:             //��ʾ��ѯ���
		{
			HWND dlg;
			int o = 0;
			char inf[10],inf2[20];
			GetDlgItemText(hDlg, IDC_COMBO1, inf, 10);
			GetDlgItemText(hDlg, IDC_COMBO4, inf2, 20);
			int ci = c,q=-1;
			category *cnow = chead;
			dlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG14), hDlg, categoryq2);
			LVC.mask = LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM;
			LVC.cx = 140;
			LVC.pszText = "�������";
			LVC.iSubItem = 0;
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 280;
			LVC.pszText = "��������";
			LVC.iSubItem = 1;
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);      //��ʼ���������
			while (ci--)
			{
				if (!strcmp(inf, cnow->code) || !strcmp(inf2, cnow->description))
				{
					o = 1;
					q++;
					LVI.mask = LVIF_TEXT;
					LVI.iItem = q;
					LVI.iSubItem = 0;
					LVI.pszText = cnow->code;
					SendMessage(GetDlgItem(dlg, IDC_LIST1),LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 1;
					LVI.pszText = cnow->description;
					SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				}
				cnow = cnow->next;
			}
			if (!o)
			{
				MessageBox(hDlg, "δ�ҵ�������", "������Ϸ������Ϣ��ѯ", MB_OK);
				EndDialog(dlg, LOWORD(wParam));
			}
			break;
		}
		case IDC_BUTTON2:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK gameq(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)        //��Ϸ������Ϣ��ѯ   
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��
		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT);
		LVC.cx = 70;
		LVC.pszText = "��Ϸ���";
		SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 140;
		LVC.pszText = "��Ϸ����";
		SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVC.cx = 280;
		LVC.pszText = "��Ϸ��ַ";
		SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
		LVC.cx = 70;
		LVC.pszText = "�շ�ģʽ";
		SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
		LVC.cx = 70;
		LVC.pszText = "������ʽ";
		SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
		int ci = c, gi,q=-1;
		category *cnow = chead;
		game *gnow;
		while (ci--)
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				q++;
				SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)0, (LPARAM)gnow->name);
				LVI.cchTextMax = 100;
				LVI.iItem = q;
				LVI.iSubItem = 0;
				LVI.pszText = gnow->code;
				SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 1;
				LVI.pszText = gnow->name;
				SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 2;
				LVI.pszText = gnow->address;
				SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 3;
				char tem[2];
				tem[0] = gnow->cmode;
				tem[1] = '\0';
				LVI.pszText = tem;
				SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 4;
				tem[0] = gnow->smode;
				tem[1] = '\0';
				LVI.pszText = tem;
				SendMessage(GetDlgItem(hDlg, IDC_LIST2), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				gnow = gnow->next;
			}
			SendMessage(GetDlgItem(hDlg, IDC_COMBO2),CB_ADDSTRING,(WPARAM)q,(LPARAM)cnow->code);
			cnow = cnow->next;
		}
		SendMessage(GetDlgItem(hDlg, IDC_COMBO4),CB_ADDSTRING, (WPARAM)0, (LPARAM)"��ʽһ");  //��ѯ��ʽ
		SendMessage(GetDlgItem(hDlg, IDC_COMBO4), CB_ADDSTRING, (WPARAM)1, (LPARAM)"��ʽ��");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)0, (LPARAM)"C");      //�շ�ģʽ
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)1, (LPARAM)"P");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)2, (LPARAM)"T");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO5), CB_ADDSTRING, (WPARAM)0, (LPARAM)"P");   //������ʽ
		SendMessage(GetDlgItem(hDlg, IDC_COMBO5), CB_ADDSTRING, (WPARAM)1, (LPARAM)"T");
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDC_BUTTON2:                          //��ѯ
			HWND dlg;
			dlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG15), hDlg, gameq2);
			LVC.cx = 70;
			LVC.pszText = "��Ϸ���";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 140;
			LVC.pszText = "��Ϸ����";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 280;
			LVC.pszText = "��Ϸ��ַ";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVC.cx = 70;
			LVC.pszText = "�շ�ģʽ";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
			LVC.cx = 70;
			LVC.pszText = "������ʽ";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
			char method[7],gname[15],cat[4],charge[2],sort[2];
			GetDlgItemText(hDlg, IDC_COMBO4, method, 7);
			if (!(strcmp(method, "��ʽһ")))
			{
				GetDlgItemText(hDlg, IDC_COMBO1, gname, 15);
				int ci = c, gi, o = 0,q=-1;
				category*cnow = chead;
				game*gnow;
				while (ci--)
				{
					gnow = cnow->ghead;
					gi = cnow->g;
					while (gi--)
					{
						if (!(strcmp(gname, gnow->name)))        //�����Ϸ��Ϣ
						{
							q++;
							o = 1;
							LVI.iItem = q;
							LVI.pszText = gnow->code;
							LVI.iSubItem = 0;
							SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
							LVI.pszText = gnow->name;
							LVI.iSubItem = 1;
							SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
							LVI.pszText = gnow->address;
							LVI.iSubItem = 2;
							SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
							charge[0] = gnow->cmode;
							charge[1] = '\0';
							LVI.pszText = charge;
							LVI.iSubItem = 3;
							SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
							sort[0] = gnow->smode;
							sort[1] = '\0';
							LVI.pszText = sort;
							LVI.iSubItem = 4;
							SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
						}
						gnow = gnow->next;
					}
					cnow = cnow->next;
				}
				if (!o)
				{
					MessageBox(hDlg, "δ�ҵ������Ϸ", "��Ϸ��Ϣ��ѯ", MB_OK);
					EndDialog(dlg, LOWORD(wParam));
				}
			}
			else if (!(strcmp(method, "��ʽ��")))
			{
				GetDlgItemText(hDlg,IDC_COMBO2,cat,4);
				GetDlgItemText(hDlg, IDC_COMBO3,charge,2);
				GetDlgItemText(hDlg, IDC_COMBO5,sort,2);
				if (cat[0] && charge[0] && sort[0])
				{
					int ci = c, o = 0, gi,q=-1;
					category *cnow = chead;
					game *gnow;
					while (ci--)
					{
						if (!(strcmp(cat, cnow->code)))
						{
							gnow = cnow->ghead;
							gi = cnow->g;
							while (gi--)
							{
								if (gnow->cmode == charge[0]&&gnow->smode == sort[0])      //�����Ϸ��Ϣ
								{
									o = 1;
									q++;
									LVI.iItem = q;
									LVI.pszText = gnow->code;
									LVI.iSubItem = 0;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.pszText = gnow->name;
									LVI.iSubItem = 1;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.pszText = gnow->address;
									LVI.iSubItem = 2;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									charge[0] = gnow->cmode;
									charge[1] = '\0';
									LVI.pszText = charge;
									LVI.iSubItem = 3;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									sort[0] = gnow->smode;
									sort[1] = '\0';
									LVI.pszText = sort;
									LVI.iSubItem = 4;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
								}
								gnow = gnow->next;
							}
							break;
						}
						cnow = cnow->next;
					}
					if (!o)
					{
						MessageBox(hDlg, "δ�ҵ������Ϸ", "��Ϸ��Ϣ��ѯ", MB_OK);
						EndDialog(dlg, LOWORD(wParam));
					}
				}
				else
				{
					MessageBox(hDlg,"�벹ȫ��Ϣ","��Ϸ��Ϣ��ѯ",MB_OK);
					EndDialog(dlg, LOWORD(wParam));
				}
			}
			else
			{
				MessageBox(hDlg, "��ѡ��һ�ֲ�ѯ��ʽ", "��Ϸ��Ϣ��ѯ", MB_OK);
				EndDialog(dlg, LOWORD(wParam));
			}
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK playerq(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //��һ�����Ϣ��ѯ
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		SendMessage(GetDlgItem(hDlg, IDC_COMBO6), CB_ADDSTRING, (WPARAM)0, (LPARAM)"��ʽһ");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO6), CB_ADDSTRING, (WPARAM)1, (LPARAM)"��ʽ��");
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		LVC.cx = 100;
		LVC.pszText = "�û���";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "ע������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "��Ϸ����";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "��Ϸ�ۼ�ʱ��";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "�����ܽ��";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "����ָ��";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)5, (LPARAM)&LVC);
		int ci = c, gi, pi, q = -1,Q1=-1;
		category *cnow = chead;
		game *gnow;
		player *pnow;
		while (ci--)
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				Q1++;
				SendMessage(GetDlgItem(hDlg, IDC_COMBO4),CB_ADDSTRING,(WPARAM)Q1,(LPARAM)gnow->name);
				pi = gnow->p;
				pnow = gnow->phead;
				while (pi--)
				{
					q++;
					SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)q, (LPARAM)pnow->pname);
					LVI.iItem = q;
					LVI.iSubItem = 0;
					LVI.pszText = pnow->pname;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 1;
					LVI.pszText = pnow->date;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 2;
					LVI.pszText = pnow->gname;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 3;
					char tep[100];
					sprintf(tep, "%d", pnow->t);
					LVI.pszText = tep;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 4;
					sprintf(tep, "%.2lf", pnow->money);
					LVI.pszText = tep;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 5;
					if (gnow->smode == 'P')
					{
						sprintf(tep, "%.2lf", pnow->iindex.score);
					}
					else
					{
						sprintf(tep, "%d", pnow->iindex.t);
					}
					LVI.pszText = tep;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					pnow = pnow->next;
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDOK:
		{
			char method[7], gname[15], pname[15], date[11];
			double money;
			HWND dlg;
			dlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG17), hDlg, playerq2);
			LVC.cx = 100;
			LVC.pszText = "�û���";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "ע������";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "��Ϸ����";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "��Ϸ�ۼ�ʱ��";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "�����ܽ��";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "����ָ��";
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)5, (LPARAM)&LVC);
			GetDlgItemText(hDlg, IDC_COMBO6, method,7);
			GetDlgItemText(hDlg, IDC_COMBO1, pname, 15);
			GetDlgItemText(hDlg, IDC_COMBO4, gname, 15);
			GetDlgItemText(hDlg, IDC_DATETIMEPICKER1, date, 11);
			money = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, TRUE);
			if (!(strcmp(method, "��ʽһ")))
			{
				category *cnow = chead;
				game*gnow;
				player *pnow;
				int ci = c, o = 0, gi, pi,q=-1;
				while (ci--)
				{
					gnow = cnow->ghead;
					gi = cnow->g;
					while (gi--)
					{
						if (!(strcmp(gname, gnow->name)))
						{
							pnow = gnow->phead;
							pi = gnow->p;
							while (pi--)
							{
								if (!(strcmp(pnow->pname, pname)))
								{
									o = 1;
									q++;
									LVI.iItem = q;
									LVI.iSubItem = 0;
									LVI.pszText = pnow->pname;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.iSubItem = 1;
									LVI.pszText = pnow->date;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.iSubItem = 2;
									LVI.pszText = pnow->gname;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.iSubItem = 3;
									char tep[100];
									sprintf(tep, "%d", pnow->t);
									LVI.pszText = tep;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.iSubItem = 4;
									sprintf(tep, "%.2lf", pnow->money);
									LVI.pszText = tep;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
									LVI.iSubItem = 5;
									if (gnow->smode == 'P')
									{
										sprintf(tep, "%.2lf", pnow->iindex.score);
									}
									else
									{
										sprintf(tep, "%d", pnow->iindex.t);
									}
									LVI.pszText = tep;
									SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
								}
								pnow = pnow->next;
							}
						}
						gnow = gnow->next;
					}
					cnow = cnow->next;
				}
				if (!o)
				{
					MessageBox(hDlg, "δ�ҵ�������", "�����Ϣ��ѯ", MB_OK);
					EndDialog(dlg, LOWORD(wParam));
				}
			}
			else if (!(strcmp(method, "��ʽ��")))
			{
				category *cnow = chead;
				game *gnow;
				player *pnow;
				int ci = c, o = 0, gi, pi,q=-1;
				while (ci--)
				{
					gi = cnow->g;
					gnow = cnow->ghead;
					while (gi--)
					{
						pi = gnow->p;
						pnow = gnow->phead;
						while (pi--)
						{
							if (!(strcmp(date, pnow->date)) && pnow->money >= money)
							{
								o = 1;
								q++;
								LVI.iItem = q;
								LVI.iSubItem = 0;
								LVI.pszText = pnow->pname;
								SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
								LVI.iSubItem = 1;
								LVI.pszText = pnow->date;
								SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
								LVI.iSubItem = 2;
								LVI.pszText = pnow->gname;
								SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
								LVI.iSubItem = 3;
								char tep[100];
								sprintf(tep, "%d", pnow->t);
								LVI.pszText = tep;
								SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
								LVI.iSubItem = 4;
								sprintf(tep, "%.2lf", pnow->money);
								LVI.pszText = tep;
								SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
								LVI.iSubItem = 5;
								if (gnow->smode == 'P')
								{
									sprintf(tep, "%.2lf", pnow->iindex.score);
								}
								else
								{
									sprintf(tep, "%d", pnow->iindex.t);
								}
								LVI.pszText = tep;
								SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
							}
							pnow = pnow->next;
						}
						gnow = gnow->next;
					}
					cnow = cnow->next;
				}
				if (!o)
				{
					MessageBox(hDlg, "δ�ҵ�������", "�����Ϣ��ѯ", MB_OK);
					EndDialog(dlg, LOWORD(wParam));
				}
			}
			else
			{
				MessageBox(hDlg,"��ѡ��ʽ","�����Ϣ��ѯ",MB_OK);
				EndDialog(dlg, LOWORD(wParam));
			}
			break;
		}
		default:
			break;
		}
		break;

	}
	return (INT_PTR)FALSE;
}
//****************************************************************************************************************************************************************//
INT_PTR CALLBACK add_c(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)       //¼�������Ϣ 
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�

		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDOK:                                      //¼���µ���� ���������β��
			char iscode[4],isdescription[15];
			GetDlgItemText(hDlg, IDC_EDIT1, iscode, 4);
			GetDlgItemText(hDlg, IDC_EDIT2, isdescription, 15);
			if (iscode[0]&&isdescription[0])
			{
				category *newcategory,*cnow;
				newcategory = (category*)malloc(sizeof(category));
				newcategory->g = 0;
				newcategory->ghead = NULL;
				newcategory->next = NULL;
				GetDlgItemText(hDlg, IDC_EDIT1, newcategory->code, 4);
				GetDlgItemText(hDlg, IDC_EDIT2, newcategory->description, 15);
				if (c)
				{ 
					cnow = chead;
					int i;
					for (i = 1; i <= c-1; i++)
					{
						cnow = cnow->next;
					}
					cnow->next = newcategory;
				}
				else
				{
					chead = newcategory;
				}
				SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				c++;
				isSaved = 0;
				SendMessage(dia, WM_INITDIALOG, 0, 0);
			}
			else
			{
				MessageBox(hDlg, "�벹ȫ��Ϣ", "������Ϣ¼��", MB_OK);
			}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK maintain_c(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //�޸ķ�����Ϣ
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci;
		category *cnow = chead;
		for (ci = 1; ci <= inde; ci++)
		{
			cnow = cnow->next;
		}
		SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, 0, (LPARAM)cnow->code);
		SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, 0, (LPARAM)cnow->description);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDOK:
		{
			char iscode[4], isdescription[15];
			GetDlgItemText(hDlg, IDC_EDIT1, iscode, 4);
			GetDlgItemText(hDlg, IDC_EDIT2, isdescription, 15);
			category *cnow=chead;
			int ci;
			for (ci = 1; ci <= inde; ci++)
			{
				cnow = cnow->next;
			}
			strcpy(cnow->code, iscode);
			strcpy(cnow->description, isdescription);
			isSaved = 0;
			SendMessage(dia,WM_INITDIALOG,0,0);
		}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK see_c(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ά��������Ϣ
{
	dia = hDlg;
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETEALLITEMS, 0, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 1, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 0, 0);
		int ci = c, s = -1;
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		LVC.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;
		LVC.cx = 160;
		LVC.iSubItem = 0;
		LVC.pszText = "������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 300;
		LVC.iSubItem = 1;
		LVC.pszText = "�������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVI.mask = LVIF_TEXT;
		category *cnow = chead;
		while (ci--)
		{
			s++;
			LVI.iItem = s;
			LVI.iSubItem = 0;
			LVI.pszText = cnow->code;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 1;
			LVI.pszText = cnow->description;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			cnow = cnow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
		{
			SendMessage(listview1, LVM_DELETEALLITEMS, 0, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 2, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 1, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 0, 0);
			LV_COLUMN LVC;
			LV_ITEM LVI;
			memset(&LVC, 0, sizeof(LVC));
			memset(&LVI, 0, sizeof(LVI));
			LVC.cx = 200;
			LVC.pszText = "��Ϸ���";
			LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 310;
			LVC.pszText = "��Ϸ����";
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 310;
			LVC.pszText = "�������";
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVI.mask = LVIF_TEXT | LVIF_STATE;
			LVI.cchTextMax = 100;
			int ci = c, gi, pi, q = -1;
			category *cnow = chead;
			game *gnow;
			player *pnow;
			while (ci--)               //////��ӡ��Ϣ����Ϣ��ʾ����
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					pi = gnow->p;
					pnow = gnow->phead;
					while (pi--)
					{
						q++;       //��ʾ���
						LVI.iItem = q;
						LVI.iSubItem = 0;
						LVI.pszText = cnow->code;
						SendMessage(listview1, LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						LVI.iSubItem = 1;
						LVI.pszText = gnow->name;
						SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						LVI.iSubItem = 2;
						LVI.pszText = pnow->pname;
						SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						pnow = pnow->next;
					}
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
		}
			EndDialog(hDlg, LOWORD(wParam)); 
			break;
		case IDOK:    
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG5),hDlg, add_c);  //¼��
			break;
		case IDC_BUTTON1:       //�޸�
			inde = ListView_GetNextItem(GetDlgItem(hDlg, IDC_LIST1), -1, LVNI_FOCUSED);
			if (inde != -1)
			{
				CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6), hDlg, maintain_c);
			}
			break;
		case IDC_BUTTON3:   //ɾ��
		{
			int ind;
			ind = ListView_GetNextItem(GetDlgItem(hDlg, IDC_LIST1), -1, LVNI_FOCUSED);
			if (ind != -1)
			{
				if (ind == 0)
				{
					chead = chead->next;
				}
				else
				{
					category *cnow =chead;
					int j;
					for (j = 1; j <= ind; j++)
					{
						if (j != 1)
						{
							cnow = cnow->next;
						}
					}
					cnow->next = cnow->next->next;
				}
				c--;
				isSaved = 0;
				SendMessage(hDlg, WM_INITDIALOG, 0, 0);
			}
		}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//****************************************************************************************************************************************************************//
INT_PTR CALLBACK add_g(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)   //¼����Ϸ��Ϣ
{
	char mcode[4], mname[15], maddr[30], mcharge[2], msort[2];
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci = c, q = -1;
		category *cnow = chead;
		while (ci--)
		{
			q++;
			SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)q, (LPARAM)cnow->code);
			cnow = cnow->next;
		}
		SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_ADDSTRING, (WPARAM)0, (LPARAM)"C");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_ADDSTRING, (WPARAM)1, (LPARAM)"P");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_ADDSTRING, (WPARAM)2, (LPARAM)"T");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)0, (LPARAM)"P");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)1, (LPARAM)"T");
		SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)0, (LPARAM)"http://");
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDC_BUTTON1:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
			break;
		case IDC_BUTTON3:
				SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)NULL, (LPARAM)"http://");
			break;
		case IDOK:                  //¼��
			GetDlgItemText(hDlg, IDC_COMBO1,mcode,4);
			GetDlgItemText(hDlg, IDC_EDIT1, mname, 15);
			GetDlgItemText(hDlg, IDC_EDIT2, maddr, 30);
			GetDlgItemText(hDlg, IDC_COMBO2,mcharge, 2);
			GetDlgItemText(hDlg, IDC_COMBO3, msort, 2);
			if (mcode[0] && mname[0] && maddr[7] && mcharge[0] && msort[0])
			{
				int ci = c;
				category *cnow = chead;
				while (ci--)
				{
					if (!strcmp(cnow->code, mcode))
					{
						game*newgame=(game*)malloc(sizeof(game));
						strcpy(newgame->code, mcode);
						strcpy(newgame->name, mname);
						strcpy(newgame->address, maddr);
						newgame->cmode = mcharge[0];
						newgame->smode = msort[0];
						newgame->next = NULL;
						newgame->p = 0;
						newgame->phead = NULL;
						if (cnow->g == 0)
						{
							cnow->ghead = newgame;
						}
						else
						{
							game *gnow = cnow->ghead;
							int gi = cnow->g-1;
							while (gi--)
							{
								gnow = gnow->next;
							}
							gnow->next = newgame;
						}
						(cnow->g)++;
					}
					cnow = cnow->next;
				}
				SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)NULL, (LPARAM)"http://");
				SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				isSaved = 0;
				SendMessage(dia2, WM_INITDIALOG, 0, 0);
			}
			else
			{
				MessageBox(hDlg, "�벹ȫ��Ϣ", "��Ϸ��Ϣ¼��", MB_OK);
			}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK maintain_g(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //�޸���Ϸ��Ϣ
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci = c,gi, q = -1,l=-1;
		category *cnow = chead;
		game *gnow;
		SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_ADDSTRING, (WPARAM)0, (LPARAM)"C");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_ADDSTRING, (WPARAM)1, (LPARAM)"P");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_ADDSTRING, (WPARAM)2, (LPARAM)"T");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)0, (LPARAM)"P");
		SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_ADDSTRING, (WPARAM)1, (LPARAM)"T");
		while (ci--)
		{
			q++;
			gi = cnow->g;
			gnow = cnow->ghead;
			SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)q, (LPARAM)cnow->code);
			while (gi--)
			{
				l++;
				if (l == inde)
				{
					SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_SELECTSTRING, (WPARAM)0, (LPARAM)cnow->code);
					SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)0, (LPARAM)gnow->name);
					SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)0, (LPARAM)gnow->address);
					char t[2];
					t[1] = '\0';
					t[0] = gnow->cmode;
					SendMessage(GetDlgItem(hDlg, IDC_COMBO2), CB_SELECTSTRING, (WPARAM)0, (LPARAM)t);
					t[0] = gnow->smode;
					SendMessage(GetDlgItem(hDlg, IDC_COMBO3), CB_SELECTSTRING, (WPARAM)0, (LPARAM)t);
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
	}
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDC_BUTTON1:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)0, (LPARAM)0);
			break;
		case IDC_BUTTON3:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)0, (LPARAM)0);
			break;
		case IDOK:      //�޸�
		{
			char mcode[4], mname[15], maddr[30], mcharge[2], msort[2];
			GetDlgItemText(hDlg, IDC_COMBO1, mcode, 4);
			GetDlgItemText(hDlg, IDC_EDIT1, mname, 15);
			GetDlgItemText(hDlg, IDC_EDIT2, maddr, 30);
			GetDlgItemText(hDlg, IDC_COMBO2, mcharge, 2);
			GetDlgItemText(hDlg, IDC_COMBO3, msort, 2);
			int ci = c, gi, l = -1;
			category *cnow = chead;
			game *gnow;
			game*newgame = (game*)malloc(sizeof(game));
			while (ci--)
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					l++;
					if (l == inde)
					{
						newgame->phead = gnow->phead;
						if ((gi + 1) == cnow->g)
						{
							cnow->ghead = cnow->ghead->next;
						}
						else
						{
							gnow->next = gnow->next->next;
						}
						cnow->g--;
						isSaved = 0;
					}
					if ((gi + 1) < cnow->g)
					{
						gnow = gnow->next;
					}
				}
				cnow = cnow->next;
			}
		    ci = c;
			cnow = chead;
			while (ci--)
			{
				if (!strcmp(cnow->code, mcode))
				{
					strcpy(newgame->code, mcode);
					strcpy(newgame->name, mname);
					strcpy(newgame->address, maddr);
					newgame->cmode = mcharge[0];
					newgame->smode = msort[0];
					newgame->next = NULL;
					newgame->p = 0;
					newgame->phead = NULL;
					if (cnow->g == 0)
					{
						cnow->ghead = newgame;
					}
					else
					{
						game *gnow = cnow->ghead;
						int gi = cnow->g - 1;
						while (gi--)
						{
							gnow = gnow->next;
						}
						gnow->next = newgame;
					}
					(cnow->g)++;
				}
				cnow = cnow->next;
			}
			SendMessage(dia2, WM_INITDIALOG, 0, 0);
		}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK see_g(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ά����Ϸ��Ϣ
{
	dia2 = hDlg;
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETEALLITEMS, 0, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 4, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 3, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 2, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 1, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 0, 0);
		{
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT);
			LVC.cx = 70;
			LVC.pszText = "��Ϸ���";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 140;
			LVC.pszText = "��Ϸ����";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 280;
			LVC.pszText = "��Ϸ��ַ";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVC.cx = 70;
			LVC.pszText = "�շ�ģʽ";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
			LVC.cx = 70;
			LVC.pszText = "������ʽ";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
			int ci = c, gi, q = -1;
			category *cnow = chead;
			game *gnow;
			while (ci--)
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					q++;
					LVI.cchTextMax = 100;
					LVI.iItem = q;
					LVI.iSubItem = 0;
					LVI.pszText = gnow->code;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 1;
					LVI.pszText = gnow->name;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 2;
					LVI.pszText = gnow->address;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 3;
					char tem[2];
					tem[0] = gnow->cmode;
					tem[1] = '\0';
					LVI.pszText = tem;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 4;
					tem[0] = gnow->smode;
					tem[1] = '\0';
					LVI.pszText = tem;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
		}
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
		{
			SendMessage(listview1, LVM_DELETEALLITEMS, 0, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 2, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 1, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 0, 0);
			LV_COLUMN LVC;
			LV_ITEM LVI;
			memset(&LVC, 0, sizeof(LVC));
			memset(&LVI, 0, sizeof(LVI));
			LVC.cx = 200;
			LVC.pszText = "��Ϸ���";
			LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 310;
			LVC.pszText = "��Ϸ����";
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 310;
			LVC.pszText = "�������";
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVI.mask = LVIF_TEXT | LVIF_STATE;
			LVI.cchTextMax = 100;
			int ci = c, gi, pi, q = -1;
			category *cnow = chead;
			game *gnow;
			player *pnow;
			while (ci--)               //////��ӡ��Ϣ����Ϣ��ʾ����
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					pi = gnow->p;
					pnow = gnow->phead;
					while (pi--)
					{
						q++;       //��ʾ���
						LVI.iItem = q;
						LVI.iSubItem = 0;
						LVI.pszText = cnow->code;
						SendMessage(listview1, LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						LVI.iSubItem = 1;
						LVI.pszText = gnow->name;
						SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						LVI.iSubItem = 2;
						LVI.pszText = pnow->pname;
						SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						pnow = pnow->next;
					}
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
		}
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDC_BUTTON1:       //�޸�
		{
			inde = ListView_GetNextItem(GetDlgItem(hDlg, IDC_LIST1), -1, LVNI_FOCUSED);
			if (inde != -1)
			{
				CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG9), hDlg, maintain_g);
			}
		}
			break;
		case IDOK:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG8), hDlg, add_g);
			break;
		case IDC_BUTTON2:    //ɾ��
		{
			int ind;
			ind = ListView_GetNextItem(GetDlgItem(hDlg,IDC_LIST1), -1, LVNI_FOCUSED);
			if (ind != -1)
			{
				int ci = c, gi, l = -1;
				category *cnow = chead;
				game *gnow;
				while (ci--)
				{
					gi = cnow->g;
					gnow = cnow->ghead;
					while (gi--)
					{
						l++;
						if (l == ind)
						{
							if ((gi + 1) == cnow->g)
							{
								cnow->ghead = cnow->ghead->next;
							}
							else
							{
								gnow->next = gnow->next->next;
							}
							cnow->g--;
							isSaved = 0;
						}
						if ((gi + 1) < cnow->g)
						{
							gnow = gnow->next;
						}
					}
					cnow = cnow->next;
				}
				SendMessage(hDlg, WM_INITDIALOG, 0, 0);
			}
		}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//****************************************************************************************************************************************************************//
INT_PTR CALLBACK add_p(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //¼�������Ϣ
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci = c, gi;
		category *cnow = chead;
		game *gnow;
		while (ci--)
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)0, (LPARAM)gnow->name);
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDOK:         //¼��
		{
			player *newplayer=(player*)malloc(sizeof(player));
			GetDlgItemText(hDlg, IDC_EDIT1, newplayer->pname, 15);
			GetDlgItemText(hDlg, IDC_DATETIMEPICKER1, newplayer->date, 11);
			GetDlgItemText(hDlg, IDC_COMBO1, newplayer->gname, 15);
			newplayer->t = GetDlgItemInt(hDlg, IDC_EDIT2, NULL, TRUE);
			newplayer->money = GetDlgItemInt(hDlg, IDC_EDIT3, NULL, TRUE);
			newplayer->next = NULL;
			if (GetDlgItemInt(hDlg, IDC_EDIT4, NULL, TRUE) && newplayer->money&&newplayer->t&&newplayer->gname[0]&&newplayer->date[0]&&newplayer->pname[0])
			{
				int ci = c, gi, pi, o = 0;
				category *cnow = chead;
				game *gnow;
				player *pnow;
				while (ci--)
				{
					gi = cnow->g;
					gnow = cnow->ghead;
					while (gi--)
					{
						if (!strcmp(gnow->name, newplayer->gname))
						{
							if (gnow->smode == 'P')
							{
								newplayer->iindex.score = (double)GetDlgItemInt(hDlg, IDC_EDIT4, NULL, TRUE);
							}
							else
							{
								newplayer->iindex.t = GetDlgItemInt(hDlg, IDC_EDIT4, NULL, TRUE);
							}
							o = 1;
							if (gnow->p == 0)
							{
								gnow->phead = newplayer;
							}
							else
							{
								pi = (gnow->p) - 1;
								pnow = gnow->phead;
								while (pi--)
								{
									pnow = pnow->next;
								}
								pnow->next = newplayer;
							}						
							(gnow->p)++;
						}
						gnow = gnow->next;
					}
					cnow = cnow->next;
				}
				SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				SendMessage(GetDlgItem(hDlg, IDC_EDIT3), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				SendMessage(GetDlgItem(hDlg, IDC_EDIT4), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
				isSaved = 0;
				SendMessage(dia3, WM_INITDIALOG, 0, 0);
			}
			else
			{
				MessageBox(hDlg, "�벹ȫ��Ϣ", "�����Ϣ¼��", MB_OK);
			}
		}
			break;
		case IDC_BUTTON1:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
			break;
		case IDC_BUTTON3:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
			break;
		case IDC_BUTTON4:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT3), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
			break;
		case IDC_BUTTON5:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT4), WM_SETTEXT, (WPARAM)NULL, (LPARAM)NULL);
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK maintain_p(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //�޸������Ϣ
{
	HWND dlg;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci = c, gi,pi,l=-1;
		category *cnow = chead;
		game *gnow;
		player *pnow;
		while (ci--)
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)0, (LPARAM)gnow->name);
				pi = gnow->p;
				pnow = gnow->phead;
				while (pi--)
				{
					l++;
					if (l == inde)
					{
						SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)0, (LPARAM)pnow->pname);
						SYSTEMTIME stime;
						sscanf(pnow->date, "%u/%u/%u", &(stime.wYear),&(stime.wMonth),&(stime.wDay));
						SendMessage(GetDlgItem(hDlg, IDC_DATETIMEPICKER1), DTM_SETSYSTEMTIME, (WPARAM)GDT_VALID, (LPARAM)&stime);
						SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_SELECTSTRING, (WPARAM)-1, (LPARAM)pnow->gname);
						char tep[100];
						sprintf(tep, "%d", pnow->t);
						SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)0, (LPARAM)tep);
						sprintf(tep, "%d", (int)(pnow->money));
						SendMessage(GetDlgItem(hDlg, IDC_EDIT3), WM_SETTEXT, (WPARAM)0, (LPARAM)tep);
						if (gnow->smode == 'P')
						{
							sprintf(tep, "%d", pnow->iindex.score);
						}
						else
						{
							sprintf(tep, "%d", pnow->iindex.t);
						}
						SendMessage(GetDlgItem(hDlg, IDC_EDIT4), WM_SETTEXT, (WPARAM)0, (LPARAM)tep);
						pnow = pnow->next;
					}
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDC_BUTTON1:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)0, (LPARAM)0);
			break;
		case IDC_BUTTON3:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)0, (LPARAM)0);
			break;
		case IDC_BUTTON4:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT3), WM_SETTEXT, (WPARAM)0, (LPARAM)0);
			break;
		case IDC_BUTTON5:
			SendMessage(GetDlgItem(hDlg, IDC_EDIT4), WM_SETTEXT, (WPARAM)0, (LPARAM)0);
			break;
		case IDOK:          //�޸�
		{
			player *newplayer = (player*)malloc(sizeof(player));
			GetDlgItemText(hDlg, IDC_EDIT1, newplayer->pname, 15);
			GetDlgItemText(hDlg, IDC_DATETIMEPICKER1, newplayer->date, 11);
			GetDlgItemText(hDlg, IDC_COMBO1, newplayer->gname, 15);
			newplayer->t = GetDlgItemInt(hDlg, IDC_EDIT2, NULL, TRUE);
			newplayer->money = GetDlgItemInt(hDlg, IDC_EDIT3, NULL, TRUE);
			newplayer->next = NULL;
			int ci = c, gi, pi, l = -1;
			category *cnow = chead;
			game *gnow;
			player *pnow;
			while (ci--)
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					pi = gnow->p;
					pnow = gnow->phead;
					while (pi--)
					{
						l++;
						if (l == inde)
						{
							if ((pi + 1) == gnow->p)
							{
								gnow->phead = gnow->phead->next;
							}
							else
							{
								pnow->next = pnow->next->next;
							}
							gnow->p--;
						}
						if ((pi + 1) < gnow->p)
						{
							pnow = pnow->next;
						}
					}
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
			ci = c;
			int o = 0;
			cnow = chead;
			while (ci--)
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					if (!strcmp(gnow->name, newplayer->gname))
					{
						if (gnow->smode == 'P')
						{
							newplayer->iindex.score = GetDlgItemInt(hDlg, IDC_EDIT4, NULL, TRUE);
						}
						else
						{
							newplayer->iindex.t = GetDlgItemInt(hDlg, IDC_EDIT4, NULL, TRUE);
						}
						o = 1;
						if (gnow->p == 0)
						{
							gnow->phead = newplayer;
						}
						else
						{
							pi = (gnow->p) - 1;
							pnow = gnow->phead;
							while (pi--)
							{
								pnow = pnow->next;
							}
							pnow->next = newplayer;
						}
						(gnow->p)++;
					}
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
			isSaved = 0;
			SendMessage(dia3, WM_INITDIALOG, 0, 0);

		}
			break;
		default:
			break;
		}
		break;
	case WM_COPYDATA:
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK see_p(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ά�������Ϣ
{
	dia3=hDlg;
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETEALLITEMS, 0, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 5, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 4, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 3, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 2, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 1, 0);
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_DELETECOLUMN, 0, 0);
		{
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
			LVC.cx = 100;
			LVC.pszText = "�û���";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "ע������";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "��Ϸ����";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "��Ϸ�ۼ�ʱ��";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "�����ܽ��";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "����ָ��";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)5, (LPARAM)&LVC);
			int ci = c, gi, pi, q = -1;
			category *cnow = chead;
			game *gnow;
			player *pnow;
			while (ci--)
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					pi = gnow->p;
					pnow = gnow->phead;
					while (pi--)
					{
						q++;
						LVI.iItem = q;
						LVI.iSubItem = 0;
						LVI.pszText = pnow->pname;
						SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
						LVI.iSubItem = 1;
						LVI.pszText = pnow->date;
						SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
						LVI.iSubItem = 2;
						LVI.pszText = pnow->gname;
						SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
						LVI.iSubItem = 3;
						char tep[100];
						sprintf(tep, "%d", pnow->t);
						LVI.pszText = tep;
						SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
						LVI.iSubItem = 4;
						sprintf(tep, "%.2lf", pnow->money);
						LVI.pszText = tep;
						SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
						LVI.iSubItem = 5;
						if (gnow->smode == 'P')
						{
							sprintf(tep, "%.2lf", pnow->iindex.score);
						}
						else
						{
							sprintf(tep, "%d", pnow->iindex.t);
						}
						LVI.pszText = tep;
						SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
						pnow = pnow->next;
					}
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
		}
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
		{
			SendMessage(listview1, LVM_DELETEALLITEMS, 0, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 2, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 1, 0);
			SendMessage(listview1, LVM_DELETECOLUMN, 0, 0);
			LV_COLUMN LVC;
			LV_ITEM LVI;
			memset(&LVC, 0, sizeof(LVC));
			memset(&LVI, 0, sizeof(LVI));
			LVC.cx = 200;
			LVC.pszText = "��Ϸ���";
			LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 310;
			LVC.pszText = "��Ϸ����";
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 310;
			LVC.pszText = "�������";
			SendMessage(listview1, LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVI.mask = LVIF_TEXT | LVIF_STATE;
			LVI.cchTextMax = 100;
			int ci = c, gi, pi, q = -1;
			category *cnow = chead;
			game *gnow;
			player *pnow;
			while (ci--)               //////��ӡ��Ϣ����Ϣ��ʾ����
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					pi = gnow->p;
					pnow = gnow->phead;
					while (pi--)
					{
						q++;       //��ʾ���
						LVI.iItem = q;
						LVI.iSubItem = 0;
						LVI.pszText = cnow->code;
						SendMessage(listview1, LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						LVI.iSubItem = 1;
						LVI.pszText = gnow->name;
						SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						LVI.iSubItem = 2;
						LVI.pszText = pnow->pname;
						SendMessage(listview1, LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);    //������ʾ��Ϣ
						pnow = pnow->next;
					}
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
			break;
		case IDOK:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG11), hDlg, add_p);
			break;
		case IDC_BUTTON1:          //�޸�
		{
			inde = ListView_GetNextItem(GetDlgItem(hDlg, IDC_LIST1), -1, LVNI_FOCUSED);
			if (inde != -1)
			{
				HWND dlg;
				dlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG12), hDlg, maintain_p);
			}
		}
			break;
		case IDC_BUTTON2:           //ɾ��
		{
			int ind;
			ind = ListView_GetNextItem(GetDlgItem(hDlg,IDC_LIST1), -1, LVNI_FOCUSED);
			if (ind != -1)
			{
				int ci = c, gi, pi, l = -1;
				category *cnow = chead;
				game *gnow;
				player *pnow;
				while (ci--)
				{
					gi = cnow->g;
					gnow = cnow->ghead;
					while (gi--)
					{
						pi = gnow->p;
						pnow = gnow->phead;
						while (pi--)
						{
							l++;
							if (l == ind)
							{
								if ((pi + 1) == gnow->p)
								{
									gnow->phead = gnow->phead->next;
								}
								else
								{
									pnow->next = pnow->next->next;
								}
								gnow->p--;
								isSaved = 0;
							}
							if ((pi + 1) < gnow->p)
							{
								pnow = pnow->next;
							}
						}
						gnow = gnow->next;
					}
					cnow = cnow->next;
				}
				SendMessage(hDlg, WM_INITDIALOG, 0, 0);
			}
		}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE; 
}
//****************************************************************************************************************************************************************//
INT_PTR CALLBACK categoryq2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //��ʾ��ѯ�ķ���
{
    PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK gameq2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //��ʾ��ѯ����Ϸ
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK playerq2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //��ʾ��ѯ�����
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի���T1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		return (INT_PTR)TRUE;��ʼ���¼�
		SendMessage(GetDlgItem(hDlg, IDC_LIS
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//****************************************************************************************************************************************************************//
/***************************************************************************************************************************************************/
INT_PTR CALLBACK s1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ͳ��һ
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		{
			LVC.cx = 70;
			LVC.pszText = "��Ϸ����";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
			LVC.cx = 100;
			LVC.pszText = "�����";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
			LVC.cx = 150;
			LVC.pszText = "�����Ϸ��ʱ��(Сʱ)";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
			LVC.cx = 150;
			LVC.pszText = "����˾���Ϸʱ��";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
			LVC.cx = 150;
			LVC.pszText = "��������ܽ��(Ԫ)";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
			LVC.cx = 150;
			LVC.pszText = "����˾����ѽ��";
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)5, (LPARAM)&LVC);
			int ci = c, gi, pi, q = -1;
			double amoney;
			long atime;
			category *cnow = chead;
			game *gnow;
			player *pnow;
			while (ci--)
			{
				gi = cnow->g;
				gnow = cnow->ghead;
				while (gi--)
				{
					q++;
					atime = 0;
					amoney = 0;
					pi = gnow->p;
					pnow = gnow->phead;
					while (pi--)
					{
						atime += pnow->t;
						amoney += pnow->money;
						pnow = pnow->next;
					}
					LVI.iItem = q;
					LVI.iSubItem = 0;
					LVI.pszText = gnow->name;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 1;
					char temp[100];
					sprintf(temp, "%d", gnow->p);
					LVI.pszText = temp;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 2;
					sprintf(temp, "%ld", atime);
					LVI.pszText = temp;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 3;
					if (gnow->p == 0){
						sprintf(temp, "%.1lf", 0);
					}
					else
					{
						sprintf(temp, "%.1lf", (double)(atime) / gnow->p);
					}
					LVI.pszText = temp;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 4;
					sprintf(temp, "%.2lf", amoney);
					LVI.pszText = temp;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 5;
					if (gnow->p == 0){
						sprintf(temp, "%.1lf", 0);
					}
					else
					{
						sprintf(temp, "%.2lf", amoney / gnow->p);
					}
					LVI.pszText = temp;
					SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					gnow = gnow->next;
				}
				cnow = cnow->next;
			}
		}
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK si2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ͳ�ƶ�
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		int ci = c,gi,q=-1;
		category *cnow = chead;
		game* gnow;
		while (ci--)
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				q++;
				SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, (WPARAM)q, (LPARAM)gnow->name);
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
	}
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		case IDOK:    //��ѯ
		{
			char name[15];
			union in{
				long t;
				double s;
			};
			typedef struct playerinf{
				char name[15];
				int time;
				double money;
				union in index;
			}playerinf;
			typedef struct pia{
				playerinf *pi;
				struct pia *next;
			}pia;
			playerinf *pitemp;
			char smode;
			int pnum;
			GetDlgItemText(hDlg, IDC_COMBO1, name, 15);
			HWND dlg;
			dlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG19), hDlg, s2);
			SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
			{
				LVC.cx = 70;
				LVC.pszText = "����";
				SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
				LVC.cx = 100;
				LVC.pszText = "�û���";
				SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
				LVC.cx = 150;
				LVC.pszText = "��Ϸ�ۼ�ʱ��";
				SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
				LVC.cx = 150;
				LVC.pszText = "�����ܶ�";
				SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
				LVC.cx = 150;
				LVC.pszText = "����ָ��";
				SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
			}
			if (name[0])
			{
				int ci = c, gi, pi, q = -1,o=0,as=0;
				category *cnow = chead;
				game *gnow;
				player *pnow;
				pia *piahead,*pianow;
				while (ci--)
				{
					gi = cnow->g;
					gnow = cnow->ghead;
					while (gi--)
					{
						if (!(strcmp(gnow->name, name)))
						{
							o = 1;
							SendMessage(GetDlgItem(dlg, IDC_EDIT1), WM_SETTEXT, (WPARAM)0, (LPARAM)gnow->code);
							SendMessage(GetDlgItem(dlg, IDC_EDIT2), WM_SETTEXT, (WPARAM)0, (LPARAM)gnow->name);
							char tt[2];
							tt[0] = gnow->smode;
							smode = gnow->smode;
							tt[1] = '\0';
							SendMessage(GetDlgItem(dlg, IDC_EDIT5), WM_SETTEXT, (WPARAM)0, (LPARAM)tt);
							pi = gnow->p;
							pnum = gnow->p;
							pnow = gnow->phead;
							while (pi--)
							{
								if (as)
								{
									pianow->next = (pia*)malloc(sizeof(pia));
									pianow = pianow->next;
									pianow->pi = (playerinf*)malloc(sizeof(playerinf));
								}
								else
								{
									as = 1;
									piahead = (pia*)malloc(sizeof(pia));
									pianow = piahead;
									pianow->pi = (playerinf*)malloc(sizeof(playerinf));
								}
								pianow->pi->time = pnow->t;
								strcpy(pianow->pi->name,pnow->pname);
								pianow->pi->money = pnow->money;
								if ((gnow->smode) == 'P')
								{
									pianow->pi->index.s = pnow->iindex.score;
								}
								else
								{
									pianow->pi->index.t = pnow->iindex.t;
								}
								pnow = pnow->next;
								pianow->next = NULL;
							}
						}
						gnow = gnow->next;
					}
					cnow = cnow->next;
				}
				if (!o)
				{
					MessageBox(hDlg, "δ�ҵ������Ϸ��Ϣ", "ָ����Ϸ�������Ϣͳ��", MB_OK);
					EndDialog(dlg, LOWORD(wParam));
					break;
				}                           ///////////////////���ϻ������������Ϣ  ������ piahead��������  ��������
				///////////////////����/////////////////////////////////////////
				int i, j;
				if (smode == 'P')
				{
					for (i = 1; i < pnum; i++)
					{
						pianow = piahead;
						for (j = 1; j < pnum; j++)
						{
							if (pianow->pi->index.s < pianow->next->pi->index.s)
							{
								pitemp = pianow->pi;
								pianow->pi = pianow->next->pi;
								pianow->next->pi = pitemp;
							}
							pianow = pianow->next;
						}
					}
				}
				else
				{
					for (i = 1; i < pnum; i++) 
					{
						pianow = piahead;
						for (j = 1; j < pnum; j++)
						{
							if (pianow->pi->index.t>pianow->next->pi->index.t)
							{
								pitemp = pianow->pi;
								pianow->pi = pianow->next->pi;
								pianow->next->pi = pitemp;
							}
							pianow = pianow->next;
						}
					}
				}
				////////////////////////////////////////////////////׼�����////////////////////
				pianow = piahead;
				for (i = 0; i < pnum; i++)
				{
					LVI.iItem = i;
					LVI.iSubItem = 0;
					char tem[10];
					sprintf(tem, "%d", i+1);
					LVI.pszText = tem;
					SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 1;
					LVI.pszText = pianow->pi->name;
					SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 2;
					sprintf(tem, "%d", pianow->pi->time);
					LVI.pszText = tem;
					SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 3;
					sprintf(tem, "%.1lf", pianow->pi->money);
					LVI.pszText = tem;
					SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					LVI.iSubItem = 4;
					if (smode == 'P')
					{
						sprintf(tem, "%.2lf", pianow->pi->index.s);
						if (!strcmp("-0.00", tem))
						{
							strcpy(tem, "0.00");
						}
					}
					else
					{
						sprintf(tem, "%d", pianow->pi->index.t);
					}
					LVI.pszText = tem;
					SendMessage(GetDlgItem(dlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
					pianow = pianow->next;
				}
            }
			else
			{
				MessageBox(hDlg, "�벹ȫ��Ϣ", "ָ����Ϸ�������Ϣͳ��", MB_OK);
				EndDialog(dlg, LOWORD(wParam));
			}
		}
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK s2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ͳ�ƶ�
{
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
		
		return (INT_PTR)TRUE;
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK s3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ͳ����
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		LVC.cx = 70;
		LVC.pszText = "��Ϸ���";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "�������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "��Ϸ����";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "�����";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "�����Ϸ��ʱ��";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
		LVC.cx = 100;
		LVC.pszText = "��������ܽ��";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)5, (LPARAM)&LVC);
		////////////////////////////////////////////////////////////////////////////////////////////////////
		typedef struct categoryinf{
			char code[4];
			char description[15];
			int g;
			int p;
			int t_p_time;
			double t_p_money;
		}categoryinf;
		typedef struct cia{
			struct categoryinf *ci;
			struct cia *next;
		}cia;
		cia *ciahead, *cianow;
		category *cnow = chead;
		categoryinf *citemp;
		int ci = c, gi, pi, o = 0;
		game *gnow;
		player *pnow;
		while (ci--)                         //������Ϣ
		{
			if (o)
			{
				cianow->next = (cia*)malloc(sizeof(cia));
				cianow = cianow->next;
				cianow->ci = (categoryinf*)malloc(sizeof(categoryinf));
			}
			else
			{
				o = 1;
				ciahead = (cia*)malloc(sizeof(cia));
				cianow = ciahead;
				cianow->ci = (categoryinf*)malloc(sizeof(categoryinf));
			}
			strcpy(cianow->ci->code, cnow->code);
			strcpy(cianow->ci->description, cnow->description);
			cianow->ci->g = cnow->g;
			cianow->ci->p = 0;
			cianow->ci->t_p_money = 0;
			cianow->ci->t_p_time = 0;
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				cianow->ci->p += gnow->p;
				pi = gnow->p;
				pnow = gnow->phead;
				while (pi--)
				{
					cianow->ci->t_p_money += pnow->money;
					cianow->ci->t_p_time += pnow->t;
					pnow = pnow->next;
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
			cianow->next = NULL;
		}
		//////////////////////////////////////����
		int i, j;
		for (i = 1; i < c; i++)
		{
			cianow = ciahead;
			for (j = 1; j < c; j++)
			{
				if (cianow->ci->p < cianow->next->ci->p)
				{
					citemp = cianow->ci;
					cianow->ci = cianow->next->ci;
					cianow->next->ci = citemp;
				}
				cianow = cianow->next;
			}
		}
		/////////////////////////////////////���
		cianow = ciahead;
		for (i = 0; i < c; i++)
		{
			LVI.iItem = i;
			LVI.iSubItem = 0;
			char tem[10];
			LVI.pszText = cianow->ci->code;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 1;
			LVI.pszText = cianow->ci->description;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 2;
			sprintf(tem, "%d", cianow->ci->g);
			LVI.pszText = tem;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 3;
			sprintf(tem, "%d", cianow->ci->p);
			LVI.pszText = tem;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 4;
			sprintf(tem, "%d", cianow->ci->t_p_time);
			LVI.pszText = tem;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 5;
			sprintf(tem, "%.2lf", cianow->ci->t_p_money);
			LVI.pszText = tem;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
			cianow = cianow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK s4(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ͳ����
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�
	{
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		LVC.cx = 70;
		LVC.pszText = "�û���";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 150;
		LVC.pszText = "��Ϸ�ۼ�ʱ��(Сʱ)";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVC.cx = 150;
		LVC.pszText = "�����ܽ��(Ԫ)";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
		int ci = c,gi,pi,q=-1,pianum=0,i,flag=0;
		category *cnow = chead;
		typedef struct playerinf
		{
			char name[15];
			int t;
			double money;
		}playerinf;
		typedef struct pia
		{
			struct playerinf *pi;
			struct pia *next;
		}pia;
		int o = 0;
		game *gnow;
		player *pnow;
		pia *pianow, *piahead,*pianow2;
		while (ci--)                 //��ȡ��Ϣ�������Ϣ������
		{
			gi = cnow->g;
			gnow = cnow->ghead;
			while (gi--)
			{
				pi = gnow->p;
				pnow = gnow->phead;
				while (pi--)
				{
					if (o)
					{
						pianow2 = piahead;
						for (i = 1; i <= pianum; i++)
						{
							if (!strcmp(pianow2->pi->name, pnow->pname))      //�ж��Ƿ���ֹ����
							{
								flag = 1;
								break;
							}
							pianow2 = pianow2->next;
						}
						if (flag)
						{         ////�Ѵ���
							pianow2->pi->money += pnow->money;
							pianow2->pi->t += pnow->t;  
							flag = 0;
						}
						else
						{
							/////////������
							pianow->next = (pia*)malloc(sizeof(pia));
							pianow = pianow->next;
							pianow->pi = (playerinf*)malloc(sizeof(playerinf));
							strcpy(pianow->pi->name, pnow->pname);
							pianow->pi->money = pnow->money;
							pianow->pi->t = pnow->t;
							pianum++;
							pianow->next = NULL;
						}
					}
					else
					{
						piahead = (pia*)malloc(sizeof(pia));
						pianow = piahead;
						pianow->pi = (playerinf*)malloc(sizeof(playerinf));
						strcpy(pianow->pi->name, pnow->pname);
						pianow->pi->money = pnow->money;
						pianow->pi->t = pnow->t;
						pianum++;
						pianow->next = NULL;
						o = 1;
					}
					pnow = pnow->next;
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
		///////////////////////////////׼������
		playerinf *temp;
		int j, k;
		for (j = 1; j < pianum; j++)
		{
			pianow = piahead;
			for (k = 1; k < pianum; k++)
			{
				if (pianow->pi->t<pianow->next->pi->t)
				{
					temp = pianow->pi;
					pianow->pi = pianow->next->pi;
					pianow->next->pi = temp;
				}
				pianow = pianow->next;
			}
		}
		///////////////////////////׼�����
		pianow = piahead;
		for (i = 1; i <= pianum; i++)
		{
			////���
			q++;
			LVI.iItem = q;
			LVI.iSubItem = 0;
			LVI.pszText = pianow->pi->name;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
			LVI.iSubItem = 1;
			char t[100];
			sprintf(t, "%d", pianow->pi->t);
			LVI.pszText =t;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)1, (LPARAM)&LVI);
			LVI.iSubItem = 2;
			sprintf(t,"%.2lf",pianow->pi->money);
			LVI.pszText = t;
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)2, (LPARAM)&LVI);
			pianow = pianow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK s5(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)  //ͳ����
{
	LV_COLUMN LVC;
	LV_ITEM LVI;
	memset(&LVC, 0, sizeof(LVC));
	LVC.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	LVI.mask = LVIF_TEXT;
	PAINTSTRUCT ps;
	HDC hdc;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_PAINT:          //�Ի�������¼�
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		SetBkMode(hdc, TRANSPARENT);     //���ñ���ɫ͸��

		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:	                //�Ի����ʼ���¼�	
	{
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETEXTENDEDLISTVIEWSTYLE, (WPARAM)0, (LPARAM)LVS_EX_FULLROWSELECT);
		LVC.cx = 70;
		LVC.pszText = "��Ϸ���";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&LVC);
		LVC.cx = 140;
		LVC.pszText = "��Ϸ����";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&LVC);
		LVC.cx = 140;
		LVC.pszText = "�������";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&LVC);
		LVC.cx = 260;
		LVC.pszText = "��Ϸ��ַ";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&LVC);
		LVC.cx = 70;
		LVC.pszText = "�շ�ģʽ";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&LVC);
		LVC.cx = 70;
		LVC.pszText = "������ʽ";
		SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTCOLUMN, (WPARAM)5, (LPARAM)&LVC);
		/////////////////////////////////////////////////////////////////////////////////////////��ȡ����
		category *cnow = chead;
		game *gnow, *hotgamehead, *hotgamenow;
		int ci = c, gi, o = 0;
		while (ci--)
		{
			if (o)
			{
				hotgamenow->next = (game*)malloc(sizeof(game));
				hotgamenow = hotgamenow->next;
			}
			else
			{
				o = 1;
				hotgamehead = (game*)malloc(sizeof(game));
				hotgamenow = hotgamehead;
			}
			gi = cnow->g - 1;
			gnow = cnow->ghead;
			if (cnow->g>0)
			{
				strcpy(hotgamenow->address, gnow->address);
				strcpy(&(hotgamenow->cmode), &(gnow->cmode));
				strcpy(hotgamenow->code, gnow->code);
				strcpy(hotgamenow->name, gnow->name);
				strcpy(&(hotgamenow->smode), &(gnow->smode));
				hotgamenow->p = gnow->p;
				hotgamenow->phead = NULL;
				hotgamenow->next = NULL;
			}
			while (gi-->0)
			{
				if (gnow->p < gnow->next->p)
				{
					strcpy(hotgamenow->address, gnow->next->address);
					hotgamenow->cmode = gnow->next->cmode;
					strcpy(hotgamenow->code, gnow->next->code);
					strcpy(hotgamenow->name, gnow->next->name);
					hotgamenow->smode = gnow->next->smode;
					hotgamenow->p = gnow->next->p;
					hotgamenow->phead = NULL;
					hotgamenow->next = NULL;
				}
				gnow = gnow->next;
			}
			cnow = cnow->next;
		}
		/////////////////////////////////////////////////////////////�������
		ci = c;
		int q = -1;
		cnow = chead;
		hotgamenow = hotgamehead;
		while (ci--)
		{
			if (cnow->g>0)
			{
				q++;
				LVI.iItem = q;
				LVI.iSubItem = 0;
				LVI.pszText = hotgamenow->code;
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 1;
				LVI.pszText = hotgamenow->name;
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 2;
				char t[50];
				sprintf(t, "%d",hotgamenow->p);
				LVI.pszText = t;
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 3;
				LVI.pszText = hotgamenow->address;
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 4;
				sprintf(t, "%c", hotgamenow->cmode);
				LVI.pszText = t;
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				LVI.iSubItem = 5;
				sprintf(t, "%c", hotgamenow->smode);
				LVI.pszText = t;
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LVM_SETITEM, (WPARAM)0, (LPARAM)&LVI);
				hotgamenow = hotgamenow->next;
			}
			cnow = cnow->next;
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:           //�Ի���ť�¼�
		switch (LOWORD(wParam))
		{
		case IDCANCEL:          //����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}