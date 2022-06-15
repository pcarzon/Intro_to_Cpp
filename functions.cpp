#include "functions.h"

//__________________________________________________________________________________________
//##########################################################################################
//  Class constructor
//    Create empty Functions
//##########################################################################################
Functions::Functions()
{
  first_particle.SetPosition({0.5, 0.4, 0.3});
  first_particle.SetMomentum({0.1, 0.2, 0.3});

  second_particle = particle({3.1, 4.5, 9.8}, {1, 2, 3});
}
//__________________________________________________________________________________________

//__________________________________________________________________________________________
//##########################################################################################
//  Class deconstructor
//##########################################################################################
Functions::~Functions()
{

}
//__________________________________________________________________________________________

//__________________________________________________________________________________________
//##########################################################################################
//  Implicit Copy
//##########################################################################################
Functions::Functions(const Functions &original)
{
  CopyFunctions(original);
}
//__________________________________________________________________________________________

//__________________________________________________________________________________________
//##########################################################################################
//  Overide operator=
//##########################################################################################
Functions& Functions::operator= (const Functions& original)
{
	CopyFunctions(original);
	return *this;
}
//__________________________________________________________________________________________

//__________________________________________________________________________________________
//##########################################################################################
//  Functions Copy Function
//##########################################################################################
void Functions::CopyFunctions(const Functions &f)
{
  first_particle = f.first_particle;
  second_particle = f.second_particle;
}
//__________________________________________________________________________________________

//__________________________________________________________________________________________
//##########################################################################################
//  Position Dot Product Function
//##########################################################################################
double Functions::PositionDotProduct(particle first, particle second)
{
  vector<double> part1 = first.GetPosition();
  vector<double> part2 = second.GetPosition();

  return part1[0]*part2[0] + part1[1]*part2[1] + part1[2]*part2[2];
}
//__________________________________________________________________________________________

//__________________________________________________________________________________________
//##########################################################################################
//  Momeuntum Dot Product Function
//##########################################################################################
void Functions::MomentumDotProduct(particle first, particle second, double &result)
{
  vector<double> part1 = first.GetPosition();
  vector<double> part2 = second.GetPosition();

  result = part1[0]*part2[0] + part1[1]*part2[1] + part1[2]*part2[2];
}
//__________________________________________________________________________________________