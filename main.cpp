/*Solution to Q6 of CNM Part 2 Coursework
  CID:02027906
  The solution to this complex problem can be divided into 3 stages:
    1)Obtaining the relevant paramters from the Parameters.txt file
    2)Computing the numerical integration using Runge Kutta 
    3)Outputting the results to the Output.txt file
*/
 
#include "BodyData.h"                                  
#include "RK_4Functions.h"     
#include "TextFileInputOutputFunctions.h"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <exception>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0)); //seeds random function using current time
    
    unsigned int N = 0;
    vector<BodyData> Bodies;  //Each member of the vector is class of a body and its x,y,xdot,ydot data
    float G_file, T_file, delta_t_file; //constants

    NoOfBodies(N);  //Stage 1

    try{    //attempt to catch erroneous inputs of wrong data type in text file
        ReadParameters(N, Bodies, G_file, T_file, delta_t_file); 
    }
    
    catch(const logic_error& e){  //Outputs corresponding error message
        cout<<"An error has occured: "<<e.what()<<endl<<"Default parameters have been used"<<endl;
    }
    
    const float G = G_file;  //Ensures constants value aren't changed 
    const float T = T_file;
    const float delta_t = delta_t_file;
  
    
    unsigned int TimeIntervalNumber = floor(T / delta_t); //1 less than number of times loop must be run(doesn't include 0)

    double t = 0.0;
    double time[TimeIntervalNumber + 1]; //time value at each increment stored in each index

    for(unsigned int k = 0; k <= TimeIntervalNumber + 1; k++) { //stops when t=T

        time[k] = t + k * delta_t; //current time
        for(unsigned int i = 0; i < N; i++) { //Runge Kutta is done on each body before moving to next time step

            double K1[4] = {};  //Initialising arrays that stores all the Runge Kutta constants eg.(K1[2] stores k1 for xdot)
            double K2[4] = {};
            double K3[4] = {};
            double K4[4] = {};

            double V[4] = {}; //Input array used to calculate the K1 array 

            V[0] = Bodies[i].Getx(k);
            V[1] = Bodies[i].Gety(k);
            V[2] = Bodies[i].Getxdot(k);
            V[3] = Bodies[i].Getydot(k);

            double V2[4] = {}; //Input arrays used to calculate K2,K3,K4 arrays respectively
            double V3[4] = {};
            double V4[4] = {};

            RKConsts(K1, V, Bodies, i, k, N, delta_t, G); //Stage 2
            //K1 obtained

            RKChangeInput(V, V2, 0.5, K1);  
            RKConsts(K2, V2, Bodies, i, k, N, delta_t, G);
            //K2 obtained

            RKChangeInput(V, V3, 0.5, K2);
            RKConsts(K3, V3, Bodies, i, k, N, delta_t, G);
            //K3 obtained

            RKChangeInput(V, V4, 1.0, K3);
            RKConsts(K4, V4, Bodies, i, k, N, delta_t, G);
            //K4 obtained

            double xnew, ynew, xdotnew, ydotnew; //V at next time step

            
            xnew = V[0] + ((K1[0]) / 6) + ((K2[0] + K3[0]) / 3) + ((K4[0]) / 6); //Runge Kutta formula for calculating V at next time step
            ynew = V[1] + ((K1[1]) / 6) + ((K2[1] + K3[1]) / 3) + ((K4[1]) / 6);
            xdotnew = V[2] + ((K1[2]) / 6) + ((K2[2] + K3[2]) / 3) + ((K4[2]) / 6);
            ydotnew = V[3] + ((K1[3]) / 6) + ((K2[3] + K3[3]) / 3) + ((K4[3]) / 6);

            

            Bodies[i].Setx(xnew);    //Updates x,y,xdot,ydot data for each body
            Bodies[i].Sety(ynew);
            Bodies[i].Setxdot(xdotnew);
            Bodies[i].Setydot(ydotnew);
        }
        
    }
    cout<<"Integration computed"<<endl;

    WriteToTextFile(Bodies, N, TimeIntervalNumber, time); //Stage 3
    

    return 0;
}
