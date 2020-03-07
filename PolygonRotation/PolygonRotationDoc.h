// PolygonRotationDoc.h : interface of the CPolygonRotationDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGONROTATIONDOC_H__51082823_B204_11D5_AFD0_0050FC3D9131__INCLUDED_)
#define AFX_POLYGONROTATIONDOC_H__51082823_B204_11D5_AFD0_0050FC3D9131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPolygonRotationDoc : public CDocument
{
protected: // create from serialization only
    CPolygonRotationDoc();
    DECLARE_DYNCREATE(CPolygonRotationDoc)

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CPolygonRotationDoc)
    public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CPolygonRotationDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CPolygonRotationDoc)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONROTATIONDOC_H__51082823_B204_11D5_AFD0_0050FC3D9131__INCLUDED_)
