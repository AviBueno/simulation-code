// PolygonRotationView.cpp : implementation of the CPolygonRotationView class
//

#include "stdafx.h"
#include "PolygonRotation.h"

#include "PolygonRotationDoc.h"
#include "PolygonRotationView.h"

#include <math.h>
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const double PI = 3.1415926535897932384626433832795;

inline
double deg2rad(double deg)
{
    double rad = deg * PI / 180.0;
    return rad;
}

class Vec2D
{
public:
    Vec2D() { x = 0.0, y = 0.0; }
    Vec2D(double pX, double pY) { x = pX, y = pY; }

    Vec2D   operator+(const Vec2D& rhs) { return Vec2D(x + rhs.x, y + rhs.y); }
    Vec2D&  operator+=(const Vec2D& rhs)    { x += rhs.x, y += rhs.y; return *this; }

    Vec2D   operator-(const Vec2D& rhs) { return Vec2D(x - rhs.x, y - rhs.y); }
    Vec2D&  operator-=(const Vec2D& rhs)    { x -= rhs.x, y -= rhs.y; return *this; }

    operator CPoint()   { return CPoint((int)x, (int)y); }

public:
    double  x;
    double  y;
};

typedef vector<Vec2D> PolyVec;
PolyVec gPolygon;
Vec2D   gPolyPivot;
double  gPolyYaw = deg2rad(-90.0);
const double    gDeltaRadAngle = deg2rad(10.0);
double  gTimerRadAngle = gDeltaRadAngle;

UINT    TIMER_ID = 1;
UINT    TIMER_INTERVAL = 1;

Vec2D   gZeroPoint = Vec2D(100.0, 100.0);
int     gMotionState    = 0;    // 0 = still, +1 = fwd, -1 = back
int     gYawState       = 0;    // 0 = still, -1 = right, +1 = left

Vec2D rotateVec( double radAngle, const Vec2D& vec1 )
{
    Vec2D vec2;
    vec2.x = vec1.x * cos(radAngle) - vec1.y * sin(radAngle);
    vec2.y = vec1.y * cos(radAngle) + vec1.x * sin(radAngle);

    return vec2;
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationView

IMPLEMENT_DYNCREATE(CPolygonRotationView, CView)

BEGIN_MESSAGE_MAP(CPolygonRotationView, CView)
    //{{AFX_MSG_MAP(CPolygonRotationView)
    ON_WM_TIMER()
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    ON_WM_ERASEBKGND()
    //}}AFX_MSG_MAP
    // Standard printing commands
    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationView construction/destruction

CPolygonRotationView::CPolygonRotationView()
{
    // TODO: add construction code here

}

CPolygonRotationView::~CPolygonRotationView()
{
}

BOOL CPolygonRotationView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationView drawing
/*
void CPolygonRotationView::OnDraw(CDC* pDC)
{
    CPolygonRotationDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // TODO: add draw code for native data here
    
    //pDC->MoveTo(0, gZeroPoint.y); pDC->LineTo(gZeroPoint.x * 2, gZeroPoint.y);
    //pDC->MoveTo(gZeroPoint.x, 0); pDC->LineTo(gZeroPoint.x, gZeroPoint.y * 2);

    Vec2D v;
    for ( PolyVec::iterator itr = gPolygon.begin(); itr != gPolygon.end(); itr++ )
    {
        v = *itr;
        v.y = -v.y; // Flip Y axis for correct drawing
        v += gZeroPoint;

        if ( itr == gPolygon.begin() )
            pDC->MoveTo(v);
        else
            pDC->LineTo(v);
    }

    v = gPolyPivot;
    v.y = -v.y;
    pDC->SetPixel(gZeroPoint+v, RGB(255,0,0));
}
*/

void drawPolygon( Vec2D origin, COLORREF color, CDC* pDC )
{
    CPoint pntArr[100];

    int i = 0;
    Vec2D v;
    for ( PolyVec::iterator itr = gPolygon.begin(); itr != gPolygon.end(); itr++ )
    {
        v = *itr;
        v.y = -v.y; // Flip Y axis for correct drawing
        v += origin;
        pntArr[i] = v;
        i++;
    }

    CBrush brush(color);
    
    CBrush* pOldBrush = pDC->SelectObject(&brush);

    pDC->Polygon(pntArr, gPolygon.size());

    v = gPolyPivot;
    v.y = -v.y;
    pDC->SetPixel(origin+v, RGB(255,0,0));

    pDC->SelectObject( pOldBrush );
}

void CPolygonRotationView::performDraw(CDC* pDC)
{
    CPolygonRotationDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // TODO: add draw code for native data here
    
    //pDC->MoveTo(0, gZeroPoint.y); pDC->LineTo(gZeroPoint.x * 2, gZeroPoint.y);
    //pDC->MoveTo(gZeroPoint.x, 0); pDC->LineTo(gZeroPoint.x, gZeroPoint.y * 2);
    drawPolygon(gZeroPoint, RGB(255,0,0), pDC);
    drawPolygon(gZeroPoint + Vec2D(-40,40), RGB(0,0,255), pDC);
    drawPolygon(gZeroPoint + Vec2D(-40,-40), RGB(0,0,255), pDC);
}

void CPolygonRotationView::OnDraw(CDC* pDC)
{
    CDC dblBufDC;
    dblBufDC.CreateCompatibleDC(pDC);

    CRect r;
    GetClientRect(&r);
    CBitmap dblBufBMP;
    dblBufBMP.CreateCompatibleBitmap(pDC, r.Width(), r.Height());

    CBitmap* pOldBmp = dblBufDC.SelectObject(&dblBufBMP);

    dblBufDC.FillSolidRect(&r, RGB(255, 255, 255));

    performDraw(&dblBufDC);

    pDC->BitBlt(0, 0, r.Width(), r.Height(), &dblBufDC, 0, 0, SRCCOPY);

    dblBufDC.SelectObject(pOldBmp);
}

BOOL CPolygonRotationView::OnEraseBkgnd(CDC* pDC) 
{
    return TRUE;    // Prevent bg erasure due to dbl buf implementation
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationView printing

BOOL CPolygonRotationView::OnPreparePrinting(CPrintInfo* pInfo)
{
    // default preparation
    return DoPreparePrinting(pInfo);
}

void CPolygonRotationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}

void CPolygonRotationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationView diagnostics

#ifdef _DEBUG
void CPolygonRotationView::AssertValid() const
{
    CView::AssertValid();
}

void CPolygonRotationView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CPolygonRotationDoc* CPolygonRotationView::GetDocument() // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolygonRotationDoc)));
    return (CPolygonRotationDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPolygonRotationView message handlers

void CPolygonRotationView::OnInitialUpdate() 
{
    CView::OnInitialUpdate();
    
    // TODO: Add your specialized code here and/or call the base class
    Vec2D arr[] = {
        Vec2D(0,0),
        Vec2D(0,25),
        Vec2D(5,25),
        Vec2D(5,15),
        Vec2D(10,15),
        Vec2D(10,30),
        Vec2D(15,30),
        Vec2D(15,15),
        Vec2D(20,15),
        Vec2D(20,25),
        Vec2D(25,25),
        Vec2D(25,0),
        Vec2D(20,0),
        Vec2D(20,10),
        Vec2D(5,10),
        Vec2D(5,0),

        Vec2D(0,0)
    };

    for ( int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ )
    {
        gPolygon.push_back( arr[i] );
    }

    gPolyPivot = Vec2D(12, 15);

    //SetTimer(TIMER_ID,0,NULL);
    rotatePolygon(gPolyYaw);

    // Initiate simulation
    SetTimer(TIMER_ID, 0, NULL);
}

void CPolygonRotationView::rotatePolygon( double deltagDeg )
{
    gPolyYaw += deltagDeg;
    PolyVec tmp;

    for ( PolyVec::iterator itr = gPolygon.begin(); itr != gPolygon.end(); itr++ )
    {
        Vec2D v = *itr;
        v -= gPolyPivot;
        v = rotateVec(deltagDeg,v);
        v += gPolyPivot;
        tmp.push_back(v);
    }

    gPolygon = tmp;

    //Invalidate();
}

void CPolygonRotationView::movePolygon( int delta )
{
    double xFactor = cos(gPolyYaw);
    double yFactor = sin(gPolyYaw);

    double      xOffset = delta * xFactor;
    double      yOffset = delta * yFactor;

    gZeroPoint.x -= xOffset; gZeroPoint.y += yOffset;

    //Invalidate();
}

void CPolygonRotationView::OnTimer(UINT nIDEvent) 
{
    // TODO: Add your message handler code here and/or call default

    enum { DELTA_MOVE = 4 };
    bool refresh = false;

    if ( gMotionState )
    {
        movePolygon(DELTA_MOVE * gMotionState);
        refresh = true;
    }

    if ( gYawState )
    {
        rotatePolygon( gDeltaRadAngle * gYawState );
        refresh = true;
    }

    if ( refresh )
    {
        Invalidate();
    }
    
    SetTimer(TIMER_ID, TIMER_INTERVAL, NULL);

    CView::OnTimer(nIDEvent);
}

/*
void CPolygonRotationView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    // TODO: Add your message handler code here and/or call default
    enum { DELTA_MOVE = 4 };
    double xFactor = cos(gPolyYaw);
    double yFactor = sin(gPolyYaw);

    double      xOffset = DELTA_MOVE * xFactor;
    double      yOffset = DELTA_MOVE * yFactor;

    switch ( nChar )
    {
        case VK_UP:     gZeroPoint.x -= xOffset; gZeroPoint.y += yOffset; break;
        case VK_DOWN:   gZeroPoint.x += xOffset; gZeroPoint.y -= yOffset; break;
            

        case VK_LEFT:   gTimerRadAngle = gDeltaRadAngle; SetTimer(TIMER_ID, 0, NULL); break;
        case VK_RIGHT:  gTimerRadAngle = -gDeltaRadAngle; SetTimer(TIMER_ID, 0, NULL); break;
    }

    Invalidate();
    
    CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CPolygonRotationView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    // TODO: Add your message handler code here and/or call default
    switch ( nChar )
    {
        case VK_LEFT:
        case VK_RIGHT:
            KillTimer(TIMER_ID);
            break;
    }
    
    CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
*/
void CPolygonRotationView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    // TODO: Add your message handler code here and/or call default
    switch ( nChar )
    {
        case VK_UP:     gMotionState = +1; break;
        case VK_DOWN:   gMotionState = -1; break;
            

        case VK_RIGHT:  gYawState = -1; break;
        case VK_LEFT:   gYawState = +1; break;
    }

    CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CPolygonRotationView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    // TODO: Add your message handler code here and/or call default
    switch ( nChar )
    {
        case VK_UP:
        case VK_DOWN:
            gMotionState = 0;
            break;
            

        case VK_RIGHT:
        case VK_LEFT:
            gYawState = 0;
            break;
    }
    
    CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
