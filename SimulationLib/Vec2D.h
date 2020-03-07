#ifndef VEC2D_HH
#define VEC2D_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Vec2D.h
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

class Vec2D
{
public:
    Vec2D();
    Vec2D(float px, float py);
    Vec2D(const Vec2D& vec);

    const Vec2D& operator = (const Vec2D& vec);

    void    init(float px, float py);

    Vec2D   operator+(const Vec2D& rhs) const;
    void    operator+=(const Vec2D& rhs);

    Vec2D   operator-(const Vec2D& rhs) const;
    void    operator-=(const Vec2D& rhs);

    Vec2D   operator-() const;  // Unary minus = negative vector result

    Vec2D   operator*(float f) const;
    void    operator*=(float f);

    Vec2D   operator/(float f) const;
    void    operator/=(float f);

    Vec2D   operator*(const Vec2D& rhs) const;
    void    operator*=(const Vec2D& rhs);

    Vec2D   operator/(const Vec2D& rhs) const;
    void    operator/=(const Vec2D& rhs);


    float   dotMul(const Vec2D& vec) const;
    float   norma() const;  // sqrt(x^2 + y^2)
    Vec2D   unitVec() const;

    static Vec2D& zero();

#ifdef __AFX_H__    // MFC Compatibility
    Vec2D(const CPoint& p)  { init( (float)p.x, (float)p.y ); } // Construction from CPoint
    operator CPoint() const { return CPoint((int)x, (int)y); }  // Object type conversion to CPoint
#endif

public:
    float   x;
    float   y;
};

#endif // VEC2D_HH //
