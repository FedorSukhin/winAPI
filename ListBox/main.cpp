#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "resource.h"
#include <cstdio>


CONST CHAR* g_sz_Param[] = { "Param1","Param2","Param3________","Param4" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT WINAPI WinMain(HINSTANCE hInstanse, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstanse, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		for (size_t i = 0; i < sizeof(g_sz_Param) / sizeof(g_sz_Param[0]); i++)
		{
			SendMessage(hwnd, LB_ADDSTRING, 0, (LPARAM)g_sz_Param[i]);
		}
	}break;
	case WM_COMMAND:
	{
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		switch (LOWORD(lParam))
		{
		
		case IDOK: {}
				 break;
		case IDCANCEL: EndDialog(hwnd, 0);
		}
	}
	break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
//#include <cstdio>
//#include  "resource.h"
//
//CONST CHAR* g_sz_STRING[] = { "This", "is", "my", "First", "List", "Box" };
//
//BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
//{
//	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
//	return 0;
//}
//
//BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//	{
//		HWND hCombo = GetDlgItem(hwnd, IDC_LIST1);
//		for (int i = 0; i < sizeof(g_sz_STRING) / sizeof(g_sz_STRING[0]); i++)
//		{
//			SendMessage(hCombo, LB_ADDSTRING, 0, (LPARAM)g_sz_STRING[i]);
//		}
//	}
//	break;
//	case WM_COMMAND:
//	{
//		CONST INT SIZE = 256;
//		CHAR sz_buffer[SIZE] = {};
//		CHAR sz_message[SIZE] = {};
//		HWND hCombo = GetDlgItem(hwnd, IDC_LIST1);
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//		{
//			int i  = (hCombo, LB_GETCURSEL, 0, 0);
//			SendMessage(hCombo, LB_GETTEXT, i, (LPARAM)sz_buffer);
//	/*		sprintf(sz_massage, "Вы выбрали пункт N%i, со значеникм %s", i + 1, sz_buffer);
//				MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);*/
//		}
//		break;
//		case IDCANCEL: EndDialog(hwnd, 0); break;
//		}
//	}
//	break;
//	case WM_CLOSE: EndDialog(hwnd, 0);
//	}
//	return FALSE;
//}
