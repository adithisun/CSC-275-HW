//
// Created by Adithi Sunke on 3/24/25.
//

#ifndef ASUNKE_HW3_Q1_RECTANGLE_H
#define ASUNKE_HW3_Q1_RECTANGLE_H

#include "Polygon.h"
#include <iostream>

class Rectangle : public Polygon {
public:
    Rectangle();
    Rectangle(int w, int h);
    int getArea() override;
    void draw() override;

};


#endif //ASUNKE_HW3_Q1_RECTANGLE_H
