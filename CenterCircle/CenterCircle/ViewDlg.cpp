// ViewDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CenterCircle.h"
#include "ViewDlg.h"
#include "afxdialogex.h"

#include "CenterCircleDlg.h"

#define IMG_WIDTH   640
#define IMG_HEIGHT  480
#define IMG_BPP       8

using namespace std;

// CViewDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CViewDlg, CDialogEx)

CViewDlg::CViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VIEW_DLG, pParent)
{
	m_pParentDlg = pParent;
}

CViewDlg::~CViewDlg()
{
}

void CViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CViewDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CViewDlg::InitImage()
{
	m_img.Create(IMG_WIDTH, -IMG_HEIGHT, IMG_BPP);

	if (IMG_BPP == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
		{
			rgb[i].rgbBlue = rgb[i].rgbGreen = rgb[i].rgbRed = i;
		}
		m_img.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)m_img.GetBits();

	memset(fm, 0xFF, IMG_WIDTH*IMG_HEIGHT);
}

bool CViewDlg::DrawCircle(int diameter, double& fCenterX, double& fCenterY)
{
	if (diameter == 0 || diameter > IMG_HEIGHT || diameter > IMG_WIDTH)
		return false;

	unsigned char* fm = (unsigned char*)m_img.GetBits();
	memset(fm, 0xFF, IMG_WIDTH*IMG_HEIGHT);

	int x = rand() % (IMG_WIDTH - diameter);
	int y = rand() % (IMG_HEIGHT - diameter);
	m_rect.SetRect(x, y, x + diameter, y + diameter);

	CDC* pDC = CDC::FromHandle(m_img.GetDC());

	pDC->Ellipse(&m_rect);
	
	ReleaseDC(pDC);

	m_img.ReleaseDC();
	
	CalcCenter(fCenterX, fCenterY);

	Invalidate();	

	return true;
}

void CViewDlg::CalcCenter(double& fCenterX, double& fCenterY)
{
	int nPitch = m_img.GetPitch();
	unsigned char* fm = (unsigned char*)m_img.GetBits();

	CRect rect(0, 0, IMG_WIDTH, IMG_HEIGHT);

	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j*nPitch + i] == 0) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	fCenterX = (double)nSumX / nCount;
	fCenterY = (double)nSumY / nCount;
	
	cout << fCenterX << "\t" << fCenterY << endl;

	m_nCenterX = (int)round(fCenterX);
	m_nCenterY = (int)round(fCenterY);
}

// CViewDlg �޽��� ó�����Դϴ�.


BOOL CViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 0, IMG_WIDTH, IMG_HEIGHT);

	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CViewDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.

	if (m_img)
		m_img.Draw(dc, 0, 0);

	if (!m_rect.IsRectEmpty())	
	{		
		CPen pen;
		pen.CreatePen(PS_SOLID, 2, COR_BLACK);
		CPen* pOldPen = dc.SelectObject(&pen);

		dc.Ellipse(&m_rect);

		dc.SelectObject(pOldPen);
		pen.DeleteObject();


		pen.CreatePen(PS_SOLID, 1, COR_RED);
		pOldPen = dc.SelectObject(&pen);

		dc.MoveTo(m_nCenterX - 2, m_nCenterY);
		dc.LineTo(m_nCenterX + 3, m_nCenterY);		
		dc.MoveTo(m_nCenterX, m_nCenterY - 2);
		dc.LineTo(m_nCenterX, m_nCenterY + 3);

		dc.SelectObject(pOldPen);
	}
}
