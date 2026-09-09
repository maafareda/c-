#include "point.h"

point::point(string n, float x1, float y1) {
    nom = n;
    x = x1;
    y = y1;
}

string point::getNom() {
    return nom;
}

float point::getX() {
    return x;
}

float point::getY() {
    return y;
}
