//
// Created by Adithi Sunke on 3/24/25.
//

#include "Rectangle.h"

Rectangle::Rectangle() : Polygon() {}
Rectangle::Rectangle(int w, int h) : Polygon(w, h) {}

int Rectangle::getArea() {
    return width * height; //rectangle area
}

void Rectangle::draw() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j)
            std::cout << "*";
        std::cout << std::endl;
    }
}
