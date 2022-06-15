//__________________________________________________________________________________________
//##########################################################################################
//	Intro to C++
//
//	https://www.tutorialspoint.com/cplusplus/index.htm
//
//	For questions and comments please email:
//	Patrick Carzon @ pcarzon2@illinois.edu
//##########################################################################################
//__________________________________________________________________________________________


//__________________________________________________________________________________________
//##########################################################################################
//  C++ Libraries
//##########################################################################################
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include <numeric>
#include <random>

#include "global.h"
#include "functions.h"
//__________________________________________________________________________________________


using namespace std;

// 	When running a code from the command line and passing values to it, the information
//	is read in as argc, which is the number of strings passed to the program with the
//	first one being the name of the program by default, and argv, which is an array of
//	the strings passed as arguments to the program
int main (int argc, char *argv[])
{
	cout << argv[0] << endl << argv[1] << endl;


	//__________________________________________________________________________________________
	//##########################################################################################
	//  Input/Output
	//##########################################################################################
	cout << "Input/Output Section" << endl;
	cout << "______________________________________________________________________________________" << endl;

	cout << "Hello World!" << endl;
	cout << "Hello New World!\n";
	// cin can be used to read information in but you wont need to use that often

	ofstream output; // Input is the same just use ifstream and the >> operator
  output.open(argv[1]);

	output << "Hello World!" << endl;

	output.close();

	//__________________________________________________________________________________________


	//__________________________________________________________________________________________
	//##########################################################################################
	//  Variables
	//##########################################################################################
	cout << "Variables" << endl;
	cout << "______________________________________________________________________________________" << endl;

	//	Strings
	string first_string = "This is my first string";
	string secondString;
	secondString = "Don't make me second string!";
	string thirdstring = first_string + "\t" + secondString;
	string NumberToString = to_string(M_PI);
	// char strings are also a thing and act like an array of characters but are not as usefull
	cout  << thirdstring << endl << NumberToString << endl;

	//	Numerics
	int first_int = 10;
	double first_double = 11.23;
	double stringToDouble = stod("3.14");
	// there are more like float, and long/short vatiations but they are not used often

	//	Bool
	bool first_bool = true;
	bool second_bool = 0;

	//	Vectors and Arrays
	//	https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
	int first_array[4];
	int second_array[4] = {1, 2, 3, 4};
	cout << second_array[0] << endl;
	second_array[1] = 5;
	int two_dimensional_array[2][2] = {{1, 2}, {3, 4}};

	//	https://www.programiz.com/cpp-programming/vectors
	vector<double> first_vector = {1., 2., 3., 4.};
	vector<double> second_vector(4, 0.);
	second_vector = {1., 2., 3., 4.};
	second_vector.push_back(5.);
	cout << second_vector.at(0) << " " << second_vector[1] << " " << second_vector.size() << endl;

	vector<double>::iterator first_iterator;
	first_iterator = second_vector.begin();
	cout << *first_iterator << " " << ++*first_iterator << " " << *second_vector.end() << endl;

	// 	Pass by reference
	//	https://www.tutorialspoint.com/cplusplus/cpp_references.htm
	int& reference_to_firstInt = first_int;

	//	Pointers
	//	https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm
	int* first_pointer = &first_int;

	cout << first_pointer << " " << *first_pointer << endl;

	//__________________________________________________________________________________________

	//__________________________________________________________________________________________
	//##########################################################################################
	//  Operations
	//##########################################################################################
	cout << "Operations" << endl;
	cout << "______________________________________________________________________________________" << endl;

	cout << first_int + first_double*(stringToDouble) << endl;
	double calculation = 0;

	calculation += first_int;
	calculation *= first_double;

	int first_count = 0;
	first_count++;
	++first_count;

	//	https://m.cplusplus.com/doc/tutorial/operators/
	//__________________________________________________________________________________________

	//__________________________________________________________________________________________
	//##########################################################################################
	//  Loops and other logic
	//##########################################################################################
	cout << "Loops and Other Logic" << endl;
	cout << "______________________________________________________________________________________" << endl;
	//	https://www.tutorialspoint.com/cplusplus/cpp_loop_types.htm

	if (first_bool == true)
	{

	}
	else if (second_bool == true)
	{

	}
	else {}

	for (int i = 0; i < 10; i++)
	{
			for (int j = 0; j < 10; j++)
			{
				cout << i << " " << j << endl;
			}
	}

	while (first_bool == false)
	{
		first_bool = true;
	}

	do {
		first_bool = true;
	} while (first_bool == false);

	//__________________________________________________________________________________________

	//__________________________________________________________________________________________
	//##########################################################################################
	//  Classes and Structs
	//##########################################################################################
	cout << "Classes and Structs" << endl;
	cout << "______________________________________________________________________________________" << endl;
	//	https://www.geeksforgeeks.org/structure-vs-class-in-cpp/

	particle first_particle;
	particle second_particle({1, 2, 3}, {4, 5, 6});
	first_particle.SetMomentum(2.3, 1.4, 4.6);
	first_particle.SetPosition({4.3, 6.4, 3.2});

	Functions calculator;
	double result = 0.;

	calculator.MomentumDotProduct(first_particle, second_particle, result);

	cout << calculator.PositionDotProduct(first_particle, second_particle) << " " << result << endl;

	//__________________________________________________________________________________________

	//__________________________________________________________________________________________
	//##########################################################################################
	//  Random Number Generators
	//##########################################################################################
	cout << "Random number generation" << endl;
	cout << "______________________________________________________________________________________" << endl;
	int lower = 1, upper = 10;

	srand(time(NULL));
	cout << ((rand() % upper) + lower) << endl;

	default_random_engine get_random_number;
	get_random_number.seed(time(NULL));
	uniform_real_distribution<double> get_number(lower, upper);
	cout << get_number(get_random_number) << endl;

	//__________________________________________________________________________________________

	//__________________________________________________________________________________________
	//##########################################################################################
	//  Monte Carlo
	//##########################################################################################
	cout << "Monte Carlo" << endl;
	cout << "______________________________________________________________________________________" << endl;

	double x, y;
  bool got_glue = false;
  int num_tests = 0;
	double e_thresh = 0.25;
	double e_tot = 10;
  //  Initialize distributions for selecting gluon energy
  uniform_real_distribution<double> get_energy(e_thresh, e_tot);  //  Selects an energy along the x-axis
  uniform_real_distribution<double> get_probability(0.0, 1.01/e_thresh);  //  Selects a probability along the y-axis

	output.open("gluon_energy_dist_test.dat");

  //  Loop until an energy and probability is selected where the probability is less than
  //  the value of the distribution function at selected energy
  while (!got_glue)
  {
    //  Sample random energy and probability
    x = get_energy(get_random_number);
    y = get_probability(get_random_number);

    //  Test if the random probability is less than the function at selected energy
    if (y < 1/x)
		{
    	output << x << " " << y << " " << 1/x << endl;
    	num_tests++;
    	if (num_tests > 10000){ got_glue = true; }
		}
	}
	//__________________________________________________________________________________________

	return 0;
}
