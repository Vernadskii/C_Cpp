//A Narcissistic Number is a positive number which is the sum of its own digits, each raised to
//the power of the number of digits in a given base.In this Kata, we will restrict ourselves to decimal(base 10).
//
//For example, take 153 (3 digits) :
//
//    1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 1 + 125 + 27 = 153
//    and 1634 (4 digits) :
//
//    1 ^ 4 + 6 ^ 4 + 3 ^ 4 + 4 ^ 4 = 1 + 1296 + 81 + 256

#include <iostream>
#include <string>
#include <cmath>

bool narcissistic(const int& value) 
{
	int res = 0;
	std::string svalue = std::to_string(value);
	for (auto i = 0; i < svalue.length(); i++)
	{
		res += pow(int(svalue[i] - '0'), svalue.length());
	}
	if (res == value) return true;
	return false;
}

int main()
{
	std::cout << narcissistic(153);
	//system("pause");
}