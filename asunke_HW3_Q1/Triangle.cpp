//
// Created by Adithi Sunke on 3/24/25.
//

#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle() : Polygon() {}

Triangle::Triangle(int w, int h) : Polygon(w, h) {}

int Triangle::getArea() {
    return (width * height) / 2; //triangle's area
}

//symmetric triangle/centered stars
void Triangle::draw() {
    int base_width = (2 * height) - 1;
    for (int i = 1; i <= height; ++i) {
        int stars = (2 * i) - 1;
        int spaces = (base_width - stars) / 2;

        //leading spaces
        for (int s = 0; s < spaces; ++s)
            cout << " ";

        //stars
        for (int j = 0; j < stars; ++j)
            cout << "*";

        cout << endl;
    }
}
