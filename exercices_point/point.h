#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class point {
private:
    string nom;
    float x;
    float y;

public:
    point(string n, float x1, float y1);

    string getNom();
    float getX();
    float getY();
};

#endif
