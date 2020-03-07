//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Rad.cpp
// = DATE:          26-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Rad.h"
#include "Deg.h"
#include <math.h>

Rad::Rad(float rad)
{
    m_rad = rad;
}

Rad::Rad(const Deg& deg)
{
    m_rad = deg.rad();
}

void Rad::normalize()
{
    m_rad = (float)fmodf( m_rad, 2.0f * Rad::pi() );
    if (m_rad > Rad::pi())
    {
        m_rad -= 2.0f * Rad::pi();
    }
}

float Rad::getValue() const
{
    return m_rad;
}

Deg Rad::deg() const
{
    return (m_rad * Deg::pi()) / Rad::pi();
}

Rad Rad::rad() const
{
    return m_rad;
}

Rad Rad::zero()
{
    static Rad zeroRad(0.0); return zeroRad;
}

Rad Rad::pi()
{
    static Rad piRad(3.1415926535897932384626433832795f);
    return piRad;
}
