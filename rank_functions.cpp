#include <iostream>
#include <iomanip>
#include <cstring>
#include "rank_functions.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	// TODO
	for (int i = 0; i < 9; ++i)
	{
		ary[i] = 0.0; // Set each element to 0
	}
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	// TODO
	for (int i = 0; i < 9; ++i)
	{
		ary[i] = 0; // Set each element to 0
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	const char *na_string = "N/A";
	// TODO
	for (int i = 0; i < 9; ++i)
	{
		std::strncpy(ary[i], na_string, STRING_SIZE - 1);
		ary[i][STRING_SIZE - 1] = '\0';
	}
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE])
{
	// TODO
	int start = 0;
	while (std::isspace(str[start]))
	{
		start++;
	}

	// If all characters are whitespace, return an empty string
	if (start == (int)strlen(str))
	{
		str[0] = '\0';
		return;
	}

	// Find the end of the last non-whitespace character
	int end = strlen(str) - 1;
	while (end >= start && std::isspace(str[end]))
	{
		end--;
	}

	// Create a new string with the trimmed content
	int length = end - start + 1;
	for (int i = 0; i < length; ++i)
	{
		str[i] = str[start + i];
	}

	// Null-terminate the new string
	str[length] = '\0';
}

//-------------------------------------------------------
// Name: get_driver_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_driver_data(double timeArray[], char countryArray[][STRING_SIZE],
					 unsigned int numberArray[], char lastnameArray[][STRING_SIZE])
{
	// TODO
	for (int i = 0; i < 9; i++)
	{
		cin >> timeArray[i];
		cin.ignore();
		if (timeArray[i] < 0)
		{
			return false;
		}
		cin.getline(countryArray[i], STRING_SIZE);
		cin.ignore();
		cin >> numberArray[i];
		cin.ignore();
		cin.getline(lastnameArray[i], STRING_SIZE);
		cin.ignore();
	}
	cout << "hi" << endl;
	return true; // set so it will compile
}

//-------------------------------------------------------
// Name: set_rankings
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void set_rankings(const double timeArray[], unsigned int rankArray[])
{
	// TODO
}

//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
				   const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;

	// print the results, based on rank, but measure the time difference_type
	for (unsigned int j = 1; j <= SIZE; j++)
	{

		// go thru each array, find who places in "i" spot
		for (unsigned int i = 0; i < SIZE; i++)
		{
			if (rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}

			if (rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
			}
		}
	}
}