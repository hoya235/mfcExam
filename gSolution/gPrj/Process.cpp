// Process.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "Process.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}

// CProcess ��� �Լ�

int CProcess::getStartInfo(CImage& image, int th)
{
	int nWidth  = image.GetWidth();
	int nHeight = image.GetHeight();
	unsigned char* fm = (unsigned char*)image.GetBits();

	int nSum = 0;
	for (int k = 0; k < nWidth*nHeight; k++)
	{
		if (fm[k] > th) {
			nSum++;
		}
	}

	return nSum;
}
