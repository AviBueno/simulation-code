#ifndef ANG_HH
#define ANG_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Ang.h
// = DATE:          27-Sep-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Deg.h"
#include "Rad.h"

class Ang
{
public:
    Ang() : m_ang(Rad::zero())              {}
    Ang(Rad rad) : m_ang(rad)               {}
    Ang(Deg deg) : m_ang(deg.rad())         {}

    Deg     deg() const                     { return m_ang.deg(); }
    Rad     rad() const                     { return m_ang.rad(); }

    Ang     operator + (const Ang& a) const { return Rad(m_ang.rad() + a.rad()); }
    void    operator += (const Ang& a)      { m_ang = Rad(m_ang.rad() + a.rad()); }

    Ang     operator - (const Ang& a) const { return Rad(m_ang.rad() - a.rad()); }
    void    operator -= (const Ang& a)      { m_ang = Rad(m_ang.rad() - a.rad()); }

private:
    Rad m_ang;
};

#endif // ANG_HH //
