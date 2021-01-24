#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


/* Функция для генерации случайных тиков
	quantity - количество тиков в тысячах*/
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
vector <T> SMA(const vector<T>& indication, char16_t window)
{

	return { 0 };
}

int main()
{
	vector <double> data;
	data.reserve(1000);
	create_data<double>(1, -100, 100, &data);
	/*for (auto i = 0; i < 1000; i++)
	{
		cout << data[i] << " " << endl;
	}*/
	//SMA <double>({ 2.9, 8, 9 }, 10);
	return 0;
}