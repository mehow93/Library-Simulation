#include "Librarian.hpp"
int Librarian::mID = 0;

void Librarian::printLibrarianData()
{
	std::cout << "Imie: " << this->mName
		<< "\nNazwisko: " << this->mSurname
		<< "\nID: " << this->mID << std::endl;
}

Book Librarian::createBookRecord(std::string p_AuthorsSurname, std::string p_AuthorsName, std::string p_Title, int p_BooksAmount)
{
	Book tempBook{};

	tempBook.authorsName = p_AuthorsName;
	tempBook.authorsSurname = p_AuthorsSurname;
	tempBook.title = p_Title;
	tempBook.booksAmount = p_BooksAmount;

	return tempBook;
}

void Librarian::addBook(std::string p_AuthorsSurname, std::string p_AuthorsName, std::string p_Title, std::vector<Book>& p_Books)
{
	if (p_Books.empty())
	{
		p_Books.push_back(createBookRecord(p_AuthorsSurname, p_AuthorsName, p_Title, 1));
	}
	else
	{
		for (auto& book : p_Books)
		{
			if (book.authorsSurname == p_AuthorsSurname && book.authorsName == p_AuthorsName && book.title == p_Title)
			{
				book.booksAmount++;
				return;
			}
		}
		p_Books.push_back(createBookRecord(p_AuthorsSurname, p_AuthorsName, p_Title, 1));
	}
}

void Librarian::getBookData(std::string& p_AuthorsSurname, std::string& p_AuthorsName, std::string& p_Title, int& p_Amount)
{
	std::cout << "Podaj nazwisko autora.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, p_AuthorsSurname);

	std::cout << "Podaj imie autora.\n";
	std::getline(std::cin, p_AuthorsName);

	std::cout << "Podaj tytul.\n"; 
	std::getline(std::cin, p_Title);

	std::cout << "Podaj ilosc.\n";
	std::cin >> p_Amount;
}