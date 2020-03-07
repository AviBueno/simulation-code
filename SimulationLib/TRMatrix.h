#ifndef TRMATRIX_HH
#define TRMATRIX_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      TRMatrix.h
// = DATE:          27-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

class Vec2D;
class Ang;
class Location;

class TRMatrix
{
public:
    TRMatrix();
    TRMatrix(const Vec2D& translationVec);                      // Translation mtx
    TRMatrix(const Ang& yaw);                                   // Rotation mtx
    TRMatrix(const Vec2D& translationVec, const Ang& yaw);      // Transformation mtx
    TRMatrix(const Location& loc);                              // Transformation mtx
    TRMatrix(float scaleX, float scaleY);                       // Scaling mtx
    TRMatrix(const TRMatrix& other);                // Copy c'tor

    // General
    void    makeUnitMatrix();
    void    init(const TRMatrix& other);
    void    init(const Ang& yaw);
    void    init(const Vec2D& translationVec);
    void    translate(const Vec2D& vec);
    void    translate(float x, float y);


    // Scaling
    void    scale(float sx, float sy);
    void    scale(float scalar);

    // Rotate about the z axis
    void    rotate(const Ang& yaw);

    // Operations
    void            operator = (const TRMatrix& tm);    // Copy assignment
    friend Vec2D    operator * (const Vec2D& vec, const TRMatrix& tm);

    TRMatrix        operator * (const Vec2D& vec) const;    // Translation
    void            operator *= (const Vec2D& vec);         // Translation
    
    TRMatrix        operator * (const TRMatrix& tm) const;
    void            operator *= (const TRMatrix& tm);

private:
    float m_matrix[3][3];
};

#endif // TRMATRIX_HH //
