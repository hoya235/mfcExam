// CreateDLL.h : CreateDLL DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCreateDLLApp
// �� Ŭ������ ������ ������ CreateDLL.cpp�� �����Ͻʽÿ�.
//

class CCreateDLLApp : public CWinApp
{
public:
	CCreateDLLApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
