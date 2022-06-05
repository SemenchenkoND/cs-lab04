#include "histogram.h"


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

vector<size_t> make_histogram(Input data)
{


	double min, max;
	find_minmax(numbers, min, max);


	double bin_size = (max - min) / bin_count;
	vector<size_t> bins(bin_count, 0);
	for (size_t i = 0; i < numbers.size(); i++)
	{
		bool found = false;
		for (size_t j = 0; j < (bin_count - 1) && !found; j++)
		{
			auto lo = min + j * bin_size;
			auto hi = min + (j + 1) * bin_size;
			if ((lo <= numbers[i]) && (numbers[i] < hi))
			{
				bins[j]++;
				found = true;
			}
		}
		if (!found)
		{
			bins[bin_count - 1]++;
		}
	}
	return bins;
}

vector<double> input_numbers(istream& in, size_t count)
{
	vector<double> result(count);
	for (size_t i = 0; i < count; i++)
	{
		in >> result[i];
	}
	return result;
}

Input read_input(istream& in, bool prompt)
{
	Input data;

	size_t number_count;
	if (prompt)
	{
		cerr << "Enter number count: ";
	}
	in >> number_count;

	if (prompt)
	{
		cerr << "Enter numbers: ";
	}
	data.numbers = input_numbers(in, number_count);

	if (prompt)
	{
		cerr << "Enter bin count: ";
	}
	in >> data.bin_count;



	return data;
}

void show_histogram_text(vector <size_t> bins)
{
	const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

	size_t max_bin = bins[0];
	for (double bin : bins)
	{
		if (bin > max_bin)
		{
			max_bin = bin;
		}
	}

	size_t maxhigth;
	if (max_bin < 76)
		maxhigth = max_bin;
	else
		maxhigth = 76;
	for (double bin : bins)
	{
		size_t height = bin;
		// проверить масштабирование(пересчитать height)

		if (height > MAX_ASTERISK)
		{
			height = MAX_ASTERISK * (static_cast<double> (bin) / max_bin);
		}


		if (bin < 100) {
			cout << " ";
		}

		if (bin < 10) {
			cout << " ";
		}
		for (size_t i = 0; i < maxhigth - height; i++)
			cout << " ";

		for (size_t i = 0; i < height; i++)
		{
			cout << "*";
		}
		cout << "|" << bin << endl;

	}

}