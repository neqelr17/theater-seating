// TheaterSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "Theater.h"


int main()
{
	const int seats = 9;
	const int rows = 10;

	Theater theater = Theater(seats, rows);
	theater.DisplaySeating();

    return 0;
}
