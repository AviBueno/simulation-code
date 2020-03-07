#ifndef DEG_HH
#define DEG_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = DESCRIPTION:   
// = FILENAME:      Deg.h
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

class Rad;

class Deg
{
public:
    Deg(float deg = 0.0f);
    Deg(const Rad& rad);

    float       getValue() const;
    operator    float() const           { return getValue(); }

    Deg         deg() const;
    Rad         rad() const;

    Deg         operator-()             { return Deg(-m_deg); }

    static Deg  zero();
    static Deg  pi();

private:
    void        normalize();

private:
    float   m_deg;
};

// END OF FILE //
#endif // DEG_HH //
