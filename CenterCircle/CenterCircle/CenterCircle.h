
// CenterCircle.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCenterCircleApp:
// �� Ŭ������ ������ ���ؼ��� CenterCircle.cpp�� �����Ͻʽÿ�.
//

class CCenterCircleApp : public CWinApp
{
public:
	CCenterCircleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCenterCircleApp theApp;