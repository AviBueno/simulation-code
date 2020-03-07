#ifndef SHAPEFACTORY_HH
#define SHAPEFACTORY_HH

#pragma once

//==================================================================
// PROJECT:     SimulationLib
// FILENAME:    ShapeFactory.h
// DATE:        1-Oct-2001
// AUTHOR(S):   Avi Bueno
//===================================================================

#include "ShapeId.h"

class Shape;

class ShapeFactory
{
public:
    Shape*  createShape(ShapeId shapeId);

    static ShapeFactory*    getInstance();
    static void             removeInstance();

private:
    ShapeFactory();
    ~ShapeFactory();

private:
    static ShapeFactory* sm_pInstance;
};

#endif // SHAPEFACTORY_HH //
