//==================================================================
// = PROJECT:       SimulationLib
// = FILENAME:      Entity.cpp
// = DATE:          1-Oct-2001
// = AUTHOR(S):     Avi Bueno
//===================================================================

#include "Entity.h"
#include "Shape.h"

Entity::Entity()
{
}

Entity::Entity(const Location& loc)
{
    setLocation(loc);
}

Entity::~Entity()
{
    if ( m_pShape )
    {
        delete m_pShape;
    }
}

void Entity::setLocation(const Location& loc)
{
    m_location = loc;
}

void Entity::setShapePtr(Shape* pShape)
{
    Assert(pShape);
    m_pShape = pShape;
}
