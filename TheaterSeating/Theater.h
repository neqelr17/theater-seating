#pragma once
class Theater
{
public:
	// Public Attributes
	
	// Constructor and Operator Methods
	Theater(int seats, int rows, float seat_price);
	Theater(const Theater &theater);
	Theater &operator=(const Theater &theater);
	~Theater();

	// Public Methods
	void DisplaySeating();
	void DisplaySeating(const int &row, const int &seat_start, const int &seat_end);
	void SellSeat(const int &row, const int &seat);
	void SellGroup(const int &row, const int &seat_start, const int &ticket_count);
	bool SeatAvailible(const int &row, const int &seat);
	bool GroupAvailible(const int &row, const int &seat_start, const int &ticket_count);
	bool ValidateSeat(const int &row, const int &seat);
	bool ValidateGroup(const int &row, const int &seat_start, const int &ticket_count);
	
	int ConvertRowToInt(const char &row);
	int GetSeatsPerRow();
	float GetSeatPrice();


private:
	// Private Attributes
	bool ** seating_chart_;
	int seats_per_row_;
	int rows_;
	int seats_;
	char starting_row_ = 'a';
	float seat_price_;

	// Private methods
	void EmptySeats();
};
