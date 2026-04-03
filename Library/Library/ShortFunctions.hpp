#pragma once
#include <iostream>

struct Book
{
	std::string title = "";
	std::string authorsName = "";
	std::string authorsSurname = "";
	int booksAmount = 0;
};

void showMenu();
void showLibrarianMenu();
