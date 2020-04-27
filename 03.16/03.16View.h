
// 03.16View.h : CMy0316View 类的接口
//

#pragma once


class CMy0316View : public CView
{
protected: // 仅从序列化创建
	CMy0316View();
	DECLARE_DYNCREATE(CMy0316View)

// 特性
public:
	CMy0316Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0316View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 03.16View.cpp 中的调试版本
inline CMy0316Doc* CMy0316View::GetDocument() const
   { return reinterpret_cast<CMy0316Doc*>(m_pDocument); }
#endif

