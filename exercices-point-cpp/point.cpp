#include "point.h"
#include<iostream>
point::point()
{
    nom='reda';
    abs=0;
    crv=0;
}

point::point(double&x,double&y,char*nam)
{
    nom=nam;
    abs=x;
    crv=y;
}
point::~point()
{
    //dtor
}
