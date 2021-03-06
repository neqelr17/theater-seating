// TheaterSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include "Menu.h"
#include "Theater.h"


// Prototypes
void SellSeat(Theater &theater);
void SellGroup(Theater &theater);
void DisplayStats(Theater &theater);


int main()
{
	// Constant variables
	const int seats = 9;
	const int rows = 10;
	const double seat_price = 29.99;

	bool keep_going = true;

	// Create theater
	Theater theater = Theater(seats, rows, seat_price);

	// Create Menu
	Menu menu = Menu();

	while (keep_going)
	{
		menu.GetUserChoice();
		system("cls");
		switch (menu.GetMenuChoice())
		{
		case Menu::MenuOptions::kShowSeating:
		{
			theater.DisplaySeating();
			break;
		}
		case Menu::MenuOptions::kSellSeat:
		{
			// Sell Seat
			SellSeat(theater);
			break;
		}
		case Menu::MenuOptions::kSellGroup:
		{
			// Sell Group of seats
			SellGroup(theater);
			break;
		}
		case Menu::MenuOptions::kStats:
		{
			// Show stats
			DisplayStats(theater);
			break;
		}
		case Menu::MenuOptions::kExit:
		{
			puts("Exiting...");
			puts("Please Come Again Soon!");
			keep_going = false;
			break;
		}
		}
	}

	return 0;
}


//
// Display Statistics
void DisplayStats(Theater &theater)
{
	theater.DisplaySeating();
	std::cout << "Theater Statistics:\n";
	std::cout << "Total Seats Available: " << theater.TotalSeatsAvailble() << std::endl;
	std::cout << "Total Seats Sold: " << theater.TotalSeatsSold() << std::endl;
	std::cout << "Total Seats Availble Per Row: \n";
	theater.DisplaySeatsAvailblePerRow();
}


//
// Sell Seats
void SellSeat(Theater &theater)
{
	theater.DisplaySeating();

	char row = '\0';
	std::cout << "Enter Row: ";
	std::cin >> row;

	int seat = 0;
	std::cout << "Enter Seat Number: ";
	std::cin >> seat;
	seat -= 1;

	int introw = theater.ConvertRowToInt(row);
	if (theater.ValidateSeat(introw, seat))
	{
		if (theater.SeatAvailable(introw, seat))
		{
			theater.DisplaySeating(introw, seat, seat + 1);
			char correct = '\n';
			std::cout << "Total Price: $" << theater.GetSeatPrice() << std::endl;
			std::cout << "Is this selection correct (y,n): ";
			std::cin >> correct;
			if (correct == 'y')
			{
				theater.SellSeat(introw, seat);
			}
			else
			{
				std::cout << "Cancelling...\n";
			}
		}
		else
		{
			std::cout << "Seat Unavailable!\n";
		}
	}
	else
	{
		std::cout << "Invalid Seat Selected!\n";
	}
}


//
// Sell Group of seats
void SellGroup(Theater &theater)
{
	theater.DisplaySeating();

	char row = '\0';
	std::cout << "Enter Row: ";
	std::cin >> row;
	int introw = theater.ConvertRowToInt(row);

	int seat_start = 0;
	std::cout << "Enter Starting Seat Number: ";
	std::cin >> seat_start;
	seat_start -= 1;

	int ticket_count = 0;
	std::cout << "How Many Seats (Max. "<< theater.GetAvailableSeatsInRow(introw, seat_start) <<") : ";
	std::cin >> ticket_count;

	if (theater.ValidateGroup(introw, seat_start, ticket_count))
	{
		if (theater.GroupAvailable(introw, seat_start, ticket_count))
		{
			theater.DisplaySeating(introw, seat_start, seat_start + ticket_count);
			char correct = '\n';
			std::cout << "Total Price: $" << theater.GetSeatPrice() * ticket_count << std::endl;
			std::cout << "Is this selection correct (y,n): ";
			std::cin >> correct;
			if (correct == 'y')
			{
				theater.SellGroup(introw, seat_start, ticket_count);
			}
			else
			{
				std::cout << "Cancelling...\n";
			}
		}
		else
		{
			std::cout << "Group Unavailable!\n";
		}
	}
	else
	{
		std::cout << "Invalid Seat Selected!\n";
	}
}
