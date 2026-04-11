#include "Library.hpp"



void Library::printAllBooks()
{

	for (const auto& oneTypeBooksVector : mBooks)
	{
		std::cout << "Tytul: " << oneTypeBooksVector[0].title;
		std::cout << "\nAutor: " << oneTypeBooksVector[0].authorsSurname << ", " << oneTypeBooksVector[0].authorsName << std::endl;
		std::cout << "Ilosc: " << oneTypeBooksVector.size() << std::endl;
		std::cout << "Z czego dostepne: " << countOnlyAvaliableBooks(oneTypeBooksVector) << std::endl;
	}
}

int Library::countOnlyAvaliableBooks(const std::vector<Book>& oneTypeBook)
{
	int avalBooksCounter = 0;
	for (const auto& book : oneTypeBook)
	{
		if (book.isBorrowed == false)
		{
			avalBooksCounter++;
		}
	}
	return avalBooksCounter;
}

/*void Library::addBook(Book p_Book)
{
	mBooks.push_back(p_Book);
}*/