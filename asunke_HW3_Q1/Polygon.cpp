//
// Created by Adithi Sunke on 3/21/25.
//

#include "Polygon.h"

Polygon::Polygon()
{
    //ctor
}

Polygon::Polygon(int newWidth, int newHeight){
    width = newWidth;
    height = newHeight;

}


void Polygon::setWidth(int newWidth){
    width = newWidth;

}


void Polygon::setHeight(int newHeight){
    height = newHeight;

}