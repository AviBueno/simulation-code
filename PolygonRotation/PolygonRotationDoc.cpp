// PolygonRotationDoc.cpp : implementation of the CPolygonRotationDoc class
//

#include "stdafx.h"
#include "PolygonRotation.h"

#include "PolygonRotationDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationDoc

IMPLEMENT_DYNCREATE(CPolygonRotationDoc, CDocument)

BEGIN_MESSAGE_MAP(CPolygonRotationDoc, CDocument)
    //{{AFX_MSG_MAP(CPolygonRotationDoc)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationDoc construction/destruction

CPolygonRotationDoc::CPolygonRotationDoc()
{
    // TODO: add one-time construction code here

}

CPolygonRotationDoc::~CPolygonRotationDoc()
{
}

BOOL CPolygonRotationDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)

    return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationDoc serialization

void CPolygonRotationDoc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // TODO: add storing code here
    }
    else
    {
        // TODO: add loading code here
    }
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationDoc diagnostics

#ifdef _DEBUG
void CPolygonRotationDoc::AssertValid() const
{
    CDocument::AssertValid();
}

void CPolygonRotationDoc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationDoc commands
