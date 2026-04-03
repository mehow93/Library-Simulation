#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ShortFunctions.hpp"



class Library
{
	public:
		void printAllBooks();
		void addBook(Book p_Book);
		std::vector<Book>& getLibraryBooks() { return mBooks; };
	private:
		std::vector<Book> mBooks;
		

};