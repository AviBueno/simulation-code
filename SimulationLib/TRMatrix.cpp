//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      TRMatrix.cpp
// = DATE:          27-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "TRMatrix.h"
#include "Ang.h"
#include "Vec2D.h"
#include "Location.h"
#include <math.h>


TRMatrix::TRMatrix()
{
    makeUnitMatrix();
}

// Translation mtx
TRMatrix::TRMatrix(const Vec2D& translationVec)
{
    //makeUnitMatrix();
    //translate(translationVec);
    init(translationVec);
}

// Rotation mtx
TRMatrix::TRMatrix(const Ang& yaw)
{
    //makeUnitMatrix();
    //rotate(yaw);
    init(yaw);
}

// Translation + rotation mtx
TRMatrix::TRMatrix(const Vec2D& translationVec, const Ang& yaw)
{
    makeUnitMatrix();
    translate(translationVec);
    rotate(yaw);
}

// Transformation mtx
TRMatrix::TRMatrix(const Location& loc)
{
    makeUnitMatrix();
    translate(loc.getPos());
    rotate(loc.getAngle());
}

// Scaling c'tor
TRMatrix::TRMatrix(float scaleX, float scaleY)
{
    makeUnitMatrix();
    scale(scaleX, scaleY);
}

TRMatrix::TRMatrix(const TRMatrix& other)
{
    init(other);
}

void TRMatrix::makeUnitMatrix()
{
    for (int i=0; i<3; i++)
        for  ( int j=0; j<3; j++ )
            if ( i == j )
                m_matrix[i][j] = 1.0f;
            else
                m_matrix[i][j] = 0.0f;
}

void TRMatrix::init(const TRMatrix& other)
{
    for (int i=0; i<3; i++)
        for  ( int j=0; j<3; j++ )
            m_matrix[i][j] = other.m_matrix[i][j];
}

void TRMatrix::init(const Vec2D& translationVec)
{
    makeUnitMatrix();

    m_matrix[2][0] = translationVec.x;
    m_matrix[2][1] = translationVec.y;
}

void TRMatrix::init(const Ang& yaw)
{
    makeUnitMatrix();

    float siny = sinf(yaw.rad());
    float cosy = cosf(yaw.rad());

    m_matrix[0][0] = cosy;
    m_matrix[0][1] = -siny;
    m_matrix[1][0] = siny;
    m_matrix[1][1] = cosy;
}

void TRMatrix::translate(const Vec2D& vec)
{
    translate(vec.x, vec.y);
}

void TRMatrix::translate(float x, float y)
{
    m_matrix[2][0] = m_matrix[0][0] * x + m_matrix[1][0] * y + m_matrix[2][0];
    m_matrix[2][1] = m_matrix[0][1] * x + m_matrix[1][1] * y + m_matrix[2][1];
    m_matrix[2][2] = m_matrix[0][2] * x + m_matrix[1][2] * y + m_matrix[2][2]; 
}

void TRMatrix::scale(float sx, float sy)
{
    m_matrix[0][0] *= sx;
    m_matrix[0][1] *= sx;
    m_matrix[0][2] *= sx;

    m_matrix[1][0] *= sy;
    m_matrix[1][1] *= sy;
    m_matrix[1][2] *= sy;
}

void TRMatrix::scale(float scalar)
{
    scale(scalar, scalar);
}

void TRMatrix::rotate(const Ang& yaw)
{
    float siny = sinf(yaw.rad());
    float cosy = cosf(yaw.rad());
    
    float a00 = m_matrix[0][0];
    float a01 = m_matrix[0][1];
    float a02 = m_matrix[0][2];

    float a10 = m_matrix[1][0];
    float a11 = m_matrix[1][1];
    float a12 = m_matrix[1][2];
    
    m_matrix[0][0] = (cosy * a00) - (siny * a10); 
    m_matrix[0][1] = (cosy * a01) - (siny * a11); 
    m_matrix[0][2] = (cosy * a02) - (siny * a12); 
    
    m_matrix[1][0] = (siny * a00) + (cosy * a10); 
    m_matrix[1][1] = (siny * a01) + (cosy * a11); 
    m_matrix[1][2] = (siny * a02) + (cosy * a12); 
}

/*
TRMatrix TRMatrix::operator * (const Vec2D& u)
{
    Vec2D v;

    v.x = u.x * tm.m_matrix[0][0] + u.y * tm.m_matrix[0][1] + tm.m_matrix[0][2];
    v.y = u.x * tm.m_matrix[1][0] + u.y * tm.m_matrix[1][1] + tm.m_matrix[1][2];

    return v;
}
*/

Vec2D operator * (const Vec2D& u, const TRMatrix& t)
{
    Vec2D v;

    v.x = u.x * t.m_matrix[0][0] + u.y * t.m_matrix[1][0] + t.m_matrix[2][0];
    v.y = u.x * t.m_matrix[0][1] + u.y * t.m_matrix[1][1] + t.m_matrix[2][1];
    
    return v;
}

TRMatrix TRMatrix::operator * (const Vec2D& vec) const
{
    TRMatrix t(*this);
    t *= vec;
    return t;
}

void TRMatrix::operator *= (const Vec2D& vec)
{
    translate(vec);
}

TRMatrix TRMatrix::operator * (const TRMatrix& b) const
{
    TRMatrix dst;
    const TRMatrix& a = *this;
    
    for (int m=0; m < 3; m++)
    {
        for  ( int n=0; n<3; n++ )
        {
            dst.m_matrix[m][n] = 0.0f;
            for (int i=0; i<3; i++)
            {
                dst.m_matrix[m][n] += a.m_matrix[m][i] * b.m_matrix[i][n];
            }           
        }
    }

    return dst;
}

void TRMatrix::operator *= (const TRMatrix& b)
{
    TRMatrix dst;
    const TRMatrix& a = *this;
    
    for (int m=0; m < 3; m++)
    {
        for  ( int n=0; n<3; n++ )
        {
            dst.m_matrix[m][n] = 0.0f;
            for (int i=0; i<3; i++)
            {
                dst.m_matrix[m][n] += a.m_matrix[m][i] * b.m_matrix[i][n];
            }           
        }
    }

    *this = dst;
}

void TRMatrix::operator = (const TRMatrix& t)
{
    init(t);
}
