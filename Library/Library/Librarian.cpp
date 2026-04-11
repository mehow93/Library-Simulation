#include "Librarian.hpp"
int Librarian::mID = 0;

void Librarian::printLibrarianData()
{
	std::cout << "Imie: " << this->mName
		<< "\nNazwisko: " << this->mSurname
		<< "\nID: " << this->mID << std::endl;
}

Book Librarian::createBookRecord(std::string p_AuthorsSurname, std::string p_AuthorsName, std::string p_Title)
{
	Book tempBook{};

	tempBook.authorsName = p_AuthorsName;
	tempBook.authorsSurname = p_AuthorsSurname;
	tempBook.title = p_Title;

	return tempBook;
}

void Librarian::addBook(std::string p_AuthorsSurname, std::string p_AuthorsName, std::string p_Title, std::vector<std::vector<Book>>& p_Books)
{
	std::vector<Book> tempVector;
	if (p_Books.empty())
	{
		
		tempVector.push_back(createBookRecord(p_AuthorsSurname, p_AuthorsName, p_Title));
		p_Books.push_back(tempVector);
	}
	else
	{
		for (auto& oneTypeBookVector : p_Books)
		{
			if (oneTypeBookVector[0].authorsSurname == p_AuthorsSurname && oneTypeBookVector[0].authorsName == p_AuthorsName && oneTypeBookVector[0].title == p_Title)
			{
				oneTypeBookVector.push_back(createBookRecord(p_AuthorsSurname, p_AuthorsName, p_Title));
				return;
			}

		}
		tempVector.push_back(createBookRecord(p_AuthorsSurname, p_AuthorsName, p_Title));
		p_Books.push_back(tempVector);
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