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
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.


void CDlgImage::OnBnClickedBtnSendParent()
{
	static int n = 100;
	CgPrjDlg& dlg = *(CgPrjDlg*)m_pParent;
	dlg.callFunc(n++);	
}
