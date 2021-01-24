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
		//print_vector(&sma);
		assert(sma == res);
	}

	vector <float> input1 = { 0 };
	vector <float> res1 = { 0 };
	for (auto i : windows)
	{
		vector <float> sma1 = SMA<float>(&input1, input1.size(), i);
		assert(sma1 == res1);
	}

	vector <double> input2 = { 5, 8, 3, 2, 1 };
	vector <double> res2 = { 4.5, 0.25 };
	vector <double> sma2 = SMA<double>(&input2, input2.size(), 4);
	assert(sma2 == res2);
	vector <float> input3 = { 5, 8, 3, 2, 1 };
	vector <float> res3 = { 4.5, 0.25 };
	vector <float> sma3 = SMA<float>(&input3, input3.size(), 4);
	assert(sma2 == res2);


	
	return true;
}