/*Q6 solution

Class header file storing the x,y,xdot,ydot and mass of a body at each time instant

*/
#ifndef BODYDATA_H
#define BODYDATA_H

#include <vector>
using namespace std;

class BodyData{

public:

    BodyData(); 

    BodyData(double x0,double y0,double xdot0,double ydot0,double mass);
    
    double Getx(unsigned int i) const;
    
    double Gety(unsigned int i) const;
    
    double Getxdot(unsigned int i) const;
    
    double Getydot(unsigned int i) const;
    
    double Getm() const;
    
    void Setx(double xnew);
    
    void Sety(double ynew);
    
    void Setxdot(double xdotnew);
    
    void Setydot(double ydotnew);

private:
    vector<double> x;    //Data held privately to prevent unwanted editing
    vector<double> y;
    vector<double> xdot;
    vector<double> ydot;
    double m;
    
};

#endif // BODYDATA_H
