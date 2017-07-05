//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_POINT2D_H
#define PROJECT_POINT2D_H

#include <utility>      // std::pair

class Point2D{
private:
    int x;
    int y;
public:
    Point2D(int, int);
    Point2D();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    std::pair<int, int> getPosition();
};

#endif //PROJECT_POINT2D_H
