
// 03.16View.cpp : CMy0316View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "03.16.h"
#endif

#include "03.16Doc.h"
#include "03.16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0316View

IMPLEMENT_DYNCREATE(CMy0316View, CView)

BEGIN_MESSAGE_MAP(CMy0316View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()

// CMy0316View 构造/析构

CMy0316View::CMy0316View()
{
	// TODO: 在此处添加构造代码

}

CMy0316View::~CMy0316View()
{
}

BOOL CMy0316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0316View 绘制

void CMy0316View::OnDraw(CDC*  pDC)
{
	CMy0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy0316View 诊断

#ifdef _DEBUG
void CMy0316View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0316Doc* CMy0316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0316Doc)));
	return (CMy0316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0316View 消息处理程序


void CMy0316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMy0316Doc* pDoc = GetDocument();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	{
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy0316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0316Doc* pDoc = GetDocument();
	pDoc->m_tagRec.right=point.x ;
	pDoc->m_tagRec.bottom= point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->m_tagRec);
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CMy0316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0316Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString str;
   str.Format(_T("x=%d  y=%d"), point.x, point.y);
	dc.TextOutW(20, 30,str);

	CView::OnMouseMove(nFlags, point);
}




