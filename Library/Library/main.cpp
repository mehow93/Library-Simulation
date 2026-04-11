
#include <array>
#include <concepts>
#include <forward_list>
#include <iterator>
#include <list>
#include <map>
#include <stdio.h>
#include <type_traits>
#include <vector>

#include "Enums.hpp"
#include "Librarian.hpp"
#include "Library.hpp"
#include "ShortFunctions.hpp"



/*void myMemCpy(const void* source, void* destiny, int bytes)
{
	const char* sr = (const char*)source;
	char* dest = (char*)destiny;

	for (int i = 0; i < bytes; i++)
	{
		dest[i] = sr[i];

	}
}

int reverseBitsOrder(int num)
{
	int singleByteMask = 0x0000000F;
	int andResult = 0x00000000;
	int result = 0x00000000;
	for (int i = 0; i < 8; i++)
	{
		//std::cout << std::hex << num << std::endl;
		andResult = num & singleByteMask;
		//std::cout << std::hex << num << std::endl;
		//std::cout << std::hex << andResult << std::endl;
		num >>= 4;
		//std::cout << std::hex << result << std::endl;
		//std::cout << std::endl;
		result = result << 4;
		std::cout << std::hex << result << std::endl;
		result = result | andResult;
	}

	return result;
}


int fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int silnia(int n)
{
	if (n == 0)
		return 1;
	else
		return n * silnia(n - 1);
}

void intToBinary(int num, int (&tab)[32])
{
	int singleBit = 0;
	int moduloRest = 0;
	int tabOperator = 31;
	for (int i = 0; i < 32; ++i)
	{
		singleBit = num % 2;
		num = num / 2;
		tab[i] = singleBit;
		--tabOperator;

	}
}

class A
{
	int x = 5;
	public:
		void prinX() { std::cout << x << std::endl; };
};

class B
{
	public:
		//B() { std::cout << "Jestek objektem typu B!" << std::endl; };
		
		B(int param = 10) { x = param;  std::cout << "Jestek objektem typu B z default argumentem!" << std::endl; };
		//B(int param) { x = param; std::cout << "Jestek objektem typu B z argumentem!" << std::endl;};
		void prinX() { std::cout << x << std::endl; };
	private:
		int x;
};

template<typename T>
void printValue(const T& value)
{
	std::cout << "Wartosc: " << value << std::endl;
}

template<>
void printValue<bool>(const bool& value)
{
	std::cout << (value ? "true\n" : "false\n");
}

template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
T multiply(T a, T b)
{
	return a * b;
}


/*template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;


// ---------------------------
// 1. DOMYåLNY SZABLON
// (dla typÛw arytmetycznych)
// ---------------------------

template<typename T>
	requires Arithmetic<T>
class TypedAccumulator
{
public:
	void add(const T& var)
	{
		sum += var;
	}

	T value() const
	{
		return sum;
	}

private:
	T sum{};     // sum = 0, ale dzia≥a teø dla float
};


// ---------------------------
// 2. PE£NA SPECJALIZACJA DLA std::string
// ---------------------------

template<>
class TypedAccumulator<std::string>
{
public:
	void add(const std::string& var)
	{
		if (!sum.empty())
			sum += " ";

		sum += var;
	}

	std::string value() const
	{
		return sum;
	}

private:
	std::string sum{};
};


// ---------------------------
// 3. CZ åCIOWA SPECJALIZACJA DLA WSZYSTKICH WSKAèNIK”W T*
// Liczymy tylko ILE razy dodano wskaünik NIE-NULL
// ---------------------------

template<typename T>
class TypedAccumulator<T*>
{
public:
	void add(const T* ptr)
	{
		if (ptr != nullptr)
			++count;
	}

	int value() const
	{
		return count;
	}

private:
	int count = 0;
};

template<typename T>
class TypedAccumulator
{
	public:
		void add(const T& var) requires std::is_arithmetic_v<T> 
		{ 
			sum += var;
			std::cout << "Ogolny template!\n";
		};
		T value() const { return sum; };
	private:
		T sum = 0;
};

/*template<typename T>
	requires std::is_arithmetic_v<T>
class TypedAccumulator<T>
{
public:
	void add(const T& var)
	{
		sum += var;
		std::cout << "Arytmetyczny template!\n";
	};
	T value() const { return sum; };
private:
	T sum = 0;
};

template<>
class TypedAccumulator<std::string>
{
public:
	void add(const std::string& var)
	{ 
		if (!sum.empty())
		{
			sum += " ";
		}
		sum += var;

	};
	std::string value() const 
	{ 
		return sum; 
	};
private:
	std::string sum = "";
};

template<typename T>
class TypedAccumulator<T*>
{
public:
	void add(const T* var)
	{
		if (var != nullptr)
		{
			++sum;
		}
	};
	int value() const { return sum; };
private:
	int sum = 0;
};*/



int main()
{
	//TypedAccumulator<int> a;
	

	Librarian adam;
	adam.printLibrarianData();
	Library biblio;
	char inputKey = ' ';
	while (inputKey != 'q')
	{
		showMenu();
		std::cin >> inputKey;
		if (inputKey == 'B')
		{
			int librarianChoice = 123;
			while (librarianChoice != '0')
			{
				showLibrarianMenu();
				
				std::cin >> librarianChoice;
				if (librarianChoice == LibrarianChoice::ADD_BOOK)
				{
					std::string inputName;
					std::string inputSurname;
					std::string inputTitle;
					int inputAmount;

					adam.getBookData(inputSurname, inputName, inputTitle, inputAmount);
					for (int i = 0; i < inputAmount; i++)
					{
						adam.addBook(inputSurname, inputName, inputTitle, biblio.getLibraryBooks());
					}
				}
				if (librarianChoice == LibrarianChoice::PRINT_BOOKS)
				{
					biblio.printAllBooks();
				}
			}

		}
	}


	

	return 0;
}