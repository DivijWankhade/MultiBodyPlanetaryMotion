/*Q6 solution

Implementation of the Runge Kutta functions

*/

#include "RK_4Functions.h"
#include "BodyData.h"


#include <cmath>
#include <vector>

//Calculates K1/K2/K3/K4 coefficients based on V input for body number i at time instant k 
void RKConsts(double (&K)[4],double (&V)[4],vector<BodyData> Bodies,unsigned int i,unsigned int k, unsigned int N,double const delta_t,double const G){     
    K[0] = delta_t*V[2];                                
    K[1] = delta_t*V[3];
    
    double xAccel=0.0,yAccel=0.0,AccelSumDenom=0.0;
    
    
    for (unsigned int j=0; j<N; j++){  //j represents every other body
        if (j==i){
            
            continue;
            
        }
        else{
            //Implementation of equation 1 from CNM 2 briefing sheet
            AccelSumDenom = pow( pow(Bodies[j].Getx(k) - V[0],2) + pow(Bodies[j].Gety(k) - V[1],2) , 0.5 ); //Denominator separated for easier readability
            xAccel = xAccel + G*( (Bodies[j].Getm()/pow(AccelSumDenom,3)) * (Bodies[j].Getx(k)-(V[0]) ) );
            yAccel = yAccel + G*( (Bodies[j].Getm()/pow(AccelSumDenom,3)) * (Bodies[j].Gety(k)-(V[1]) ) );
            
        }
    }
    
    
    K[2] = delta_t * xAccel;
    K[3] = delta_t * yAccel;
    
}

//Creates the elements of Vnew based on old V and whether K1,K2,K3 or K4 needs to be calculated
void RKChangeInput(double V[4],double (&Vnew)[4],double RKconstantWeight,double K[4]){
    
    Vnew[0] = V[0] + RKconstantWeight*K[0];    //RKconstantWeights takes the value 0.5 when calculating K2 and K3 but 1.0 when calculating K4 as per formula
    Vnew[1] = V[1] + RKconstantWeight*K[1];
    Vnew[2] = V[2] + RKconstantWeight*K[2];
    Vnew[3] = V[3] + RKconstantWeight*K[3];
    
    
}

