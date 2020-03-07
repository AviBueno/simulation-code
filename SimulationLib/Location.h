#ifndef LOCATION_HH
#define LOCATION_HH

#include "Vec2D.h"
#include "Ang.h"

class Location
{
public:
    Location()  {};
    Location( const Vec2D& vec, const Ang& ang )
    {
        init(vec, ang);
    }

    void    init( const Vec2D& pos, const Ang& ang )
    {
        setPos(pos);
        setAngle(ang);
    }

    void            setPos(const Vec2D& pos)            { m_pos = pos; }
    void            setAngle(const Ang& ang)            { m_angle = ang; }

    // Operations
    Vec2D           operator + (const Vec2D& v) const   { return m_pos + v; }
    void            operator += (const Vec2D& v)        { m_pos += v; }

    Ang             operator + (const Ang& a) const     { return m_angle + a;}
    void            operator += (const Ang& a)          { m_angle += a; }

    // Queries
    const Vec2D&    getPos() const                      { return m_pos; }
    Ang             getAngle() const                    { return m_angle; }

private:
    Vec2D   m_pos;
    Ang     m_angle;
};


#endif LOCATION_HH