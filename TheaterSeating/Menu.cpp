#include "stdafx.h"
#include "Menu.h"

#include <iostream>


Menu::Menu()
{
}


Menu::~Menu()
{
}


Menu::MenuOptions Menu::GetMenuChoice()
{
	return menu_choice_;
}


bool Menu::SetMenuChoice(int option)
{
	if (option > 0 && option < 4 || option == 9)
	{
		menu_choice_ = static_cast<Menu::MenuOptions>(option);
		return true;
	}
	return false;
}


//
// Prints menu to console.
void Menu::ShowMenu()
{
	std::cout << "\nMenu:\n";
	std::cout << "------------------------------\n";
	std::cout << " 1) Show Available Seating\n";
	std::cout << " 2) Sell Tickets\n";
	std::cout << " 3) Show Theater Statistics\n";
	std::cout << " 9) Exit\n";
	std::cout << "------------------------------\n";
	std::cout << "Enter menu option: ";
}


//
// Display menu to console and request input from user and validate input.
void Menu::GetUserChoice()
{
	int choice = 0;
	bool is_valid = false;
	
	while (!is_valid)
	{
		ShowMenu();

		// Get and validate input from user
		std::cin >> choice;
		if (std::cin.fail() || !SetMenuChoice(choice))
		{
			system("cls");
			std::cout << "Invalid input!\n";
			std::cin.clear();
			std::cin.ignore(999, '\n');
		}
		else
		{
			is_valid = true;
		}
	}
}
