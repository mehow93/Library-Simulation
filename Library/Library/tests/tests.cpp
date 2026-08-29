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

TEST_F(LibrarianTest, 2LibrariansInOneTestLastOneWithIDEq3)
{
    Librarian testLibrarian2("Jan", "Naj");
    ASSERT_EQ(testLibrarian2.getID(), 2);

    Librarian testLibrarian3("Ola", "Cola");
    EXPECT_EQ(testLibrarian3.getID(), 3);

}

TEST_F(LibrarianTest, CreateBookTest)
{
    Book modelBook = {"Title", "authorsName", "authorsSurname" };
    auto testBook = m_testLibrarian.createBookRecord("authorsSurname", "authorsName", "Title");

    ASSERT_FALSE(testBook.isBorrowed);
    ASSERT_STREQ(modelBook.authorsSurname.c_str(), testBook.authorsSurname.c_str());
    ASSERT_STREQ(modelBook.authorsName.c_str(), testBook.authorsName.c_str());
    ASSERT_STREQ(modelBook.title.c_str(), testBook.title.c_str());
}