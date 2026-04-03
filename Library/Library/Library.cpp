#include "Library.hpp"



void Library::printAllBooks()
{

	for (const auto& book : mBooks)
	{
		std::cout << "Tytul: " << book.title;
		std::cout << "\nAutor: " << book.authorsSurname << ", " << book.authorsName;
		std::cout << "\nStan: " << book.booksAmount << std::endl;
	}
}


void Library::addBook(Book p_Book)
{
	mBooks.push_back(p_Book);
}