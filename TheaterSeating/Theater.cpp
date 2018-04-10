#include "stdafx.h"
#include "Theater.h"

#include <iostream>


//
// Constructor with seats and rows passed in.
Theater::Theater(int seats_per_row, int rows) : seats_per_row_(seats_per_row), rows_(rows), seats_(seats_per_row * rows), seating_chart_(new bool*[rows])
{
	// Allocate seating chart based off of seats and rows.
	for (int row = 0; row < rows_; row++)
	{
		seating_chart_[row] = new bool[seats_per_row_];
	}
	EmptySeats();
}


//
// Copy Constructor
Theater::Theater(const Theater &theater) : seats_per_row_(theater.seats_per_row_), rows_(theater.rows_),
	seats_(theater.seats_), starting_row_(theater.starting_row_), seating_chart_(new bool*[theater.rows_])
{
	// Copy values of seating_chart_ into new Theater seating_chart_
	for (int row = 0; row < rows_; row++)
	{
		seating_chart_[row] = new bool[seats_per_row_];
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			seating_chart_[row][seat] = theater.seating_chart_[row][seat];
		}
	}
}


//
// Overload = operator
Theater &Theater::operator=(const Theater &theater)
{
	// Clean up memory of old seating_chart_ to prevent memory leaks
	for (int row = 0; row < rows_; row++)
	{
		delete[] seating_chart_[row];
	}
	delete[] seating_chart_;

	// set attributes
	seats_per_row_ = theater.seats_per_row_;
	rows_ = theater.rows_;
	seats_ = theater.seats_;
	
	// Copy values of theater.seating_chart_ into new seating_chart_
	seating_chart_ = new bool*[theater.rows_];
	for (int row = 0; row < rows_; row++)
	{
		seating_chart_[row] = new bool[seats_per_row_];
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			seating_chart_[row][seat] = theater.seating_chart_[row][seat];
		}
	}
	return *this;
}


//
// Destructor
Theater::~Theater()
{
	// Delete seating_chart_
	for (int row = 0; row < rows_; row++)
	{
		delete[] seating_chart_[row];
	}
	delete[] seating_chart_;
}


//
// Empty all seats
void Theater::EmptySeats()
{
	for (int row = 0; row < rows_; row++)
	{
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			seating_chart_[row][seat] = false;
		}
	}
}


//
// Display seating chart
void Theater::DisplaySeating()
{
	std::cout << "    ______Stage______  ----------------" << std::endl;
	std::cout << "Row       Seats        | #: Availible |" << std::endl;

	std::cout << "    ";
	for (int seat = 0; seat < seats_per_row_; seat++)
	{
		std::cout << seat + 1 << " ";
	}
	std::cout << " | *: Taken     |" << std::endl;
	
	for (int row = 0; row < rows_; row++)
	{
		printf("%-3c", starting_row_ + row);
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			std::cout << '|';
			if (seating_chart_[row][seat])
			{
				std::cout << '*';
			}
			else
			{
				std::cout << '#';
			}
		}
		std::cout << '|';
		if (row == 0)
		{
			std::cout << " ----------------";
		}
		std::cout << std::endl;
	}
}


//
// Display seating chart with selected seats
void Theater::DisplaySeating(const int &selected_row, const int &seat_start, const int &seat_end)
{
	std::cout << "    ______Stage______  ----------------" << std::endl;
	std::cout << "Row       Seats        | #: Availible |" << std::endl;

	std::cout << "    ";
	for (int seat = 0; seat < seats_per_row_; seat++)
	{
		std::cout << seat + 1 << " ";
	}
	std::cout << " | *: Taken     |" << std::endl;

	for (int row = 0; row < rows_; row++)
	{
		printf("%-3c", starting_row_ + row);
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			std::cout << '|';
			if (selected_row == row && seat >= seat_start && seat <= seat_end)
			{
				std::cout << 's';
			}
			else
			{
				if (seating_chart_[row][seat])
				{
					std::cout << '*';
				}
				else
				{
					std::cout << '#';
				}
			}
		}
		std::cout << '|';
		if (row == 0)
		{
			std::cout << " ----------------";
		}
		std::cout << std::endl;
	}
}


//
// Mark seat as sold.
void Theater::SellSeat(const int &row, const int &seat)
{
	if (row > 0 && row < rows_ + 1 && seat > 0 && seat < seats_per_row_ + 1)
	{
		seating_chart_[row - 1][seat - 1] = true;
	}
}


//
// Check to see if seat is availble
bool Theater::SeatAvailible(const int &row, const int &seat)
{
	return seating_chart_[row][seat];
}


//
// Validate if seat is a valid seat in the theater
bool Theater::ValidateSeat(const int &row, const int &seat)
{
	if (row > 0 && row < rows_)
	{
		if (seat > 0 && seat < seats_per_row_)
		{
			return true;
		}
	}
	return false;
}


//
// Return int of a given row
int Theater::ConvertRowToInt(const char &row)
{
	return starting_row_ - row;
}
