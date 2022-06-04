#include "histogram.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
	if (numbers.size() == 0)
	{
		return;
	}

	min = numbers[0];
	max = numbers[0];
	for (double number : numbers)
	{
		if (min > number)
		{
			min = number;
		}
		if (max < number)
		{
			max = number;
		}
	}

}

vector<double> input_numbers(size_t number_count, istream& in)
{
	vector<double> result(number_count);
	for (size_t i = 0; i < number_count; i++)
	{
		in >> result[i];
	}
	return result;
}
