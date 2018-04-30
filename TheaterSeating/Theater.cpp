#include "stdafx.h"
#include "Theater.h"

#include <iostream>


//
// Constructor with seats and rows passed in.
Theater::Theater(int seats_per_row, int rows, float seat_price) : seats_per_row_(seats_per_row), rows_(rows), seats_(seats_per_row * rows), seating_chart_(new bool*[rows]), seat_price_(seat_price)
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
	seats_(theater.seats_), starting_row_(theater.starting_row_), seat_price_(theater.seat_price_), seating_chart_(new bool*[theater.rows_])
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
	seat_price_ = theater.seat_price_;
	
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
	std::cout << "          Seats        | #: Available |" << std::endl;

	std::cout << "Row ";
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
	std::cout << "          Seats        | #: Available |" << std::endl;

	std::cout << "Row ";
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
			if (selected_row == row && seat >= seat_start && seat < seat_end)
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
	if (row >= 0 && row < rows_ && seat >= 0 && seat < seats_per_row_)
	{
		seating_chart_[row][seat] = true;
	}
}

//
// Mark a group of tickets sold.
void Theater::SellGroup(const int & row, const int & seat_start, const int & ticket_count)
{
	if (row >= 0 && row < rows_ && seat_start >= 0 && seat_start + ticket_count <= seats_per_row_)
	{
		for (int seat = seat_start; seat < seat_start + ticket_count; seat++)
		{
			seating_chart_[row][seat] = true;
		}
	}
}


//
// Check to see if seat is availble
bool Theater::SeatAvailable(const int &row, const int &seat)
{
	return !seating_chart_[row][seat];
}

bool Theater::GroupAvailable(const int & row, const int & seat_start, const int & ticket_count)
{
	bool is_availble = true;

	for (int seat = seat_start; seat < seat_start + ticket_count; seat++)
	{
		if (seating_chart_[row][seat])
		{
			is_availble = false;
		}
	}

	return is_availble;
}


//
// Validate if seat is a valid seat in the theater
bool Theater::ValidateSeat(const int &row, const int &seat)
{
	if (row >= 0 && row < rows_)
	{
		if (seat >= 0 && seat < seats_per_row_)
		{
			return true;
		}
	}
	return false;
}

bool Theater::ValidateGroup(const int & row, const int & seat_start, const int & ticket_count)
{
	bool is_valid = false;
	if (row >= 0 && row < rows_)
	{
		if (seat_start >= 0 && seat_start <= seats_per_row_)
		{
			if (seat_start + ticket_count <= seats_per_row_)
			{
				return true;
			}
		}
	}
	return false;
}

int Theater::TotalSeatsAvailble()
{
	int seats_availble = 0;
	for (int row = 0; row < rows_; row++)
	{
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			if (!seating_chart_[row][seat])
			{
				seats_availble++;
			}
		}
	}
	return seats_availble;
}

int Theater::TotalSeatsSold()
{
	return seats_ - TotalSeatsAvailble();
}

void Theater::DisplaySeatsAvailblePerRow()
{
	for (int row = 0; row < rows_; row++)
	{
		int seats_availble = 0;
		for (int seat = 0; seat < seats_per_row_; seat++)
		{
			if (!seating_chart_[row][seat])
			{
				seats_availble++;
			}
		}
		std::cout << "Row " << (char)(starting_row_ + row) << ": | Seats Availble: " << seats_availble << " |\n";
	}
}


//
// Return int of a given row
int Theater::ConvertRowToInt(const char &row)
{
	return row - starting_row_;
}

int Theater::GetSeatsPerRow()
{
	return seats_per_row_;
}

int Theater::GetAvailableSeatsInRow(int row, int start_seat)
{
	int seats_available = 0;
	for (int seat = start_seat; seat <= seats_per_row_; seat++)
	{
		if (!seating_chart_[row][seat])
		{
			seats_available++;
		}
		else
		{
			break;
		}
	}
	return seats_available;
}

float Theater::GetSeatPrice()
{
	return seat_price_;
}
