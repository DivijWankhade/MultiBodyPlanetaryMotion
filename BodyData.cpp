/*Q6 solution

BodyData class implementation
Overloading has been applied for the initialisation

*/
#include "BodyData.h"
#include <cstdlib>
#include <vector>



//Initialises BodyData with default initial conditions if all data isn't specified or erroneous
BodyData::BodyData() : x(static_cast<double>(rand()%5)),y(static_cast<double>(rand()%5)),xdot(0.0),ydot(0.0),m(1.0) {} //x,y will take random integers from 0 and 5 and mass will be 1.0


//Initialises BodyData with initial conditions from Parameters.txt
BodyData::BodyData(double x0,double y0,double xdot0,double ydot0,double mass){
        x.push_back(x0);   //Appends initial conditions to empty x,y,xdot,ydot vectors and mass variable
        y.push_back(y0);
        xdot.push_back(xdot0);
        ydot.push_back(ydot0);
        m=mass;
    }
    
//Returns the x position for a given body at time instant i
double BodyData::Getx(unsigned int i) const{
        return x[i];
    }
    
double BodyData::Gety(unsigned int i) const{
        return y[i];
    }
    
double BodyData::Getxdot(unsigned int i) const{
        return xdot[i];
    }
    
double BodyData::Getydot(unsigned int i) const{
        return ydot[i];
    }
    
double BodyData::Getm() const{  //mass is a single value which remains constant during execution
        return m;
    }
 

//Appends new x position at end of each timestep to x vector in BodyData class
void BodyData::Setx(double xnew){
        x.push_back(xnew);
    }
    
void BodyData::Sety(double ynew){
        y.push_back(ynew);
    }
    
void BodyData::Setxdot(double xdotnew){
        xdot.push_back(xdotnew);
    }
    
void BodyData::Setydot(double ydotnew){
        ydot.push_back(ydotnew);
    }