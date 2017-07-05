//
// Created by lifka on 18/06/17.
//

#include "Point2D.h"

Point2D::Point2D(int x, int y){
    this->x = x;
    this->y = y;
}

int Point2D::getX() {
    return x;
}

int Point2D::getY() {
    return y;
}

void Point2D::setX(int x) {
    this->x = x;
}

void Point2D::setY(int y) {
    this->y = y;
}

std::pair<int,int> Point2D::getPosition() {
    return std::make_pair(x,y);
}

Point2D::Point2D() {
    x = 0;
    y = 0;
}
