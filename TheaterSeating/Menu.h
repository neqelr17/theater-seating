#pragma once
class Menu
{
public:
	Menu();
	~Menu();

	// Menu options cast from user input.
	enum class MenuOptions
	{
		kShowSeating = 1,
		kSellSeats = 2,
		kStats = 3,
		kExit = 9
	};

	MenuOptions GetMenuChoice();
	bool SetMenuChoice(int option);
	void GetUserChoice();

private:
	MenuOptions menu_choice_ = MenuOptions::kShowSeating;
};
