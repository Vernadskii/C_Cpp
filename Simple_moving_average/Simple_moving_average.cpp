#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


/* Функция для вывода вектора*/
template < typename T >
void print_vector(vector <T>* empty_data)
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
	indication - набор тиков, n - длина вектора, window - длина окна*/
template < typename T >
vector <T> SMA(const vector<T>* indication, const int n, char16_t window)
{
	vector <T> result_v;
	result_v.reserve(n/window + 1);
	int count = 0;
	T sum = 0;
	for (auto element : *indication)
	{
		sum += element;
		count++;
		if (count == window)
		{
			result_v.push_back(sum / static_cast<T>(window));
			sum = 0;
			count = 0;
		}
	}
	if (count != 0) // Заносим последнюю сумму, членов которой не хватило до полного окна
	{
		result_v.push_back(sum / static_cast<T>(window));
	}
	return result_v;
}

int main()
{
	
	int quantity = 1* 1000;
	int window = 16;
	vector <double> data;
	data.reserve(quantity);
	create_data<double>(quantity/1000, -100, 100, &data);
	vector <double> result = SMA<double>(&data, quantity, window);
	print_vector(&result);
	return 0;
}