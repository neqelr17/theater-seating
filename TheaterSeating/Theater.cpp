#include "stdafx.h"
#include "Theater.h"

#include <iostream>


//
// Constructor with seats and rows passed in.
Theater::Theater(int seats_per_row, int rows) : _seats_per_row(seats_per_row), _rows(rows), _seats(seats_per_row * rows), _seating_chart(new bool*[rows])
{
	// Allocate seating chart based off of seats and rows.
	for (int row = 0; row < _rows; row++)
	{
		_seating_chart[row] = new bool[_seats_per_row];
	}
	_empty_seats();
}


//
// Copy Constructor
Theater::Theater(const Theater &theater) : _seats_per_row(theater._seats_per_row), _rows(theater._rows),
	_seats(theater._seats), _starting_row(theater._starting_row), _seating_chart(new bool*[theater._rows])
{
	// Copy values of _seating_chart into new Theater _seating_chart
	for (int row = 0; row < _rows; row++)
	{
		_seating_chart[row] = new bool[_seats_per_row];
		for (int seat = 0; seat < _seats_per_row; seat++)
		{
			_seating_chart[row][seat] = theater._seating_chart[row][seat];
		}
	}
}


//
// Overload = operator
Theater &Theater::operator=(const Theater &theater)
{
	// Clean up memory of old _seating_chart to prevent memory leaks
	for (int row = 0; row < _rows; row++)
	{
		delete[] _seating_chart[row];
	}
	delete[] _seating_chart;

	// set attributes
	_seats_per_row = theater._seats_per_row;
	_rows = theater._rows;
	_seats = theater._seats;
	
	// Copy values of theater._seating_chart into new _seating_chart
	_seating_chart = new bool*[theater._rows];
	for (int row = 0; row < _rows; row++)
	{
		_seating_chart[row] = new bool[_seats_per_row];
		for (int seat = 0; seat < _seats_per_row; seat++)
		{
			_seating_chart[row][seat] = theater._seating_chart[row][seat];
		}
	}
	return *this;
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


//
// Mark seat as sold.
void Theater::sell_seat(int row, int seat)
{
	if (row > 0 && row < _rows + 1 && seat > 0 && seat < _seats_per_row + 1)
	{
		_seating_chart[row - 1][seat - 1] = true;
	}
}
