// Modified by Nathan Smith 2/2/2016
// Original source attribution available
// Modified by M. Molodowitch

// An employee class
#ifndef EMPLOY_H
#define EMPLOY_H

#include <iostream>
#include <string>

using namespace std;

class Book {
	friend ostream & operator<<( ostream &, const Book );
	friend istream & operator>>( istream &, Book & );

public:
   Book( const string first= "", const string last = "",  const string id = "X", const string title = "", const string year = "-1");  // constructor
   ~Book();                       // destructor
   Book & setAuthorFirstName( const string);
   Book & setAuthorLastName( const string);
   Book & setID( const string );
   Book & setTitle( const string );
   Book & setYear(const string);
   const string getFirstName() const;  // return author's first name
   const string getLastName() const;   // return author's last name
   const string getID() const;
   const string getTitle() const;
   const string getYear() const;

   // for comparison operators <, >, ==,  only the ID value is looked at
   bool operator<(const Book & right) const; 
   
   bool operator>(const Book & right)const;
    
   bool operator==(const Book & right)const;


  
private:
   string authorFirstName;
   string authorLastName;
   string ID;
   string title;
   string year;
};

#endif



