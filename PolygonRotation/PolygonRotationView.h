// PolygonRotationView.h : interface of the CPolygonRotationView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGONROTATIONVIEW_H__51082825_B204_11D5_AFD0_0050FC3D9131__INCLUDED_)
#define AFX_POLYGONROTATIONVIEW_H__51082825_B204_11D5_AFD0_0050FC3D9131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPolygonRotationView : public CView
{
protected: // create from serialization only
    CPolygonRotationView();
    DECLARE_DYNCREATE(CPolygonRotationView)

// Attributes
public:
    CPolygonRotationDoc* GetDocument();

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CPolygonRotationView)
    public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void OnInitialUpdate();
    protected:
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CPolygonRotationView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CPolygonRotationView)
    afx_msg void OnTimer(UINT nIDEvent);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

private:
    void    rotatePolygon( double deltagDeg );
    void    movePolygon( int delta );
    void    performDraw(CDC* pDC);
};

#ifndef _DEBUG  // debug version in PolygonRotationView.cpp
inline CPolygonRotationDoc* CPolygonRotationView::GetDocument()
   { return (CPolygonRotationDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONROTATIONVIEW_H__51082825_B204_11D5_AFD0_0050FC3D9131__INCLUDED_)
