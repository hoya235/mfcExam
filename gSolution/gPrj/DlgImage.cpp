// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"

#include "gPrjDlg.h"

// CDlgImage ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SEND_PARENT, &CDlgImage::OnBnClickedBtnSendParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage �޽��� ó�����Դϴ�.

void  CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);
}

BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 0, 640, 480);

	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgImage::OnBnClickedBtnSendParent()
{
	static int n = 100;
	CgPrjDlg& dlg = *(CgPrjDlg*)m_pParent;
	dlg.callFunc(n++);
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	DrawData(dc);
}

void CDlgImage::DrawData(CDC& dc) 
{
	CRect rect;
	CPen  pen;	
	pen.CreatePen(PS_SOLID, 5, COR_GREEN);
	CPen* pOldPen = dc.SelectObject(&pen);
	
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(2, 2);
		dc.Ellipse(rect);
	}
	
	dc.SelectObject(pOldPen);
}
