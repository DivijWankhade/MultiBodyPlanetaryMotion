/*Q6 solution

Header file storing the functions needed to compute the Runge Kutta approximation

*/
#ifndef RK_4FUNCTIONS_H
#define RK_4FUNCTIONS_H

#include "BodyData.h"

#include <vector>

using namespace std;

void RKConsts(double (&K)[4],double (&V)[4],vector<BodyData> Bodies,unsigned int i,unsigned int k, unsigned int N,double const delta_t,double const G); //K and V passed by reference to optimise efficiency by reduing the number of outputs 

void RKChangeInput(double V[4],double (&Vnew)[4],double RKconstantWeight,double K[4]);

#endif // RK_4FUNCTIONS_H
