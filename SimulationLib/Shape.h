#ifndef SHAPE_HH
#define SHAPE_HH

#include "Rect.h"
#include "Vec2D.h"

#include <vector>
using namespace std;

class Shape {
public:
    Shape( const Rect& r = invalidRect() )                  { setBoundingRect(r); }
    virtual ~Shape()                                        {}

    void                setBoundingRect(const Rect& r)      { m_boundingRect = r; }
    const Rect&         getBoundingRect() const             { return m_boundingRect; }

    void                addVertex(const Vec2D& vertex);
    const Vec2D&        getVertex(int idx) const            { return m_vertexList[idx]; }
    int                 getVertexCount() const              { return m_vertexList.size(); }

    // Overridables
    virtual bool        collides( const Vec2D& vec2d)       { return m_boundingRect.isPointInside(vec2d); }
    virtual void        move(const Vec2D& offset)           { m_boundingRect.shiftRect( offset ); }

public:
    typedef vector<Vec2D> VertexList;

private:
    VertexList  m_vertexList;
    Rect        m_boundingRect;

public:
    static const Rect&  invalidRect()                       { static Rect r(-1, -1, -1, -1); return r; }

};

#endif SHAPH_HH