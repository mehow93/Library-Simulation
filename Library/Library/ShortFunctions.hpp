#pragma once
#include <iostream>

struct Book
{
	std::string title = "";
	std::string authorsName = "";
	std::string authorsSurname = "";
	bool isBorrowed = false;
};

void showMenu();
void showLibrarianMenu();
