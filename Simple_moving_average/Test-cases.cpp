#include <cassert>
#include <iostream>
#include <vector>
#include <list>
#include "Simple_moving_average.h"

using namespace std;

bool test()
{
	list<int> windows = { 4, 8, 16, 32, 64, 128 };
	vector <double> input = { 0 };
	vector <double> res = { 0 };
	for (auto i : windows)
	{
		vector <double> sma = SMA<double>(&input, input.size(), i);
		print_vector(&sma);
		assert(sma == res);
	}
	
	return true;
}