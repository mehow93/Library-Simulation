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
    testing::internal::CaptureStdout();
    

    m_testLibrarian.printLibrarianData();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(output.c_str(), "Imie: Adam\nNazwisko: Nowak\nID: 1\n");
}

TEST_F(LibrarianTest, customConstrTest)
{
    testing::internal::CaptureStdout();
    Librarian testLibrarian("Czesiek","Kowalski");

    testLibrarian.printLibrarianData();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_THAT(output.c_str(), testing::HasSubstr("Imie: Czesiek\nNazwisko: Kowalski\n"));
}

TEST_F(LibrarianTest, IDshouldBe2WhenTwoLibrariansWereCreated)
{
    testing::internal::CaptureStdout();
    Librarian testLibrarian("Jan", "Naj");

    testLibrarian.printLibrarianData();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_THAT(output.c_str(), testing::HasSubstr("ID: 2\n"));
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
    Book modelBook;
    modelBook.authorsSurname = "authorsSurname";
    modelBook.authorsName = "authorsName";
    modelBook.title = "Title";

    auto testBook = m_testLibrarian.createBookRecord("authorsSurname", "authorsName", "Title");

    ASSERT_FALSE(testBook.isBorrowed);
    ASSERT_STREQ(modelBook.authorsSurname.c_str(), testBook.authorsSurname.c_str());
    ASSERT_STREQ(modelBook.authorsName.c_str(), testBook.authorsName.c_str());
    ASSERT_STREQ(modelBook.title.c_str(), testBook.title.c_str());
}