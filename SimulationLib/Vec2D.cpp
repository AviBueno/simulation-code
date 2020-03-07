//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Vec2D.cpp
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Vec2D.h"
#include "Assert.h"
#include <math.h>

Vec2D::Vec2D()
{
    init(0.0f, 0.0f);
}

Vec2D::Vec2D(float px, float py)
{
    init(px, py);
}

Vec2D::Vec2D(const Vec2D& vec)
{
    init(vec.x, vec.y);
}

const Vec2D& Vec2D::operator = (const Vec2D& vec)
{
    init(vec.x, vec.y);
    return *this;
}

void Vec2D::init(float px, float py)
{
    x = px;
    y = py;
}

Vec2D Vec2D::operator+(const Vec2D& rhs) const
{
    return Vec2D(x + rhs.x, y + rhs.y);
}

void Vec2D::operator+=(const Vec2D& rhs)
{
    x += rhs.x;
    y += rhs.y;
}

Vec2D Vec2D::operator-(const Vec2D& rhs) const
{
    return Vec2D(x - rhs.x, y - rhs.y);
}

void Vec2D::operator-=(const Vec2D& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
}

Vec2D Vec2D::operator-() const
{
    return Vec2D(-x, -y);
}

Vec2D Vec2D::operator*(float f) const
{
    return Vec2D(x * f, y * f);
}

void Vec2D::operator*=(float f)
{
    x *= f;
    y *= f;
}

Vec2D Vec2D::operator/(float f) const
{
    Assert( f != 0.0 );
    return Vec2D(x / f, y / f);
}

void Vec2D::operator/=(float f)
{
    Assert( f != 0.0 );
    x /= f;
    y /= f;
}

Vec2D   Vec2D::operator*(const Vec2D& rhs) const
{
    Vec2D v(x * rhs.x, y * rhs.y);
    return v;
}

void Vec2D::operator*=(const Vec2D& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
}

Vec2D Vec2D::operator/(const Vec2D& rhs) const
{
    Assert(rhs.x != 0.0f && rhs.y != 0.0f);
    Vec2D v(x / rhs.x, y / rhs.y);
    return v;
}

void Vec2D::operator/=(const Vec2D& rhs)
{
    Assert(rhs.x != 0.0f && rhs.y != 0.0f);
    x /= rhs.x;
    y /= rhs.y;
}


float Vec2D::dotMul(const Vec2D& vec) const
{
    float r = x*vec.x + y*vec.y;
    return r;
}

float Vec2D::norma() const  // sqrt(x^2 + y^2)
{
    float n = (float)sqrt(x*x + y*y);
    return n;
}

Vec2D Vec2D::unitVec() const
{
    return *this/norma();
}

Vec2D& Vec2D::zero()
{
    static Vec2D zeroVec;
    return zeroVec;
}

