#pragma once
class Theater
{
public:
	// Public Attributes
	
	// Public Methods
	Theater(int seats, int rows);
	Theater(const Theater &theater);
	Theater &operator=(const Theater &theater);
	~Theater();
	void display_seating();
	void sell_seat(int row, int seat);


private:
	// Private Attributes
	bool ** _seating_chart;
	int _seats_per_row;
	int _rows;
	int _seats;
	char _starting_row = 'a';

	// Private methods
	void _empty_seats();
};
