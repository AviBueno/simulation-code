//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Deg.cpp
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Deg.h"
#include "Rad.h"
#include <math.h>

Deg::Deg(float deg)
{
    m_deg = deg;
    normalize();
}

Deg::Deg(const Rad& rad)
{
    m_deg = rad.deg();
    normalize();
}

void Deg::normalize()
{
    m_deg = (float)fmodf( m_deg, 2.0f * Deg::pi() );
    if (m_deg > Deg::pi())
    {
        m_deg -= 2.0f * Deg::pi();
    }
}

float Deg::getValue() const
{
    return m_deg;
}

Deg Deg::deg() const
{
    return m_deg;
}

Rad Deg::rad() const
{
    return (m_deg * Rad::pi()) / Deg::pi();
}

Deg Deg::zero()
{
    static Deg zeroDeg(0.0);
    return zeroDeg;
}

Deg Deg::pi()
{
    static Deg piDeg(180.0f);
    return piDeg;
}

