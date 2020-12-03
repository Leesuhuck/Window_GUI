
#include "default.h"

#define ID_BUTTON_1 1001
#define ID_BUTTON_2 1002
#define ID_BUTTON_3 1003
#define ID_BUTTON_Show 1004
#define ID_BUTTON_Hide 1005
//
BOOL APIENTRY Console_Gui_For_MainEditor_Proc( HWND hdlg , UINT msg , WPARAM wParam , LPARAM lParam ) {
	HWND h;
	switch ( msg ) {
			
		case WM_DROPFILES:
			return TRUE;
			//
		case WM_CREATE:
			CreateWindowEx(0, "button", "A", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, 0, 0, 100, 100, hdlg, (HMENU)ID_BUTTON_1, GetModuleHandle(NULL), NULL);
			CreateWindowEx(0, "button", "B", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, 120, 0, 100, 100, hdlg, (HMENU)ID_BUTTON_2, GetModuleHandle(NULL), NULL);
			CreateWindowEx(0, "button", "C", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, 240, 0, 100, 100, hdlg, (HMENU)ID_BUTTON_3, GetModuleHandle(NULL), NULL);
			CreateWindowEx(0, "button", "Show", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, 60, 120, 100, 100, hdlg, (HMENU)ID_BUTTON_Show, GetModuleHandle(NULL), NULL);
			CreateWindowEx(0, "button", "Hide", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, 180, 120, 100, 100, hdlg, (HMENU)ID_BUTTON_Hide, GetModuleHandle(NULL), NULL);

			h = GetDlgItem(hdlg, ID_BUTTON_1); EnableWindow(h, TRUE);
			h = GetDlgItem(hdlg, ID_BUTTON_2); EnableWindow(h, FALSE);
			h = GetDlgItem(hdlg, ID_BUTTON_3); EnableWindow(h, FALSE);
			return TRUE;

		case WM_TIMER :
			return TRUE;

		case WM_SIZE:
			return TRUE;

		case WM_NOTIFY:
			return FALSE;

		case WM_DRAWITEM:
			return TRUE;

		case WM_KEYDOWN :
			return TRUE;

		case WM_CHAR:
			return TRUE;

		case WM_KEYUP:
			return TRUE;

		case WM_MOUSEWHEEL :
			return 0;

		case WM_HSCROLL:
		case WM_VSCROLL:
			return TRUE;

		case WM_PAINT:
			printf("Paint");
			return( DefWindowProc( hdlg, msg, wParam, lParam ) );

		case WM_LBUTTONDOWN:
			return TRUE;

		case WM_MOUSEMOVE:
			return TRUE;

		case WM_LBUTTONDBLCLK :
			return TRUE;

		case WM_LBUTTONUP :
			return TRUE;

		case WM_RBUTTONDOWN:
			return TRUE;

		case WM_DESTROY:
			return TRUE;

		case WM_CLOSE:
			printf("WM_Close()\n");
			DestroyWindow(hdlg);
			return TRUE;

		case WM_COMMAND:

			switch (wParam)
			{
			case ID_BUTTON_1:
				printf("버튼1입니다\n");
				h = GetDlgItem(hdlg, ID_BUTTON_1); EnableWindow(h, FALSE);
				h = GetDlgItem(hdlg, ID_BUTTON_2); EnableWindow(h, TRUE);
				h = GetDlgItem(hdlg, ID_BUTTON_3); EnableWindow(h, FALSE);
				break;
			case ID_BUTTON_2:
				printf("버튼2입니다\n");
				h = GetDlgItem(hdlg, ID_BUTTON_1); EnableWindow(h, FALSE);
				h = GetDlgItem(hdlg, ID_BUTTON_2); EnableWindow(h, FALSE);
				h = GetDlgItem(hdlg, ID_BUTTON_3); EnableWindow(h, TRUE);
				break;
			case ID_BUTTON_3:
				printf("버튼3입니다\n");
				h = GetDlgItem(hdlg, ID_BUTTON_1); EnableWindow(h, TRUE);
				h = GetDlgItem(hdlg, ID_BUTTON_2); EnableWindow(h, FALSE);
				h = GetDlgItem(hdlg, ID_BUTTON_3); EnableWindow(h, FALSE);
				break;
			case ID_BUTTON_Show:
				printf("버튼쇼입니다\n");
				h = GetDlgItem(hdlg, ID_BUTTON_1); ShowWindow(h, SW_SHOW);
				h = GetDlgItem(hdlg, ID_BUTTON_2); ShowWindow(h, SW_SHOW);
				h = GetDlgItem(hdlg, ID_BUTTON_3); ShowWindow(h, SW_SHOW);
				break;
			case ID_BUTTON_Hide:
				printf("버튼 하이드입니다\n");
				h = GetDlgItem(hdlg, ID_BUTTON_1); ShowWindow(h, SW_HIDE);
				h = GetDlgItem(hdlg, ID_BUTTON_2); ShowWindow(h, SW_HIDE);
				h = GetDlgItem(hdlg, ID_BUTTON_3); ShowWindow(h, SW_HIDE);
				break;
			default:
				break;
			}
			return TRUE;

		default:
			return( DefWindowProc( hdlg, msg, wParam, lParam ) );
	}
	return FALSE;
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------

int WinStandardWindowCreate( char *classname , char *title , long style , long x , long y , long xs , long ys , HWND hdlg , WNDPROC Proc , long icon , long cursor , long back , long menu , long ex ) {
	MSG msg;
	HWND hWnd;
	WNDCLASS wndclass = {0};

	wndclass.lpfnWndProc	= (WNDPROC) Proc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= GetModuleHandle(NULL);
	if ( icon == (long) NULL )		wndclass.hIcon		= NULL;
	else							wndclass.hIcon		= LoadIcon( GetModuleHandle(NULL) , MAKEINTRESOURCE( icon ) );
	if ( cursor == (long) NULL )	wndclass.hCursor	= LoadCursor( NULL , IDC_ARROW );
	else							wndclass.hCursor	= LoadCursor( NULL , (LPCTSTR) cursor );
	if ( back == (long) NULL )		wndclass.hbrBackground	= NULL;
	else							wndclass.hbrBackground	= (HBRUSH) ( back );
	if ( menu == (long) NULL )		wndclass.lpszMenuName	= NULL;
	else							wndclass.lpszMenuName	= MAKEINTRESOURCE( menu );
	wndclass.lpszClassName	= classname;
	wndclass.style = CS_DBLCLKS;
	//
	RegisterClass( &wndclass );
	//
	hWnd = CreateWindowEx( ex , classname , title , style ,
                             x , y , xs , ys , hdlg , NULL , GetModuleHandle(NULL) , NULL );
	if ( hWnd == NULL ) return FALSE;
	//
	ShowWindow( hWnd, SW_SHOWNORMAL );
	UpdateWindow( hWnd ) ;
	//
	while ( GetMessage( &msg , NULL , 0 , 0 ) ) {
		//
		TranslateMessage( &msg );
		DispatchMessage( &msg );
		//
	}
	//
	return msg.wParam;
}


void main() {

	InitCommonControls();

	WinStandardWindowCreate( "TEST" , "TEST" , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , CW_USEDEFAULT , CW_USEDEFAULT , NULL , Console_Gui_For_MainEditor_Proc , (long) MAKEINTRESOURCE( IDI_PROGRAM_GUI ) , (long) NULL , (long) (COLOR_WINDOW+2) , (long) NULL , WS_EX_ACCEPTFILES );

}

