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
	void SellSeat(int row, int seat);


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
