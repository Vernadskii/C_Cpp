#pragma once
#include <vector>
using namespace std;

template < typename T >
vector <T> SMA(const vector<T>* indication, const int n, char16_t window);

template < typename T >
void print_vector(vector <T>* v);

