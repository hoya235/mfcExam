
// BitmapBtn.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CBitmapBtnApp:
// �� Ŭ������ ������ ���ؼ��� BitmapBtn.cpp�� �����Ͻʽÿ�.
//

class CBitmapBtnApp : public CWinApp
{
public:
	CBitmapBtnApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CBitmapBtnApp theApp;