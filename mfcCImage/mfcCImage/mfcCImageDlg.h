
// mfcCImageDlg.h : ��� ����
//

#pragma once


// CmfcCImageDlg ��ȭ ����
class CmfcCImageDlg : public CDialogEx
{
private:
	CImage m_image;

	void moveRect();
	BOOL validPosXY(int x, int y);
	BOOL IsInCircle(int x, int y, int nRadius);

// �����Դϴ�.
public:
	CmfcCImageDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	void UpdateDisplay();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCIMAGE_DIALOG };
#endif
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnAction();
};
