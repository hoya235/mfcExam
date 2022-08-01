// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"

#include "gPrjDlg.h"

// CDlgImage 대화 상자입니다.

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


// CDlgImage 메시지 처리기입니다.

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
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

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
