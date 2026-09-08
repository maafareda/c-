#ifndef POINT_H
#define POINT_H
using namespace std;

class point
{
    public:
        point(double& , double& ,char *);
        affiche();
        translate(double&,double&);
        ~point();
    private:
        double abs, crv;
        char non[20];
};

#endif // POINT_H
