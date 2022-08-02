#pragma once

// CProcess 명령 대상입니다.

class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

public:
	int getStartInfo(CImage& image, int th = 100);
};


