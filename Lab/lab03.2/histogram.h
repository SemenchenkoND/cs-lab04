#ifndef INCLUDE_HISTOGRAM_H
#define INCLUDE_HISTOGRAM_H
#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
#pragma once
using namespace std;

struct Input {
	vector<double> numbers;
	size_t bin_count;
};
Input read_input(istream& in, bool prompt);
vector<double> input_numbers(size_t number_count, istream& in);
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(Input data);
#endif
