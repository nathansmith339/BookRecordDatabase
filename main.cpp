// Nathan Smith 2/2/2016
// This program uses a stack-type data structure to store and handle the books.
// The books individually hold the id, first and last name of the author, the title, and publication year
// The books are first loaded into memory at the start of the program. Once this is finished, the menu is
// shown to the user. The user can add, search, delete, and print using the list of books. Once the user
// tells the program to quit, the program saves the current database to a file, overwriting existing data,
// The save filename is below as a constant string.
#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "Stack.h"
using namespace std;

const string SAVE_FILE = "textSave.txt";

// Loads the previous save file into the data structure
void loadFile(const string filename, Stack< Book > &book_list);
// Saves the data structure to the file, overwriting data
void saveFile(const string filename, Stack< Book > &book_list);
// Prints out instructions to user
void instructions();
// A main menu for user to interact with
void mainMenu();

int main()
{
	mainMenu();
	system("PAUSE");
	return 0;
}

void loadFile(const string filename, Stack< Book >& book_list)
{
	// Note:	getline is used in order to get the book's entire title
	//			the ignore and get statements are there to remove an
	//			extra space and carriage return respectively.
	ifstream in_file;
	Book oneBook;
	string id, first, last, title, year;

	in_file.open(filename);
	if (in_file.fail())
		cout << "Error opening file to read.\n";
	else
	{
		// loops until record is invalid
		while (in_file >> id >> first >> last >> year)
		{
			in_file.ignore(1);	// ignore the space in between
			getline(in_file, title);

			//set all data in a book
			oneBook.setID(id);
			oneBook.setAuthorFirstName(first);
			oneBook.setAuthorLastName(last);
			oneBook.setYear(year);
			oneBook.setTitle(title);

			//add a new book
			book_list.push(oneBook);
		}
	}
	in_file.close();
}

void saveFile(const string filename, Stack< Book >& book_list)
{
	// Saves in order:		ID, First Name, Last Name, Year, Title
	ofstream out_file;
	Book oneBook;
	string id, first, last, title, year;

	out_file.open(filename);
	if (out_file.fail())
		cout << "Error opening file to write.\n";
	else
	{
		while ( !book_list.isEmpty() )
		{
			oneBook = book_list.pop();
			out_file << oneBook.getID() << " " << oneBook.getFirstName() << " " << oneBook.getLastName() << " "
				 << oneBook.getYear() << " "  << oneBook.getTitle()  << "\n";
		}
	}
	out_file.close();
}

void mainMenu()
{
	Stack< Book > bookStack;
	Book oneBook;
	string id;
	char choice, search_type;
	// load from a save file
	loadFile(SAVE_FILE, bookStack);

	do {
		instructions();
		cin >> choice;
		choice = toupper(choice); // input formatting

		// Note:	Valid choices are:
		//				-N		to input a new book
		//				-F		to find a book by id
		//				-D		to delete a book by id
		//				-P		to print the entire list of books
		//				-Q		to quit the program
		switch (choice) {
		// new book
		case 'N':
			cout << "Enter info for an Book: ";
			cin >> oneBook;
			if (bookStack.push(oneBook))
				cout << "Book added to list.\n";
			else
				cout << "Could not add book to list.\n";
			break;

		// find book (by id)
		case 'F':
			if ( !bookStack.isEmpty() )
			{
				cout << "Enter id to search: ";
				cin >> id;
				oneBook = bookStack.search(id);
				if (oneBook.getYear() != "-1")
					cout << oneBook;
				else
					cout << "Book not found.\n";
			}
			else
				cout << "No books on record.\n";
			break;

		// delete book (by id)
		case 'D':
			if (bookStack.isEmpty())
				cout << "No books on record.\n";
			else
			{
				cout << "Enter id to search: ";
				cin >> id;
				if (bookStack.remove(id))
					cout << "Book removed.\n";
				else
					cout << "Book not found.\n";
			}
			break;

		// print all books
		case 'P':
			if (bookStack.isEmpty())
				cout << "No books on record.\n";
			else
				bookStack.print();

		default:
			break;
		}
	} while (choice != 'Q');
	// Save to file before exiting
	saveFile(SAVE_FILE, bookStack);
}

void instructions()
{
	cout << "\nEnter one of the following:\n"
		<< "  N to add a book to the list\n"
		<< "  F to find a book in the list\n"
		<< "  D to delete a book in the list\n"
		<< "  P to print the whole list\n"
		<< "  Q to quit from the program\n";
}