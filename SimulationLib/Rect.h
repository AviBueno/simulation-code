#ifndef RECT_HH
#define RECT_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Rect.h
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Vec2D.h"

class Rect
{
public:
    Rect(float l = 0.0f, float t = 0.0f, float r = 0.0f, float b = 0.0f)
        : m_left(l), m_top(t) , m_right(r), m_bottom(b) {}

    Rect(const Vec2D& tl, const Vec2D& br)
        : m_left(tl.x), m_top(tl.y) , m_right(br.x), m_bottom(br.y) {}

    bool    isPointInside( const Vec2D& p ) const   { return isPointInside(p.x, p.y); }
    bool    isPointInside( float x, float y ) const
    {
        bool inside = (x >= m_left && x <= m_right && y >= m_top && y <= m_bottom);
        return inside;
    }

    Vec2D   getCenterPoint() const  { return Vec2D(m_left + width() / 2, m_top + height() / 2); }

    void    shiftRect(const Vec2D& offset)
    {
        m_left += offset.x;
        m_right += offset.x;
        m_top += offset.y;
        m_bottom += offset.y;
    }

    float   width() const   { return m_right - m_left; }
    float   height() const  { return m_bottom - m_top; }

public:
    float   m_left;
    float   m_top;
    float   m_right;
    float   m_bottom;
};

#endif // RECT_HH //
