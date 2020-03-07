#ifndef ENTITY_HH
#define ENTITY_HH

#pragma once

//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Entity.h
// = DATE:          1-Oct-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Location.h"
#include "Assert.h"

class Shape;

class Entity
{
public:
    Entity();
    Entity(const Location& loc);
    ~Entity();

    void            setLocation(const Location& loc);
    const Location& getLocation() const { return m_location; }

    void            setShapePtr(Shape* pShape);
    const Shape*    getShapePtr() const
    {
        Assert(m_pShape);
        return m_pShape;
    }

private:
    Location    m_location;
    Shape*      m_pShape;
};

#endif // ENTITY_HH //
