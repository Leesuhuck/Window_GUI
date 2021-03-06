//===========================================================================================================================
#define _CRT_SECURE_NO_DEPRECATE
//===========================================================================================================================

#include "default.h"
#include "Option.h"
#include "Lang.h"
#include "Tool.h"
#include "Connect.h"
//
int LANG_DATA_CONTROL = 0; // Auto , E , K , J , C
//
void LANG_SET_CONTROL( int id ) {
	//
	LANG_DATA_CONTROL = id;
	//
	switch( LANG_DATA_CONTROL ) {
	case 1 : // E
		KGUI_DRAW_LANGUAGE_SET( _LANG_ENGLISH );
		break;
	case 2 : // K
		KGUI_DRAW_LANGUAGE_SET( _LANG_KOREA );
		break;
	case 3 : // J
		KGUI_DRAW_LANGUAGE_SET( _LANG_JAPAN );
		break;
	case 4 : // C
		KGUI_DRAW_LANGUAGE_SET( _LANG_CHINA );
		break;
	default :
		switch( GetSystemDefaultLangID() ) {
		case 0x0411 :	//Japanese
			KGUI_DRAW_LANGUAGE_SET( _LANG_JAPAN );
			break;
		case 0x0412 :	//Korean
			KGUI_DRAW_LANGUAGE_SET( _LANG_KOREA );
			break;
		case 0x0404 :	//Chinese (Taiwan) 
		case 0x0804 :	//Chinese (PRC) 
		case 0x0c04 :	//Chinese (Hong Kong SAR, PRC) 
		case 0x1004 :	//Chinese (Singapore) 
		case 0x1404 :	//Chinese (Macau SAR) 
			KGUI_DRAW_LANGUAGE_SET( _LANG_CHINA );
			break;
		default :
			KGUI_DRAW_LANGUAGE_SET( _LANG_ENGLISH );
			break;
		}
		break;
	}
}

int  LANG_GET_CONTROL() {
	return LANG_DATA_CONTROL;
}

BOOL LANG_SELECT_CONTROL( HWND hdlg ) {
	int x;
	//
	x = LANG_DATA_CONTROL;
	//
	if ( TOOL_TRACK_MENU_ENUM( hdlg , 0 , "AUTO|ENGLISH|KOREA|JAPAN|CHINA" , &x ) ) {
		LANG_SET_CONTROL( x );
		return TRUE;
	}
	return FALSE;
}


//========================================================================================================================
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================





int LANG_GET_MENU_ID( int id ) {
	if ( id == 0 ) {
		//
		switch( KGUI_DRAW_LANGUAGE_GET() ) {
		case _LANG_ENGLISH :
			return IDR_MENU1_0;
			break;
		case _LANG_KOREA :
			return IDR_MENU1_1;
			break;
		case _LANG_JAPAN :
			return IDR_MENU1_2;
			break;
		case _LANG_CHINA :
			return IDR_MENU1_3;
			break;
		default :
			return IDR_MENU1_0;
			break;
		}
		//
	}
	else {
		//
		switch( KGUI_DRAW_LANGUAGE_GET() ) {
		case _LANG_ENGLISH :
			return IDR_MENU2_0;
			break;
		case _LANG_KOREA :
			return IDR_MENU2_1;
			break;
		case _LANG_JAPAN :
			return IDR_MENU2_2;
			break;
		case _LANG_CHINA :
			return IDR_MENU2_3;
			break;
		default :
			return IDR_MENU2_0;
			break;
		}
		//
	}
}

//========================================================================================================================


void LANG_GET_RECENTLY_OPEN( char *Buffer , int cnt ) {
	//
	strcpy( Buffer , "" );
	//
	switch( KGUI_DRAW_LANGUAGE_GET() ) {
	case _LANG_ENGLISH :
		strcpy( Buffer , "Recent File Open.." );
		break;
	case _LANG_KOREA :
		strcpy( Buffer , "최근에 사용한 파일" );
		break;
	case _LANG_JAPAN :
		strcpy( Buffer , "最近使用したファイル.." );
		break;
	case _LANG_CHINA :
		strcpy( Buffer , "最近使用的文档.." );
		break;
	default :
		strcpy( Buffer , "Recent File Open.." );
		break;
	}
	//
}

//========================================================================================================================


void LANG_GET_STATUSBAR( int mode , char *Buffer , int cnt ) {
	//
	strcpy( Buffer , "" );
	//
	switch( KGUI_DRAW_LANGUAGE_GET() ) {

	case _LANG_ENGLISH :
		//
		switch( mode ) {
		case 1 :
			if ( _EDIT_UTIL_NOT_SAVED() ) strcpy( Buffer , "Modified" );
			break;
		case 3 :
			strcpy( Buffer , "PageView" );
			break;
		case 4 :
			strcpy( Buffer , "AttrView" );
			break;
		case 5 :
			strcpy( Buffer , ( !Get_Option_VIEW_HIDEBACK() ) ? "ShowBack" : "HideBack" );
			break;
		case 7 :
			switch( CON_GET_STATUS() ) {
			case 1 :
				sprintf( Buffer , "Connect - [%s]" , CON_GET_NAME() );
				break;
			case 2 :
				sprintf( Buffer , "Disconnect - [%s]" , CON_GET_NAME() );
				break;
			default :
				strcpy( Buffer , "No Connect" );
				break;
			}
			break;
		}
		//
		break;

	case _LANG_KOREA :
		//
		switch( mode ) {
		case 1 :
			if ( _EDIT_UTIL_NOT_SAVED() ) strcpy( Buffer , "수정됨" );
			break;
		case 3 :
			strcpy( Buffer , "Page창" );
			break;
		case 4 :
			strcpy( Buffer , "속성창" );
			break;
		case 5 :
			strcpy( Buffer , ( !Get_Option_VIEW_HIDEBACK() ) ? "배경보임" : "배경숨김" );
			break;
		case 7 :
			switch( CON_GET_STATUS() ) {
			case 1 :
				sprintf( Buffer , "연결중 - [%s]" , CON_GET_NAME() );
				break;
			case 2 :
				sprintf( Buffer , "연결끊김 - [%s]" , CON_GET_NAME() );
				break;
			default :
				strcpy( Buffer , "연결없음" );
				break;
			}
			break;
		}
		//
		break;

	case _LANG_JAPAN :
		//
		switch( mode ) {
		case 1 :
			if ( _EDIT_UTIL_NOT_SAVED() ) strcpy( Buffer , "修正済み" );
			break;
		case 3 :
			strcpy( Buffer , "ページウィンドウ" );
			break;
		case 4 :
			strcpy( Buffer , "プロパティウィンドウ" );
			break;
		case 5 :
			strcpy( Buffer , ( !Get_Option_VIEW_HIDEBACK() ) ? "バックグラウンドを表示" : "バックグラウンドを隠す" );
			break;
		case 7 :
			switch( CON_GET_STATUS() ) {
			case 1 :
				sprintf( Buffer , "接続中 - [%s]" , CON_GET_NAME() );
				break;
			case 2 :
				sprintf( Buffer , "接続切断 - [%s]" , CON_GET_NAME() );
				break;
			default :
				strcpy( Buffer , "接続なし" );
				break;
			}
			break;
		}
		//
		break;

	case _LANG_CHINA :
		//
		switch( mode ) {
		case 1 :
			if ( _EDIT_UTIL_NOT_SAVED() ) strcpy( Buffer , "已修正" );
			break;
		case 3 :
			strcpy( Buffer , "Page窗口" );
			break;
		case 4 :
			strcpy( Buffer , "属性窗口" );
			break;
		case 5 :
			strcpy( Buffer , ( !Get_Option_VIEW_HIDEBACK() ) ? "显示背景" : "隐藏背景" );
			break;
		case 7 :
			switch( CON_GET_STATUS() ) {
			case 1 :
				sprintf( Buffer , "连接中 - [%s]" , CON_GET_NAME() );
				break;
			case 2 :
				sprintf( Buffer , "断开连接 - [%s]" , CON_GET_NAME() );
				break;
			default :
				strcpy( Buffer , "无连接" );
				break;
			}
			break;
		}
		//
		break;

	default :
		//
		switch( mode ) {
		case 1 :
			if ( _EDIT_UTIL_NOT_SAVED() ) strcpy( Buffer , "Modified" );
			break;
		case 3 :
			strcpy( Buffer , "PageView" );
			break;
		case 4 :
			strcpy( Buffer , "AttrView" );
			break;
		case 5 :
			strcpy( Buffer , ( !Get_Option_VIEW_HIDEBACK() ) ? "ShowBack" : "HideBack" );
			break;
		case 7 :
			switch( CON_GET_STATUS() ) {
			case 1 :
				sprintf( Buffer , "Connect - [%s]" , CON_GET_NAME() );
				break;
			case 2 :
				sprintf( Buffer , "Disconnect - [%s]" , CON_GET_NAME() );
				break;
			default :
				strcpy( Buffer , "No Connect" );
				break;
			}
			break;
		}
		//
		break;

	}
}




int LANG_MESSAGEBOX( HWND hWnd , int mode , char *ustr , int uint ) {
	char Buffer[256];
	//
	switch( KGUI_DRAW_LANGUAGE_GET() ) {

	case _LANG_ENGLISH :
		//
		switch( mode ) {
			//
		case _MB_Q_FILNOTSAVE_WHEN_NEW :
			return MessageBox( hWnd , "File Not Saved! Do you want to New without saving ?" , "NEW Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_OPEN :
			return MessageBox( hWnd , "File Not Saved! Do you want to Open without saving ?" , "OPEN Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_EXIT :
			return MessageBox( hWnd , "File Not Saved! Do you want to Exit without saving ?" , "EXIT Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_CON_DISCONNECT :
			sprintf( Buffer , "Connection(%s) already established. Do you want to disconnect ?" , ustr );
			return MessageBox( hWnd , Buffer , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_EDIT_IMAGE_to_ORIGINALSIZE :
			return MessageBox( hWnd , "Do you want to change original size for Image?" , "Confirmation" , MB_ICONQUESTION | MB_OKCANCEL );
			break;
			//
		case _MB_Q_ANIM_ALLCLEARLOAD :
			return MessageBox( hWnd , "All Clear and Load?" , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_ANIM_CHG_SWAP :
			sprintf( Buffer , "Change Index already has Data. Do you want to Swap with Index %d ?" , uint );
			return MessageBox( hWnd , Buffer , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_C_OPENFILE_INVALID :
			sprintf( Buffer , "Open File [%s] is not valid [%d] !! Please Check" , ustr , uint );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_TEST_CLOSE :
			return MessageBox( hWnd , "TEST is Running! Please Close The TEST" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_SAVE :
			return MessageBox( hWnd , "Project can not find properly Folder(Save First)!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_SELPOPUP_INVALID :
			return MessageBox( hWnd , "Selected Popup Page is not saved or NoName!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_INSERT_ONLYMAINPAGE :
			return MessageBox( hWnd , "Project can not Insert(Only Use Main Page)!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_SUBPAGE :
			return MessageBox( hWnd , "Sub Page can not find!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_POPUPPAGE :
			return MessageBox( hWnd , "Popup Page can not find!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_CONINFO :
			return MessageBox( hWnd , "Connection Information can not find" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_CANNOT_INS_FULL :
			return MessageBox( hWnd , "Insert index can not insert (Full) !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_POPUP1 :
			return MessageBox( hWnd , "Insert index No is not Valid!! (from 1 POPUP)" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_INVALID :
			return MessageBox( hWnd , "Insert index No is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNO :
			return MessageBox( hWnd , "Insert index is already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNOTNO :
			return MessageBox( hWnd , "index is not already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_FAIL :
			return MessageBox( hWnd , "Insert Operation Fail !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_INVALID :
			return MessageBox( hWnd , "Delete index No is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_HASNOTNO :
			return MessageBox( hWnd , "Delete index is not already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_FAIL :
			return MessageBox( hWnd , "Delete index Operation Fail !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_MULTISELECT :
			return MessageBox( hWnd , "Two or More Index Item Selected" , "CHECK" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_INVALID :
			return MessageBox( hWnd , "Change index No is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_HASNOTNO :
			return MessageBox( hWnd , "Select index is not already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_VALUE_INVALID :
			return MessageBox( hWnd , "Value is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_FAIL :
			return MessageBox( hWnd , "Can not Insert Blink-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_CANNOTDEL :
			return MessageBox( hWnd , "Can not Delete Blink-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTINS :
			return MessageBox( hWnd , "Can not Insert X-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTDEL :
			return MessageBox( hWnd , "Can not Delete X-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_IMPORT_FAIL :
			sprintf( Buffer , "File Import Fail !! : %s" , ustr );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_EXPORT_FAIL :
			sprintf( Buffer , "File Export Fail !! : %s" , ustr );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CONINFO_MAKE_FAIL :
			sprintf( Buffer , "Connection Information can not make : %s" , ustr );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
		}
		//
		break;

	case _LANG_KOREA :
		//
		switch( mode ) {
			//
		case _MB_Q_FILNOTSAVE_WHEN_NEW :
			return MessageBox( hWnd , "파일이 저장되지 않았습니다. 파일을 저장하지 않고 새 파일을 사용하시겠습니까?" , "확인" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_OPEN :
			return MessageBox( hWnd , "파일이 저장되지 않았습니다. 파일을 저장하지 않고 새로운 파일을 열겠습니까?" , "확인" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_EXIT :
			return MessageBox( hWnd , "파일이 저장되지 않았습니다. 파일을 저장하지 않고 종료하시겠습니까?" , "확인" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_CON_DISCONNECT :
			sprintf( Buffer , "연결설정 (%s)가 이미 연결중입니다. 연결중인 연결을 끊으시겠습니까?" , ustr );
			return MessageBox( hWnd , Buffer , "확인" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_EDIT_IMAGE_to_ORIGINALSIZE :
			return MessageBox( hWnd , "IMAGE를 원래의 크기로 변경하시겠습니까?" , "확인" , MB_ICONQUESTION | MB_OKCANCEL );
			break;
			//
		case _MB_Q_ANIM_ALLCLEARLOAD :
			return MessageBox( hWnd , "모두 지우고 LOAD 하시겠습까?" , "확인" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_ANIM_CHG_SWAP :
			sprintf( Buffer , "바꿀 Index 번호에 Data가 존재합니다. Index %d 과 바꾸시겠습니까?" , uint );
			return MessageBox( hWnd , Buffer , "확인" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_C_OPENFILE_INVALID :
			sprintf( Buffer , "열려는 파일 %s 가 올바르지 않은 파일입니다. [에러:%d]" , ustr , uint );
			return MessageBox( hWnd , Buffer , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_TEST_CLOSE :
			return MessageBox( hWnd , "테스트 작업이 진행중입니다. 먼저 테스트 작업을 종료해 주세요" , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_SAVE :
			return MessageBox( hWnd , "올바른 폴더가 정의되어 있지 않습니다.(먼저 저장하여 폴더를 지정하십시요)" , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_SELPOPUP_INVALID :
			return MessageBox( hWnd , "선택한 POPUP 페이지가 유효하지 않습니다.(저장되지 않거나 이름이 없음)" , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_INSERT_ONLYMAINPAGE :
			return MessageBox( hWnd , "해당 삽입작업은 메인 페이지에서만 할 수 있습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_SUBPAGE :
			return MessageBox( hWnd , "SUB 페이지를 찾을 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_POPUPPAGE :
			return MessageBox( hWnd , "POPUP 페이지를 찾을 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_CONINFO :
			return MessageBox( hWnd , "연결설정 정보를 찾을 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_CANNOT_INS_FULL :
			return MessageBox( hWnd , "추가할 Index 번호의 공간이 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_POPUP1 :
			return MessageBox( hWnd , "추가할 Index 번호가 유효하지 않습니다.(POPUP 의 경우 1부터 시작해야합니다.)" , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_INVALID :
			return MessageBox( hWnd , "추가할 Index 번호가 유효하지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNO :
			return MessageBox( hWnd , "추가할 Index 번호가 이미 존재합니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNOTNO :
			return MessageBox( hWnd , "추가할 Index 번호가 존재하지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_FAIL :
			return MessageBox( hWnd , "추가 작업을 성공하지 못했습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_INVALID :
			return MessageBox( hWnd , "삭제할 Index 번호가 유효하지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_HASNOTNO :
			return MessageBox( hWnd , "삭제할 Index 번호가 존재하지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_FAIL :
			return MessageBox( hWnd , "삭제 작업을 성공하지 못했습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_MULTISELECT :
			return MessageBox( hWnd , "2개 또는 그 이상의 Index Item이 선택되어 있습니다." , "확인" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_INVALID :
			return MessageBox( hWnd , "바꿀 Index 번호가 유효하지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_HASNOTNO :
			return MessageBox( hWnd , "선택한 Index 번호가 존재하지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_VALUE_INVALID :
			return MessageBox( hWnd , "VALUE 값이 올바르지 않습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_FAIL :
			return MessageBox( hWnd , "BLINK IMAGE를 추가할 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_CANNOTDEL :
			return MessageBox( hWnd , "BLINK IMAGE를 삭제할 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTINS :
			return MessageBox( hWnd , "X-IMAGE를 추가할 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTDEL :
			return MessageBox( hWnd , "X-IMAGE를 삭제할 수 없습니다." , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_IMPORT_FAIL :
			sprintf( Buffer , "파일 %s 의 불러오기 작업을 성공하지 못했습니다." , ustr );
			return MessageBox( hWnd , Buffer , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_EXPORT_FAIL :
			sprintf( Buffer , "파일 %s 의 내보내기 작업을 성공하지 못했습니다." , ustr );
			return MessageBox( hWnd , Buffer , "에러" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CONINFO_MAKE_FAIL :
			sprintf( Buffer , "연결설정 %s의 정보를 만들수 없습니다." , ustr );
			return MessageBox( hWnd , Buffer , "에러" , MB_ICONHAND | MB_OK );
			break;
		}
		//
		break;

	case _LANG_JAPAN :
		//
		switch( mode ) {
			//
		case _MB_Q_FILNOTSAVE_WHEN_NEW :
			return MessageBox( hWnd , "ファイルを保存できませんでした。ファイルを保存しないで、新しいファイルを作成しますか。" , "NEW Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_OPEN :
			return MessageBox( hWnd , "ファイルを保存できませんでした。ファイルを保存しないで、新しいファイルを開きますか。" , "OPEN Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_EXIT :
			return MessageBox( hWnd , "ファイルを保存できませんでした。ファイルを保存しないで、終了しますか。" , "EXIT Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_CON_DISCONNECT :
			sprintf( Buffer , "既に接続しています。接続を切断してもよろしいですか。(%s)" , ustr );
			return MessageBox( hWnd , Buffer , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_EDIT_IMAGE_to_ORIGINALSIZE :
			return MessageBox( hWnd , "イメージを元のサイズに戻しますか。" , "Confirmation" , MB_ICONQUESTION | MB_OKCANCEL );
			break;
			//
		case _MB_Q_ANIM_ALLCLEARLOAD :
			return MessageBox( hWnd , "すべて削除してLOADしますか。" , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_ANIM_CHG_SWAP :
			sprintf( Buffer , "変更するIndex番号にデータが存在します。. Index %d と変更しますか。" , uint );
			return MessageBox( hWnd , Buffer , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_C_OPENFILE_INVALID :
			sprintf( Buffer , "開くファイル %s は正しくないファイルです。」[エラー:%d]" , ustr , uint );
			return MessageBox( hWnd , Buffer , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_TEST_CLOSE :
			return MessageBox( hWnd , "現在テスト実行中です。まずはテストを終了してください。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_SAVE :
			return MessageBox( hWnd , "フォルダが見つかりません。(まず保存してからフォルダを指定してください)" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_SELPOPUP_INVALID :
			return MessageBox( hWnd , "選択したPOPUPページは有効ではありません。(保存されていないか、名前なし)" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_INSERT_ONLYMAINPAGE :
			return MessageBox( hWnd , "該当の挿入機能はメインページのみ可能です。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_SUBPAGE :
			return MessageBox( hWnd , "SUBページが見つかりません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_POPUPPAGE :
			return MessageBox( hWnd , "POPUPページが見つかりません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_CONINFO :
			return MessageBox( hWnd , "接続設定の情報が見つかりません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_CANNOT_INS_FULL :
			return MessageBox( hWnd , "挿入するIndex番号(フル)は挿入できません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_POPUP1 :
			return MessageBox( hWnd , "挿入するIndex番号は有効ではありません。(POPUPの場合は、1から始まるべきです)	" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_INVALID :
			return MessageBox( hWnd , "挿入するIndex番号は有効ではありません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNO :
			return MessageBox( hWnd , "挿入するIndex番号はすでに存在します。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNOTNO :
			return MessageBox( hWnd , "挿入するIndex番号が存在しません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_FAIL :
			return MessageBox( hWnd , "挿入に失敗しました。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_INVALID :
			return MessageBox( hWnd , "削除するIndex番号が有効ではありません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_HASNOTNO :
			return MessageBox( hWnd , "削除するIndex番号が存在しません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_FAIL :
			return MessageBox( hWnd , "削除に失敗しました。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_MULTISELECT :
			return MessageBox( hWnd , "2個、あるいは2個以上のIndex Itemが選択されています。" , "CHECK" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_INVALID :
			return MessageBox( hWnd , "変更するIndex番号が有効ではありません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_HASNOTNO :
			return MessageBox( hWnd , "選択したIndex番号が存在しません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_VALUE_INVALID :
			return MessageBox( hWnd , "VALUEが正しい値ではありません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_FAIL :
			return MessageBox( hWnd , "BLINK-IMAGEが追加できません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_CANNOTDEL :
			return MessageBox( hWnd , "BLINK-IMAGEが削除できません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTINS :
			return MessageBox( hWnd , "X-IMAGEが追加できません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTDEL :
			return MessageBox( hWnd , "X-IMAGEが削除できません。" , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_IMPORT_FAIL :
			sprintf( Buffer , "ファイル %s のインポートに失敗しました。" , ustr );
			return MessageBox( hWnd , Buffer , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_EXPORT_FAIL :
			sprintf( Buffer , "ファイル %s のエクスポートに失敗しました。" , ustr );
			return MessageBox( hWnd , Buffer , "エラー" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CONINFO_MAKE_FAIL :
			sprintf( Buffer , "接続設定 %s の情報が作成できません。" , ustr );
			return MessageBox( hWnd , Buffer , "エラー" , MB_ICONHAND | MB_OK );
			break;
		}
		//
		break;

	case _LANG_CHINA :
		//
		switch( mode ) {
			//
		case _MB_Q_FILNOTSAVE_WHEN_NEW :
			return MessageBox( hWnd , "没有保存文档。确定不保存并使用新文档吗？" , "确认" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_OPEN :
			return MessageBox( hWnd , "没有保存文档。确定不保存并打开新文档吗？" , "确认" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_EXIT :
			return MessageBox( hWnd , "没有保存文档。确定不保存并退出程序吗？" , "确认" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_CON_DISCONNECT :
			sprintf( Buffer , "已建立连接设定(%s)。确定要断开该连接状态吗？" , ustr );
			return MessageBox( hWnd , Buffer , "确认" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_EDIT_IMAGE_to_ORIGINALSIZE :
			return MessageBox( hWnd , "是否把IMAGE更改为初始大小?" , "确认" , MB_ICONQUESTION | MB_OKCANCEL );
			break;
			//
		case _MB_Q_ANIM_ALLCLEARLOAD :
			return MessageBox( hWnd , "是否全部清空并执行 LOAD?" , "确认" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_ANIM_CHG_SWAP :
			sprintf( Buffer , "更改对象 Index 里已存在 Data。是否跟 Index %d 进行替换?" , uint );
			return MessageBox( hWnd , Buffer , "确认" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_C_OPENFILE_INVALID :
			sprintf( Buffer , "目标文档 [%s] 无效。[错误:%d]" , ustr , uint );
			return MessageBox( hWnd , Buffer , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_TEST_CLOSE :
			return MessageBox( hWnd , "正在执行 TEST 工作。请先终止 TEST 工作。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_SAVE :
			return MessageBox( hWnd , "指定文件夹无效。（请先保存文档并指定相应文件夹）" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_SELPOPUP_INVALID :
			return MessageBox( hWnd , "所选 POPUP Page 无效。(没有保存或没有名称)" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_INSERT_ONLYMAINPAGE :
			return MessageBox( hWnd , "只能在 Main Page 里执行 Project 插入操作。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_SUBPAGE :
			return MessageBox( hWnd , "无法查找 SUB Page。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_POPUPPAGE :
			return MessageBox( hWnd , "无法查找 POPUP Page。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_CONINFO :
			return MessageBox( hWnd , "无法查找连接信息。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_CANNOT_INS_FULL :
			return MessageBox( hWnd , "空间已满，无法添加 Index Number." , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_POPUP1 :
			return MessageBox( hWnd , "添加对象 Index Number 无效。(POPUP 从1开始计数)" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_INVALID :
			return MessageBox( hWnd , "添加对象 Index Number 无效。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNO :
			return MessageBox( hWnd , "已经存在添加对象 Index Number。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNOTNO :
			return MessageBox( hWnd , "不存在添加对象 Index Number。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_FAIL :
			return MessageBox( hWnd , "插入操作失败。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_INVALID :
			return MessageBox( hWnd , "删除对象 Index Number 无效。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_HASNOTNO :
			return MessageBox( hWnd , "不存在删除对象 Index Number。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_FAIL :
			return MessageBox( hWnd , "删除操作失败。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_MULTISELECT :
			return MessageBox( hWnd , "已选定2个以上（包括2个）Index Item。" , "确认" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_INVALID :
			return MessageBox( hWnd , "更改对象 Index Number 无效。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_HASNOTNO :
			return MessageBox( hWnd , "不存在选定对象 Index Number。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_VALUE_INVALID :
			return MessageBox( hWnd , "VALUE值无效。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_FAIL :
			return MessageBox( hWnd , "无法添加 BLINK-IMAGE。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_CANNOTDEL :
			return MessageBox( hWnd , "无法删除 BLINK-IMAGE。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTINS :
			return MessageBox( hWnd , "无法添加 X-IMAGE。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTDEL :
			return MessageBox( hWnd , "无法删除 X-IMAGE。" , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_IMPORT_FAIL :
			sprintf( Buffer , "导入文件 %s 失败。" , ustr );
			return MessageBox( hWnd , Buffer , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_EXPORT_FAIL :
			sprintf( Buffer , "导出文件 %s 失败。" , ustr );
			return MessageBox( hWnd , Buffer , "错误" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CONINFO_MAKE_FAIL :
			sprintf( Buffer , "无法建立 %s 连接信息 。" , ustr );
			return MessageBox( hWnd , Buffer , "错误" , MB_ICONHAND | MB_OK );
			break;
		}
		//
		break;

	default :
		//
		switch( mode ) {
			//
		case _MB_Q_FILNOTSAVE_WHEN_NEW :
			return MessageBox( hWnd , "File Not Saved! Do you want to New without saving ?" , "NEW Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_OPEN :
			return MessageBox( hWnd , "File Not Saved! Do you want to Open without saving ?" , "OPEN Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_FILNOTSAVE_WHEN_EXIT :
			return MessageBox( hWnd , "File Not Saved! Do you want to Exit without saving ?" , "EXIT Check" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_CON_DISCONNECT :
			sprintf( Buffer , "Connection(%s) already established. Do you want to disconnect ?" , ustr );
			return MessageBox( hWnd , Buffer , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_EDIT_IMAGE_to_ORIGINALSIZE :
			return MessageBox( hWnd , "Do you want to change original size for Image?" , "Confirmation" , MB_ICONQUESTION | MB_OKCANCEL );
			break;
			//
		case _MB_Q_ANIM_ALLCLEARLOAD :
			return MessageBox( hWnd , "All Clear and Load?" , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_Q_ANIM_CHG_SWAP :
			sprintf( Buffer , "Change Index already has Data. Do you want to Swap with Index %d ?" , uint );
			return MessageBox( hWnd , Buffer , "CHECK" , MB_ICONQUESTION | MB_YESNO );
			break;
			//
		case _MB_C_OPENFILE_INVALID :
			sprintf( Buffer , "Open File [%s] is not valid [%d] !! Please Check" , ustr , uint );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_TEST_CLOSE :
			return MessageBox( hWnd , "TEST is Running! Please Close The TEST" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_FIRST_SAVE :
			return MessageBox( hWnd , "Project can not find properly Folder(Save First)!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_SELPOPUP_INVALID :
			return MessageBox( hWnd , "Selected Popup Page is not saved or NoName!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_INSERT_ONLYMAINPAGE :
			return MessageBox( hWnd , "Project can not Insert(Only Use Main Page)!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_SUBPAGE :
			return MessageBox( hWnd , "Sub Page can not find!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_POPUPPAGE :
			return MessageBox( hWnd , "Popup Page can not find!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CANNOTFIND_CONINFO :
			return MessageBox( hWnd , "Connection Information can not find" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_CANNOT_INS_FULL :
			return MessageBox( hWnd , "Insert index can not insert (Full) !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_POPUP1 :
			return MessageBox( hWnd , "Insert index No is not Valid!! (from 1 POPUP)" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_INVALID :
			return MessageBox( hWnd , "Insert index No is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNO :
			return MessageBox( hWnd , "Insert index is already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_HASNOTNO :
			return MessageBox( hWnd , "index is not already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_INS_FAIL :
			return MessageBox( hWnd , "Insert Operation Fail !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_INVALID :
			return MessageBox( hWnd , "Delete index No is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_HASNOTNO :
			return MessageBox( hWnd , "Delete index is not already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_DEL_FAIL :
			return MessageBox( hWnd , "Delete index Operation Fail !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_MULTISELECT :
			return MessageBox( hWnd , "Two or More Index Item Selected" , "CHECK" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_INVALID :
			return MessageBox( hWnd , "Change index No is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_NOERR_CHG_HASNOTNO :
			return MessageBox( hWnd , "Select index is not already exist !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_VALUE_INVALID :
			return MessageBox( hWnd , "Value is not Valid!!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_FAIL :
			return MessageBox( hWnd , "Can not Insert Blink-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_BLINK_CANNOTDEL :
			return MessageBox( hWnd , "Can not Delete Blink-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTINS :
			return MessageBox( hWnd , "Can not Insert X-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_XIMAGE_CANNOTDEL :
			return MessageBox( hWnd , "Can not Delete X-IMAGE !!" , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_IMPORT_FAIL :
			sprintf( Buffer , "File Import Fail !! : %s" , ustr );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_ANIM_EXPORT_FAIL :
			sprintf( Buffer , "File Export Fail !! : %s" , ustr );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
			//
		case _MB_C_CONINFO_MAKE_FAIL :
			sprintf( Buffer , "Connection Information can not make : %s" , ustr );
			return MessageBox( hWnd , Buffer , "ERROR" , MB_ICONHAND | MB_OK );
			break;
		}
		//
		break;
	}
	//
	//=======================
	return IDCANCEL;
}
