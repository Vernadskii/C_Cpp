#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include "Test-cases.h"
#include "Simple_moving_average.h"
#include <ctime>
#include <list>

//#define NDEBUG

using namespace std;

/* Функция для генерации случайных тиков
	quantity - количество тиков, LO и HI - левая и правая границы рандома,
	empty_data - пустой вектор для заполнения*/
template < typename T >
void create_data(const int& quantity, const int& LO, const int& HI, vector <T> * empty_data)
{
	assert(LO < HI);
	srand(static_cast<unsigned int> (time(NULL)));
	T rand_number = 0;
	for (auto i = 0; i < quantity; i++)
	{
		empty_data->push_back(LO + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (HI - LO))));
	}
}


int main()
{
	cout << "Would you like to start tests? (1 - Yes, 0 - No) ";
	bool answer = false;
	cin >> answer;
	if (answer)
	{
		test();
	}
	const int quantity = 1000 * 1000;
	//int window = 128;
	const list<int> windows = { 4, 8, 16, 32, 64, 128 };
	vector <float> data;
	data.reserve(quantity);
	create_data<float>(quantity, -100, 100, &data);
	srand(time(0));
	for (auto i : windows)
	{
		clock_t start = clock();
		vector <float> result = SMA<float>(&data, quantity, i);
		clock_t end = clock();
		double seconds = (float)(end - start) / CLOCKS_PER_SEC;
		cout << i << " = window. Runtime = " << seconds << endl; // время работы программы        
		//cout << i <<" = window. Runtime = " << clock() / 1000.0 << endl; // время работы программы        
	}
	
	
	//print_vector(&result);
	
	return 0;
}