
// gPrjDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"
#include "Process.h"

#include <chrono>
#include <thread>

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

using namespace std;
using namespace chrono;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgPrjDlg ��ȭ ����



CgPrjDlg::CgPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPRJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CgPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrjDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_PROCESS, &CgPrjDlg::OnBnClickedBtnProcess)
	ON_BN_CLICKED(IDC_BTN_MAKE_PATTEN, &CgPrjDlg::OnBnClickedBtnMakePatten)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CgPrjDlg::OnBnClickedBtnGetData)
	ON_BN_CLICKED(IDC_BTN_THREAD, &CgPrjDlg::OnBnClickedBtnThread)
END_MESSAGE_MAP()


// CgPrjDlg �޽��� ó����

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	MoveWindow(0, 0, 1280, 800);

	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	m_pDlgImgResult = new CDlgImage;
	m_pDlgImgResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImgResult->ShowWindow(SW_SHOW);
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CgPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CgPrjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgPrjDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pDlgImage) delete m_pDlgImage;
	if (m_pDlgImgResult) delete m_pDlgImgResult;
}

void CgPrjDlg::callFunc(int n)
{
	cout << n << endl;
}

void CgPrjDlg::OnBnClickedBtnTest()
{
	CImage& img = m_pDlgImage->m_image;

	int nWidth = img.GetWidth();
	int nHeight = img.GetHeight();
	int nPitch = img.GetPitch();
	unsigned char* fm = (unsigned char*)img.GetBits();

	memset(fm, 0, nHeight*nWidth);
	
	for (int k = 0; k < MAX_POINT; k++) {
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = rand()%0xff;
	}

	int index = 0;
	int nTh = 100;
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j*nPitch + i] > nTh) {
				if (m_pDlgImgResult->m_nDataCount < MAX_POINT) {
					//cout << index << " " << i << ":" << j << endl;
					m_pDlgImgResult->m_ptData[index].x = i;
					m_pDlgImgResult->m_ptData[index].y = j;
					m_pDlgImgResult->m_nDataCount = ++index;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImgResult->Invalidate();
}


void CgPrjDlg::OnBnClickedBtnProcess()
{
	CProcess ps;

	auto start = system_clock::now();	
	int ret = ps.getStartInfo(m_pDlgImage->m_image, 0);
	auto end = system_clock::now();
	auto msec = duration_cast<chrono::milliseconds>(end - start);
	cout << ret << "\t" << msec.count() << "ms" << endl;	
}


void CgPrjDlg::OnBnClickedBtnMakePatten()
{
	CImage& img = m_pDlgImage->m_image;

	int nWidth = img.GetWidth();
	int nHeight = img.GetHeight();
	int nPitch = img.GetPitch();
	unsigned char* fm = (unsigned char*)img.GetBits();

	memset(fm, 0, nHeight*nWidth);

	CRect rect(100, 100, 200, 200);
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			fm[j * nPitch + i] = rand() % 0xff;
		}
	}

	m_pDlgImage->Invalidate();
}


void CgPrjDlg::OnBnClickedBtnGetData()
{
	CImage& img = m_pDlgImage->m_image;

	int nWidth = img.GetWidth();
	int nHeight = img.GetHeight();
	int nPitch = img.GetPitch();
	unsigned char* fm = (unsigned char*)img.GetBits();

	CRect rect(0, 0, nWidth, nHeight);
	int nTh = 0x80;
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j*nPitch + i] > nTh) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	double dbCenterX = (double)nSumX / nCount;
	double dbCenterY = (double)nSumY / nCount;

	cout << dbCenterX << "\t" << dbCenterY << endl;
}

void threadProcess(CWnd* pParent, CRect rect, int *nRet)
{
	CgPrjDlg* pWnd = (CgPrjDlg*)pParent;
	*nRet = pWnd->ProcessImg(rect);
}

void CgPrjDlg::OnBnClickedBtnThread()
{
	auto start = system_clock::now();

	int nImgSize = 4096 * 4;
	CRect rect(0, 0, nImgSize, nImgSize);
	CRect rt[4];
	for (int k = 0; k < 4; k++)
	{
		rt[k] = rect;
		rt[k].OffsetRect(nImgSize * (k % 2), nImgSize * int(k / 2));
	}

	int nRet[4] = { 0,0,0,0 };
	thread _thread0(threadProcess, this, rt[0], &nRet[0]);
	thread _thread1(threadProcess, this, rt[1], &nRet[1]);
	thread _thread2(threadProcess, this, rt[2], &nRet[2]);
	thread _thread3(threadProcess, this, rt[3], &nRet[3]);

	_thread0.join();
	_thread1.join();
	_thread2.join();
	_thread3.join();

	int nSum = 0;
	for (int i = 0; i < 4; i++)
		nSum += nRet[i];
	
	auto end = system_clock::now();
	auto msec = duration_cast<milliseconds>(end - start);
	cout << "main: "<< nSum << "\t" << msec.count() << "ms" << endl;
}

int CgPrjDlg::ProcessImg(CRect rect)
{
	auto start = system_clock::now();
	
	CProcess ps;
	
	int nRet = ps.getStartInfo(&m_pDlgImage->m_image, 0, rect);

	auto end = system_clock::now();
	auto msec = duration_cast<milliseconds>(end - start);
	cout << "thread: " << nRet << "\t" << msec.count() << "ms" << endl;

	return nRet;
}