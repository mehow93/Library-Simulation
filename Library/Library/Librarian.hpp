#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ShortFunctions.hpp"



class Librarian
{
	public:
		Librarian(std::string p_Name = "Adam", std::string p_Surname = "Nowak") : mName(p_Name), mSurname(p_Surname)
		{
			mID++;
		}
		void printLibrarianData();
		Book createBookRecord(std::string p_AuthorsSurname, std::string p_AuthorsName, std::string p_Title);
		void getBookData(std::string& p_AuthorsSurname, std::string& p_AuthorsName, std::string& p_Title, int& p_Amount);
		void addBook(std::string p_AuthorsSurname, std::string p_AuthorsName, std::string p_Title, std::vector<std::vector<Book>>& p_Books);
	private:
		std::string mName;
		std::string mSurname;
		static int mID;




		



};
