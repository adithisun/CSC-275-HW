//
// Created by Adithi Sunke on 3/21/25.
//

#ifndef ASUNKE_HW3_Q1_POLYGON_H
#define ASUNKE_HW3_Q1_POLYGON_H


class Polygon {
public:
    Polygon();
    Polygon(int newWidth, int newHeight);

    void setWidth(int newWidth);
    void setHeight(int newHeight);

    //pure virtual function for area
    virtual int getArea() = 0;

    //pure virtual function for draw
    virtual void draw() = 0;

protected:
    int width = 0;
    int height = 0;
};


#endif //ASUNKE_HW3_Q1_POLYGON_H
