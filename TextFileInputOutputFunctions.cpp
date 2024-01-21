/*Q6 solution

Implementation of the functions needed to write to and read from text files

*/

#include "TextFileInputOutputFunctions.h"
#include "BodyData.h"


#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>

using namespace std;

//Calculates number of lines of parameter text file to obtain number of bodies and changes value of N
void NoOfBodies(unsigned int &N){
   
    string line;
    ifstream Parameters("parameters.txt"); 
    
    if (Parameters.good()){
        while (getline(Parameters,line)){
             N++;
        }
        N=N-1;  //have to subtract 1 as first line are the G,delta_t and T constants
        cout<<"From the data there are "<<N<<" bodies"<<endl;
    }    
    else{
        cout<<"Failed to open file"<<endl;
    }
    Parameters.close();
    
}

//Reads the initial conditions for each body into the relvant BodyData class eg.(the initial data for body 1 will be read to the class stored at index 0 of the Bodies vector)
void ReadParameters(unsigned int N,vector<BodyData>& Bodies,float &G_file,float &T_file,float &delta_t_file){
    string line;
    ifstream Parameters("parameters.txt");//Opens parameters text file
    
    float x0,y0,xdot0,ydot0,mass; //initial values of x,y,xdot,ydot

    
    if (Parameters.good()){
        for (unsigned int i = 1; i <= N; i++) {
            
            Parameters.clear();
            Parameters.seekg(0,ios::beg); //resets position read to start of file
            for (unsigned int j=1; j<=i+1; j++){
                if (j==1){
                    Parameters >> G_file >> T_file >> delta_t_file; //line 1 in different format
                    // if data entered in incorrect format on first line
                    if (Parameters.fail()){
                        throw logic_error("Parameters entered in incorrect format");
                    }
                    else if (T_file<=0 || delta_t_file<=0){
                        throw logic_error("Time period and step should be positive numbers");
                    }
                }
                else{
                    Parameters >> x0 >> y0 >> xdot0 >> ydot0 >> mass; 
                    //if data entered in incorrect format on second line
                    if (Parameters.fail()){
                        throw logic_error("Initial conditions of bodies entered in incorrect format");
                    }
                    else if (mass<=0){
                        throw logic_error("Mass of bodies should be greater than 0");
                    }
                }
            }
            
            Bodies.push_back(BodyData(x0,y0,xdot0,ydot0,mass)); //Appends to Bodies vector a new class for each body initialised using their respective initial x,y,xdot,ydot
        }
    }
    else{
        cout<<"Failed to open file"<<endl;
    } 
    Parameters.close();
    
}   

//Outputs data stored in Bodies vector at each time increment to an external text file
void WriteToTextFile(vector <BodyData> Bodies,unsigned int N,unsigned int TimeIntervalNumber,double time[]){
    cout<<"Output File created"<<endl;
    ofstream Simulation("output.txt",ios::out | ios::trunc);  //Starts a new text file to output too
    if (Simulation.good()){
        for (unsigned int i=0;i<=N;i++){   //For each body
            //Data outputted to file in form of: Body number,time,x,y,xdot,ydot
            for (unsigned int k=0;k<=TimeIntervalNumber;k++){
                Simulation.precision(5);   //All data outputted to 5 decimals places and 20 column width for readability
                Simulation << setw(20) << (i+1) << setw(20) << time[k] << setw(20) << Bodies[i].Getx(k)
                        << setw(20) << Bodies[i].Gety(k) << setw(20) << Bodies[i].Getxdot(k)
                        << setw(20) << Bodies[i].Getydot(k) << endl; 
            }
        
        }
 
        
    }
    else{
        cout<<"Failed to open output file"<<endl;
    }
    Simulation.close();
    
}