#include "Simple_moving_average.h"
#include <cassert>
#include <iostream>

using namespace std;

bool test()
{
	vector <double> v = { 0 };
	vector <double> sma = SMA(&v, v.size(), 4);
	print_vector(&sma);
	//assert((SMA(&v, v.size(), 4)) == {0});
	return true;
}