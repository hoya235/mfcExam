#pragma once


// CViewDlg 대화 상자입니다.

class CViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CViewDlg)

public:
	CViewDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CViewDlg();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
