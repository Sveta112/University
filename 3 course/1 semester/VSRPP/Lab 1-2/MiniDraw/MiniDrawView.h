
// MiniDrawView.h: интерфейс класса CMiniDrawView
//

#pragma once


class CMiniDrawView : public CView
{
protected: // создать только из сериализации
	CMiniDrawView() noexcept;
	DECLARE_DYNCREATE(CMiniDrawView)
	CString m_ClassName;
	int m_Dragging;
	HCURSOR m_HCross;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT /* nFlags */, CPoint point);
	afx_msg void OnContextMenu(CWnd* /* pWnd */, CPoint point);
	void OnFilePrintPreview();
// Атрибуты
public:
	CMiniDrawDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMiniDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

#ifndef _DEBUG  // версия отладки в MiniDrawView.cpp
inline CMiniDrawDoc* CMiniDrawView::GetDocument() const
   { return reinterpret_cast<CMiniDrawDoc*>(m_pDocument); }
#endif

