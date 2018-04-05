#pragma once
class Theater
{
public:
	// Public Attributes
	
	// Public Methods
	Theater(int seats, int rows);
	~Theater();
	void display_seating();


private:
	// Private Attributes
	bool ** _seating_chart;
	int _seats_per_row;
	int _rows;
	int _seats;

	// Private methods
	void _empty_seats();
};

