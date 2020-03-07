#ifndef RAD_HH
#define RAD_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = DESCRIPTION:   Radian angle representation
// = FILENAME:      Rad.h
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

class Deg;

class Rad
{
public:
    Rad(float rad = 0.0f);
    Rad(const Deg& deg);

    float       getValue() const;
    operator    float() const                   { return getValue(); }

    Deg         deg() const;
    Rad         rad() const;

    Rad         operator-()                     { return Rad(-m_rad); }

    static Rad  zero();
    static Rad  pi();

private:
    void        normalize();

private:
    float   m_rad;
};

#endif // RAD_HH //
