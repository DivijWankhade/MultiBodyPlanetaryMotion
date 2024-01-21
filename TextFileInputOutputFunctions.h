/*Q6 solution

Header file storing the functions related to reading and writing to and from external text files

*/

#ifndef TEXTFILEINPUTOUTPUTFUNCTIONS_H
#define TEXTFILEINPUTOUTPUTFUNCTIONS_H

#include "BodyData.h"


#include <vector>

using namespace std;

void NoOfBodies(unsigned int &N);   //N passed by reference
    
void ReadParameters(unsigned int N,vector<BodyData>& Bodies,float &G_file,float &T_file,float &delta_t_file); //G,T,delta_t passed by reference
    
void WriteToTextFile(vector <BodyData> Bodies,unsigned int N,unsigned int TimeIntervalNumber,double time[]);

#endif // TEXTFILEINPUTOUTPUTFUNCTIONS_H
