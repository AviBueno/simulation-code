#ifndef SHAPE_LIST_HH
#define SHAPE_LIST_HH

#include "Shape.h"

#include <vector>
using namespace std;

class ShapeList : public Shape
{
public:
    ShapeList()
    {
    }
    
    ~ShapeList()
    {
        ShapesVec::iterator itr = m_shapesVec.begin();
        while ( itr != m_shapesVec.end() )
        {
            delete *itr;
             itr++;
        }
    }

    void addShape( Shape* pShape )  // Ptr to newly allocated shape object
    {
        // Add the shape to the shapes list
        Assert( pShape );
        m_shapesVec.push_back(pShape);

        // Set me as the shape's parent
        pShape->setParent(this);

        recalcBoundingRect();
    }

    int     getCount() const    { return m_shapesVec.size(); }
    Shape*  getShape(int idx)   { Assert(idx >= 0 && idx < getCount()); return m_shapesVec[idx]; }

    virtual bool        collides( const CVec2D& vec2d )
    {
        bool res = false;
        if ( Shape::collides(vec2d) )
        {
            for ( int i = 0; i < getCount(); i++ )
            {
                Shape* pShape = m_shapesVec[i];
                Assert( pShape );
                if ( pShape->collides(vec2d) )
                {
                    res = true;
                    break;
                }
            }
        }

        return res;
    }

    virtual void        draw(CDC* pDC)
    {
        for ( int i = 0; i < getCount(); i++ )
        {
            Shape* pShape = m_shapesVec[i];
            Assert( pShape );
            pShape->draw(pDC);
        }

        COLORREF color = RGB(0, 255, 0);
        pDC->Draw3dRect(&getBoundingRect(), color, color);
    }

    virtual void        move(const CVec2D& offset )
    {
        for ( int i = 0; i < getCount(); i++ )
        {
            Shape* pShape = m_shapesVec[i];
            Assert( pShape );
            pShape->move(offset);
        }

        // Move this object's base class instance as well
        Shape::move(offset);
    }

    virtual void    recalcBoundingRect()
    {
        // Adjust the bounding rect if needed
        CRect r = invalidRect();
        for ( int i = 0; i < getCount(); i++ )
        {
            Shape* pShape = m_shapesVec[i];
            Assert( pShape );
            const CRect& sRect = pShape->getBoundingRect();
            if ( sRect.left < r.left ) r.left = sRect.left;
            if ( sRect.top < r.top ) r.top = sRect.top;
            if ( sRect.right > r.right ) r.right = sRect.right;
            if ( sRect.bottom > r.bottom ) r.bottom = sRect.bottom;
        }
        
        setBoundingRect(r);     

        // Call base class implementation
        Shape::recalcBoundingRect();
    }

private:
    typedef vector<Shape*> ShapesVec;
    ShapesVec m_shapesVec;
};

#endif  SHAPE_LIST_HH
