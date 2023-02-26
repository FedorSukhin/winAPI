#include <Windows.h>
#include "resource.h"
CONST CHAR gsz_DEFAULT_LOGIN_MESSAGE[] = { "������� ��� ������������" };
CONST CHAR gsz_DEFAULT_PASSWORD_MESSAGE[] = { "������" };
//g - GLOBAL
//sz - string Zero
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/*
------------------------
LP -Long Pointer
SPR - String
LPSTR - Long pointer to string
------------------------
*/
//#define MESSAGE_BOX
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
#ifdef MESSAGE_BOX
	MessageBox(NULL, "������ ���!", "Hello", MB_OK/*MB_YESNOCANSEL*/ | MB_ICONERROR /*��� ������ */);
	// NULL - ������������ ����,������ �����������
	// 2- ��������� 
	// 3 - ���������
	// 4 MB_OK - �����, �������������� ����� ������ � ������ ����
	// ����� - ��� ���� ������������ ��� ��������, � ��� ��� 
	//����������� ����������� ������ 4
	//������ ���� � �����  
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:// ������������ ��� ������� ���� � ����� ��������� �������� ����
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		HWND hEditLodin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
		SendMessage(hEditLodin, WM_SETTEXT, 0, (LPARAM)gsz_DEFAULT_LOGIN_MESSAGE);
		SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)gsz_DEFAULT_PASSWORD_MESSAGE);
	}
	break;
	case WM_COMMAND://���������� ��������� ������ �� ������ � �.�
	{
		HWND hEditLodin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
		CONST INT SIZE = 256;
		CHAR sz_buffer[SIZE] = {};
		switch (LOWORD(wParam))//�������� �������� �����
		{
		case IDC_EDIT_LOGIN:
			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				SendMessage(hEditLodin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				if (strcmp(sz_buffer, gsz_DEFAULT_LOGIN_MESSAGE) == 0)
					SendMessage(hEditLodin, WM_SETTEXT, 0, (LPARAM)"");
			}
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				SendMessage(hEditLodin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				if (strcmp(sz_buffer, "") == 0)
					SendMessage(hEditLodin, WM_SETTEXT, 0, (LPARAM)gsz_DEFAULT_LOGIN_MESSAGE);
			}
			break;
		case IDC_EDIT_PASSWORD:
			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				SendMessage(hEditPassword, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				if (strcmp(sz_buffer, gsz_DEFAULT_PASSWORD_MESSAGE) == 0)
					SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)"");
			}
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				SendMessage(hEditPassword, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				if (strcmp(sz_buffer, "") == 0)
					SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)gsz_DEFAULT_PASSWORD_MESSAGE);
			}
			break;
		case IDC_BUTTON_COPY:
		{
			SendMessage(hEditLodin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		case IDOK: MessageBox(hwnd, "���� ������ ������ ��", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;
}