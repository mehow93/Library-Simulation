#include <gtest/gtest.h>
#include "../Librarian.hpp"

TEST(LibrarianTest, CreateBookTest)
{
    Librarian testLibrarian;
    Book modelBook;
    modelBook.authorsSurname = "authorsSurname";
    modelBook.authorsName = "authorsName";
    modelBook.title = "Title";

    auto testBook = testLibrarian.createBookRecord("authorsSurname", "authorsName", "Title");

    ASSERT_FALSE(testBook.isBorrowed);
    ASSERT_STREQ(modelBook.authorsSurname.c_str(), testBook.authorsSurname.c_str());
    ASSERT_STREQ(modelBook.authorsName.c_str(), testBook.authorsName.c_str());
    ASSERT_STREQ(modelBook.title.c_str(), testBook.title.c_str());
}