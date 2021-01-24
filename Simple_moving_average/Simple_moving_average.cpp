#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include "Test-cases.h"
#include "Simple_moving_average.h"

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
	int quantity = 19;
	int window = 8;
	//vector <double> data;
	//data.reserve(quantity);
	//create_data<double>(quantity, -100, 100, &data);
	//vector <double> result = SMA<double>(&data, quantity, window);
	//print_vector(&result);
	return 0;
}