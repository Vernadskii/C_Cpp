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
	quantity - количество тиков, LO и HI - левая и правая границы рандома,
	empty_data - пустой вектор для заполнения*/
template < typename T >
void create_data(const int& quantity, const int& LO, const int& HI, vector <T> * empty_data)
{
	srand(static_cast<unsigned int> (time(NULL)));
	T rand_number = 0;
	for (auto i = 0; i < quantity; i++)
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
	if (count != 0) // Заносим последнюю сумму, членов которой не хватило до полного окна и сообщаем об этом
	{
		result_v.push_back(sum / static_cast<T>(window));
		cout << "Last element in result didn't have enought ticks" << endl;
	}
	return result_v;
}

int main()
{
	int quantity = 19;
	int window = 8;
	vector <double> data;
	data.reserve(quantity);
	create_data<double>(quantity, -100, 100, &data);
	vector <double> result = SMA<double>(&data, quantity, window);
	print_vector(&result);
	return 0;
}