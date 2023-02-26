#include <Windows.h>
#include "resource.h"
CONST CHAR gsz_DEFAULT_LOGIN_MESSAGE[] = { "Введите имя пользователя" };
CONST CHAR gsz_DEFAULT_PASSWORD_MESSAGE[] = { "Пароль" };
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
	MessageBox(NULL, "Привет МИР!", "Hello", MB_OK/*MB_YESNOCANSEL*/ | MB_ICONERROR /*или другие */);
	// NULL - родительское окно,значит отсутствует
	// 2- сообщение 
	// 3 - заголовок
	// 4 MB_OK - флаги, опредеделяющие набор кнопок и значек окна
	// флаги - это биты показывающие что включено, а что нет 
	//максимально колличество кнопок 4
	//другая инфа в инете  
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:// отрабатывает при запуске окна и может создавать элементы окна
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		HWND hEditLodin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
		SendMessage(hEditLodin, WM_SETTEXT, 0, (LPARAM)gsz_DEFAULT_LOGIN_MESSAGE);
		SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)gsz_DEFAULT_PASSWORD_MESSAGE);
	}
	break;
	case WM_COMMAND://отобращает сообщение нажата на кнопку и т.д
	{
		HWND hEditLodin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
		CONST INT SIZE = 256;
		CHAR sz_buffer[SIZE] = {};
		switch (LOWORD(wParam))//параметр младшего слова
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
		case IDOK: MessageBox(hwnd, "Была нажата кнопка ОК", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;
}