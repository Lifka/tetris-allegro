//
// Created by lifka on 18/06/17.
//

#include "Point2D.h"

Point2D::Point2D(float x, float y){
    this->x = x;
    this->y = y;
}

float Point2D::getX() {
    return x;
}

float Point2D::getY() {
    return y;
}

void Point2D::setX(float x) {
    this->x = x;
}

void Point2D::setY(float y) {
    this->y = y;
}

std::pair<float,float> Point2D::getPosition() {
    return std::make_pair(x,y);
}

Point2D::Point2D() {
    x = 0;
    y = 0;
}
