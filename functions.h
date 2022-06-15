#ifndef Functions_H
#define Functions_H
//__________________________________________________________________________________________
//##########################################################################################
//  C++ Libraries
//##########################################################################################
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "global.h"
//__________________________________________________________________________________________

using namespace std;

class Functions
{
private:
  double pi_ = 3.14;

  particle first_particle;
  particle second_particle;
  //__________________________________________________________________________________________
  //##########################################################################################
  //  Internal Functions
  //##########################################################################################
	//  Copy function for Mask class, called by operator= and implicit copy functions
	void CopyFunctions(const Functions &f);
  //__________________________________________________________________________________________

public:
  //__________________________________________________________________________________________
  //##########################################################################################
  //  Basic Class Functions
  //##########################################################################################
  Functions();  // Class Constructor
  ~Functions();  //  Class Destructor

  Functions(const Functions &original); //  Implicit copy function, newFunctionsObject(oldFunctionsObject)
  Functions& operator=(const Functions& original);  //  Defines what happens when you use = operator on class
  //__________________________________________________________________________________________

  //__________________________________________________________________________________________
  //##########################################################################################
  //  Internal Functions
  //##########################################################################################
  double PositionDotProduct(particle first, particle second);
  void MomentumDotProduct(particle first, particle second, double &result);
  //__________________________________________________________________________________________
};
#endif
