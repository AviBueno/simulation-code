//==================================================================
// PROJECT:     SimulationLib
// FILENAME:    ShapeFactory.cpp
// DATE:        1-Oct-2001
// AUTHOR(S):   Avi Bueno
//===================================================================

#include "ShapeFactory.h"
#include "Shape.h"
#include "Assert.h"

#define arrSize(a)      sizeof(a) / sizeof(a[0])

ShapeFactory* ShapeFactory::sm_pInstance = new ShapeFactory;

Vec2D tankShape[] = {
    Vec2D(0,0),
    Vec2D(0,25),
    Vec2D(5,25),
    Vec2D(5,15),
    Vec2D(10,15),
    Vec2D(10,30),
    Vec2D(15,30),
    Vec2D(15,15),
    Vec2D(20,15),
    Vec2D(20,25),
    Vec2D(25,25),
    Vec2D(25,0),
    Vec2D(20,0),
    Vec2D(20,10),
    Vec2D(5,10),
    Vec2D(5,0),

    Vec2D(0,0)
};

Vec2D weaponShape[] = {
    Vec2D(0,0),
    Vec2D(2,10),
    Vec2D(4,0),

    Vec2D(0,0)
};

Vec2D wall1Shape[] = {
    Vec2D(0,0),
    Vec2D(0,20),
    Vec2D(50,20),
    Vec2D(50,0),
    Vec2D(45,0),
    Vec2D(45,15),
    Vec2D(5,15),
    Vec2D(5,0),

    Vec2D(0,0)
};

ShapeFactory::ShapeFactory()
{
}

ShapeFactory::~ShapeFactory()
{
}

ShapeFactory* ShapeFactory::getInstance()
{
    return sm_pInstance;
}

void ShapeFactory::removeInstance()
{
    delete sm_pInstance;
}

Shape* createShapeFromArray( Vec2D* pVertexList, int vCount )
{
    Assert(  pVertexList );

    Shape* pShape = new Shape();
    Assert( pShape );

    for ( int i = 0; i < vCount; i++ )
    {
        pShape->addVertex( pVertexList[i] );
    }

    return pShape;
}

Shape* ShapeFactory::createShape(ShapeId shapeId)
{
    Assert( shapeId < NUM_SHAPE_IDS );
    Shape* pShape = NULL;

    switch (shapeId)
    {
        case SHP_TANK:      pShape = createShapeFromArray( tankShape, arrSize(tankShape) ); break;
        case SHP_WEAPON:    pShape = createShapeFromArray( weaponShape, arrSize(weaponShape) ); break;
        case SHP_WALL1:     pShape = createShapeFromArray( wall1Shape, arrSize(wall1Shape) ); break;

        default:
            Assert(0);
    }

    Assert(pShape);
    return pShape;
}
