
#include "default.h"

//
BOOL APIENTRY Console_Gui_For_MainEditor_Proc( HWND hdlg , UINT msg , WPARAM wParam , LPARAM lParam ) {
	switch ( msg ) {
			
		case WM_DROPFILES:
			return TRUE;
			//
		case WM_CREATE:
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
			return TRUE;

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
			return TRUE;

		case WM_COMMAND:
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
// Rc1015 리소스 컴파일 오류는 MSDN에 자료가 있다.
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

