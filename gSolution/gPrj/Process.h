#pragma once

// CProcess ��� ����Դϴ�.

class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

public:
	int getStartInfo(CImage& image, int th = 100);
};


