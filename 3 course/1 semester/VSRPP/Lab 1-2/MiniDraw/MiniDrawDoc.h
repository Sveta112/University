
// MiniDrawDoc.h: интерфейс класса CMiniDrawDoc 
//

#include "Afxtempl.h"
#pragma once

class CCircle : public CObject
{
protected:
	int m_X1, m_Y1, m_X2, m_Y2, flag;
	CCircle() {}
	DECLARE_SERIAL(CCircle)
public:
	CCircle(int X1, int Y1, int X2, int Y2, int flag)
	{
		m_X1 = X1; m_Y1 = Y1; m_X2 = X2; m_Y2 = Y2; this->flag = flag;
	}
	void Draw(CDC *PDC, int);
	int getfl() { return flag; }
	virtual void Serialize(CArchive& ar);
};


class CMiniDrawDoc : public CDocument
{
protected: // создать только из сериализации
	CMiniDrawDoc() noexcept;
	DECLARE_DYNCREATE(CMiniDrawDoc)
	CTypedPtrArray<CObArray, CCircle*> m_CirArray;
	CTypedPtrArray<CObArray, CCircle*> m_CirArray_redo;
public:
	void AddCir(int X1, int Y1, int X2, int Y2, int flag);
	CCircle *GetCir(int Index);
	int GetFlag(int Index);
	int GetNumCirs();
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMiniDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
	afx_msg void OnEditClearAll();
	afx_msg void OnUpdateEditClearAll(CCmdUI *pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI *pCmdUI);
};