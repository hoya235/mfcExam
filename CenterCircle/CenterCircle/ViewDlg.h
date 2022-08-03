#pragma once


// CViewDlg ��ȭ �����Դϴ�.

class CViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CViewDlg)

public:
	CViewDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CViewDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEW_DLG };
#endif

private:
	CWnd*  m_pParentDlg;
	CImage m_img;
	CRect  m_rect;
	int    m_nCenterX = 0;
	int    m_nCenterY = 0;

	void InitImage();
	void CalcCenter(double& fCenterX, double& fCenterY);

public:
	bool DrawCircle(int diameter, double& fCenterX, double& fCenterY);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
