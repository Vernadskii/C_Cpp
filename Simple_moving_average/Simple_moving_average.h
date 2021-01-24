#pragma once
#include <vector>
using namespace std;

/* ������� ���������� simple moving average.
	indication - ����� �����, n - ����� �������, window - ����� ����*/
template < typename T >
inline vector <T> SMA(const vector<T>* indication, const int n, char16_t window)
{
	assert(n > 0 && window > 0);
	vector <T> result_v;
	result_v.reserve(n / window + 1);
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
	if (count != 0) // ������� ��������� �����, ������ ������� �� ������� �� ������� ����
	{
		result_v.push_back(sum / static_cast<T>(window));
		//cout << "Last element in result didn't have enought ticks" << endl;
	}
	return result_v;
}

/* ������� ��� ������ �������*/
template < typename T >
inline void print_vector(vector <T>* v)
{
	for (auto i : *v)
	{
		cout << i << " " << endl;
	}
}

