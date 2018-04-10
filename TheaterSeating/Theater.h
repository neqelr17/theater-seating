#pragma once
class Theater
{
public:
	// Public Attributes
	
	// Constructor and Operator Methods
	Theater(int seats, int rows);
	Theater(const Theater &theater);
	Theater &operator=(const Theater &theater);
	~Theater();

	// Public Methods
	void DisplaySeating();
	void DisplaySeating(const int &row, const int &seat_start, const int &seat_end);
	void SellSeat(const int &row, const int &seat);
	bool SeatAvailible(const int &row, const int &seat);
	bool ValidateSeat(const int &row, const int &seat);
	int ConvertRowToInt(const char &row);


private:
	// Private Attributes
	bool ** seating_chart_;
	int seats_per_row_;
	int rows_;
	int seats_;
	char starting_row_ = 'a';

	// Private methods
	void EmptySeats();
};
