// Nathan Smith 2/2/2016
// Revised Fig. 7.9: employ1.cpp
// M. Molodowitch 10/24/00
// Member function definitions for class Book
#include <iostream>
#include <string>
#include <cassert>
#include "Book.h"
using namespace std;


Book::Book( const string first, const string last ,  const string id, const string title, const string year)
{
   setAuthorFirstName (first);

   setAuthorLastName (last);
 
   setID ( id );

   setTitle (title);

   setYear (year);
}


Book::~Book()
{
 
}

Book & Book::setAuthorFirstName( const string first) 
{
	authorFirstName = first;

	return (*this);
}

Book & Book::setAuthorLastName( const string last ){

	
	authorLastName = last;

	return (*this);
}

Book & Book::setID( const string idNumber ){

	ID = idNumber;

	return (*this);
}

Book & Book::setTitle(const string book_title)
{
	title = book_title;

	return (*this);
}

Book & Book::setYear(const string book_year)
{
	year = book_year;

	return (*this);
}

// Return first name of author
const string Book::getFirstName() const
{
     return authorFirstName;
}

// Return last name of author
const string Book::getLastName() const
{
   return authorLastName;
}

// Returns ID of book
const string Book::getID() const
{
	return ID;
}

// Returns title of book
const string Book::getTitle() const
{
	return title;
}

// Returns year of book
const string Book::getYear() const
{
	return year;
}

bool Book::operator<(const Book & right) const 
{
	   return (ID < right.ID);
 }

bool Book::operator>(const Book & right)const 
{
   return (ID > right.ID);
}

bool Book::operator==(const Book & right)const 
{
   return (ID == right.ID);
}

// Output Overload
ostream & operator<<( ostream & output, const Book book)
{
	output << "Book ID:  " << book.getID() << "\nAuthor: " << book.getLastName()
		<< ", " << book.getFirstName() << "\nTitle: " << book.getTitle() << "\nYear: " << book.getYear()
		<< endl;

	return output;
}

// Input Overload
istream & operator>> (istream & input, Book & book)
{
	string newID;
	string first;
	string last;
	string newTitle;
	string newYear;

	cout << "\nBook ID: " ;
	input >> newID;

	book.setID(newID);

	cout << "\nAuthor's First name: ";
	input >> first;

	book.setAuthorFirstName( first );

	cout << "\nAuthor's Last name: ";
	input >> last;

	book.setAuthorLastName( last );

	cout << "\nBook Title: ";
	input >> newTitle;

	book.setTitle(newTitle);

	cout << "\nBook Year: ";
	input >> newYear;

	book.setYear(newYear);

	return input;
}