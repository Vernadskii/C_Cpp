#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


template < typename T >
void print_vector(vector <T>* empty_data, int n)
{
	for (auto i : *empty_data)
	{
		cout << i << " " << endl;
	}
}


/* Функция для генерации случайных тиков
	quantity - количество тиков в тысячах, LO и HI - левая и правая границы рандома,
	empty_data - пустой вектор для заполнения*/
template < typename T >
void create_data(const int& quantity, const int& LO, const int& HI, vector <T> * empty_data)
{
	srand(static_cast<unsigned int> (time(NULL)));
	T rand_number = 0;
	for (auto i = 0; i < quantity * 1000; i++)
	{
		empty_data->push_back(LO + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (HI - LO))));
	}
}


/* Функция вычисления simple moving average.
	indication - набор тиков, window - длина окна*/
template < typename T >
vector <T> SMA(const vector<T>* indication, const int n, char16_t window)
{
	//for (auto i = 0, i<n)
	return { 0 };
}

int main()
{
	int quantity = 1* 1000;
	vector <double> data;
	data.reserve(quantity);
	create_data<double>(quantity/1000, -100, 100, &data);
	print_vector<double>(&data, quantity);
	SMA<double>(&data, quantity, 16);
	return 0;
}