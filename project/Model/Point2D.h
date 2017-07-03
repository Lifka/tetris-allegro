//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_POINT2D_H
#define PROJECT_POINT2D_H

#include <utility>      // std::pair

class Point2D{
private:
    float x;
    float y;
public:
    Point2D(float, float);
    Point2D();
    float getX();
    float getY();
    void setX(float);
    void setY(float);
    std::pair<float, float> getPosition();
};

#endif //PROJECT_POINT2D_H
