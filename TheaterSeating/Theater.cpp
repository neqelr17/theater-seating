#include "stdafx.h"
#include "Theater.h"

#include <iostream>


//
// Constructor with seats and rows passed in.
Theater::Theater(int seats_per_row, int rows)
{
	// Set member seats and rows
	_seats_per_row = seats_per_row;
	_rows = rows;
	_seats = _seats_per_row * _rows;

	// Allocate seating chart based off of seats and rows.
	_seating_chart = new bool*[_rows];
	for (int row = 0; row < _rows; row++)
	{
		_seating_chart[row] = new bool[_seats_per_row];
	}
	_empty_seats();
}


//
// Destructor
Theater::~Theater()
{
	// Delete _seating_chart
	for (int row = 0; row < _rows; row++)
	{
		delete[] _seating_chart[row];
	}
	delete[] _seating_chart;
}

//
// Empty all seats
void Theater::_empty_seats()
{
	for (int row = 0; row < _rows; row++)
	{
		for (int seat = 0; seat < _seats_per_row; seat++)
		{
			_seating_chart[row][seat] = false;
		}
	}
}

//
// Display seating chart
void Theater::display_seating()
{
	std::cout << "Row       Seats" << std::endl;

	std::cout << "    ";
	for (int seat = 0; seat < _seats_per_row; seat++)
	{
		std::cout << seat + 1 << " ";
	}
	std::cout << std::endl;
	
	for (int row = 0; row < _rows; row++)
	{
		printf("%-3c", _starting_row + row);
		for (int seat = 0; seat < _seats_per_row; seat++)
		{
			std::cout << '|';
			if (_seating_chart[row][seat])
			{
				std::cout << '*';
			}
			else
			{
				std::cout << '#';
			}
		}
		std::cout << '|' << std::endl;
	}
}