#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../Librarian.hpp"

class LibrarianTest : public testing::Test
{
    protected:
        Librarian m_testLibrarian;
};

TEST_F(LibrarianTest, defaultConstrTest)
{
    ASSERT_EQ("Adam", m_testLibrarian.getName());
    ASSERT_EQ("Nowak", m_testLibrarian.getSurname());
}


TEST_F(LibrarianTest, customNameTest)
{
    Librarian testLibrarian("Czesiek");

    ASSERT_EQ("Czesiek", testLibrarian.getName());
    ASSERT_EQ("Nowak", testLibrarian.getSurname());

}

TEST_F(LibrarianTest, customNameAndSurnameTest)
{
    Librarian testLibrarian("Zbyszek", "Poryszek");

    ASSERT_EQ("Zbyszek", testLibrarian.getName());
    ASSERT_EQ("Poryszek", testLibrarian.getSurname());

}

TEST_F(LibrarianTest, IDshouldBe2WhenTwoLibrariansWereCreated)
{
    Librarian testLibrarian("Jan", "Naj");

    ASSERT_EQ(2, testLibrarian.getID());
}

TEST_F(LibrarianTest, 2LibrariansInOneTestLastOneWithIDEq3)//przepisz ten test
{
    Librarian testLibrarian2("Jan", "Naj");
    Librarian testLibrarian3("Ola", "Cola");

    ASSERT_EQ(testLibrarian2.getID(), 2);
    EXPECT_EQ(testLibrarian3.getID(), 3);

}

TEST_F(LibrarianTest, createBookTest)
{
    Book modelBook = {"Title", "authorsSurname", "authorsName"};
    auto testBook = m_testLibrarian.createBookRecord("Title", "authorsSurname", "authorsName");

    ASSERT_FALSE(testBook.isBorrowed);
    ASSERT_STREQ(modelBook.authorsSurname.c_str(), testBook.authorsSurname.c_str());
    ASSERT_STREQ(modelBook.authorsName.c_str(), testBook.authorsName.c_str());
    ASSERT_STREQ(modelBook.title.c_str(), testBook.title.c_str());
}

/*TEST_F(LibrarianTest, addBookTest_EmptyLibraryBooks)//consider mocking Library class and its function getLibraryBooks()
{
    std::vector<std::vector<Book>> testBooksVector;

    ASSERT_EQ(1, testBooksVector.size());
    EXPECT_EQ(1, testBooksVector[0].size());
    m_testLibrarian.addBook("testTitle", "testSurname", "testName", testBooksVector);

}*/