#ifndef Global_H
#define Global_H
//__________________________________________________________________________________________
//##########################################################################################
//  C++ Libraries
//##########################################################################################
#include <vector>
#include <random>

using namespace std;


//__________________________________________________________________________________________
//##########################################################################################
//  Data Structure Used to keep track of particles and their charges
//##########################################################################################
struct particle
{
private:
  vector<double> position = {0., 0., 0.};
  vector<double> momentum = {0., 0., 0.};

public:

  particle();
  particle(vector<double> x, vector<double> p)
  {
    position = x;
    momentum = p;
  }

  ~particle()
  {
      position.clear();
      momentum.clear();
  }

  double particle::operator* (const particle& part)
  {
    return this->momentum[0]*part.momentum[0] + this->momentum[1]*part.momentum[1] + this->momentum[2]*part.momentum[2];
  }

  void SetPosition(double x, double y, double z)
  {
    position[0] = x;
    position[1] = y;
    position[2] = z;
  }

  void SetMomentum(double px, double py, double pz)
  {
    momentum[0] = px;
    momentum[1] = py;
    momentum[2] = pz;
  }

  void SetPosition(vector<double> x) {  position = x; }

  void SetMomentum(vector<double> p) {  momentum = p; }

  //  Returns the set charge of the object
  vector<double> GetPosition() {  return position;  }
  vector<double> GetMomentum() {  return momentum;  }
};
//__________________________________________________________________________________________

#endif
