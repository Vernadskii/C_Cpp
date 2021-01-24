#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


/* Функция для генерации случайных тиков
	quantity - количество тиков в тысячах*/
template < typename T >
vector <T> create_data(const int& quantity, const int& LO, const int& HI)
{
	vector <T> result;
	result.reserve(quantity * 1000);
	srand(time(NULL));
	T rand_number = 0;
	for (auto i = 0; i < quantity * 1000; i++)
	{
		result.push_back(LO + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (HI - LO))));
		//rand_number = LO + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (HI - LO)));
		//cout << rand_number << ' ' << endl;
	}
	return result;
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
	vector<double> data = create_data<double>(1, -100, 100);
	//SMA <double>({ 2.9, 8, 9 }, 10);
	return 0;
}