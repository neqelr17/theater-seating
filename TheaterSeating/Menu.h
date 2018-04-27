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
		kSellSeat = 2,
		kSellGroup =3,
		kStats = 8,
		kExit = 9
	};

	MenuOptions GetMenuChoice();
	bool SetMenuChoice(int option);
	void GetUserChoice();
	void ShowMenu();

private:
	MenuOptions menu_choice_ = MenuOptions::kShowSeating;
};
