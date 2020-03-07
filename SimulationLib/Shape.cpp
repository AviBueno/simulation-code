//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Shape.cpp
// = DATE:          1-Oct-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Shape.h"

void Shape::addVertex(const Vec2D& vertex)
{
    m_vertexList.push_back(vertex);
    Rect r = invalidRect();
    for ( VertexList::iterator itr = m_vertexList.begin(); itr != m_vertexList.end(); itr++ )
    {
        const Vec2D& v = *itr;
        if ( v.x < r.m_left ) r.m_left = v.x;
        if ( v.x > r.m_right ) r.m_right = v.x;

        if ( v.y < r.m_top ) r.m_top = v.y;
        if ( v.y > r.m_bottom ) r.m_bottom = v.y;
    }

    setBoundingRect(r);
}
