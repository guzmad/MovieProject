#include "stdafx.h"
#include "Store.h"
#include "Customer.h"
#include <fstream>
#include <sstream>

Store::Store()
{

}

Store::~Store()
{
}


void Store::populateMovie(string fileName)
{
	char check = ' ';
	char putBack;
	char putBack2;
	string tempStr;
	string line;
	char genre;
	int quantity;
	string director = "";
	string title;
	string majorActor;
	int month;
	int year;
	MovieFactory factory;
	Movie * tempMoviePtr;
	ifstream fin;
	fin.open("data4movies.txt");

	while (!fin.eof()) {
		fin >> genre;
		fin >> check;
		
		if (genre == 'C') {
			fin >> quantity;
			fin >> check;

			fin >> director;
			while (director[director.length() - 1] != ',') {
				fin >> tempStr;
				director += (" " + tempStr);
			}
			director.pop_back();

			fin >> title;
			while (title[title.length() - 1] != ',') {
				fin >> tempStr;
				title += (" " + tempStr);
			}
			title.pop_back();

			fin >> majorActor;
			while (isalpha(majorActor[majorActor.length() - 1])) {
				fin >> tempStr;
				majorActor += (" " + tempStr);
			}

			if (isdigit(majorActor[majorActor.length() - 2])) {     // checks for two digit months
				putBack = majorActor[majorActor.length() - 1];
				putBack2 = majorActor[majorActor.length() - 2];

				stringstream ss;  //convert chars to string
				string s;
				ss << putBack2;
				ss >> s;

				s += putBack;
				
				stringstream convert(s); // convert string to int
				convert >> month;

				majorActor.pop_back();
				majorActor.pop_back();
				majorActor.pop_back();
			}

			else {
				putBack = majorActor[majorActor.length() - 1];
				fin.putback(putBack);

				majorActor.pop_back();
				majorActor.pop_back(); //gets rid of white space

				fin >> month;
			}

			fin >> year;

			tempMoviePtr = factory.createMovie(genre, director, title, majorActor, month, year);
			MovieInventory tempMovieInventory(tempMoviePtr);
			tempMovieInventory.setQuantity(quantity - 1);
			movieList.addMovie(tempMovieInventory);
		}

		else if (genre == 'F' || genre == 'D') {
			fin >> quantity;
			fin >> check;

			fin >> director;
			while (director[director.length() - 1] != ',') {
				fin >> tempStr;
				director += (" " + tempStr);
			}
			director.pop_back();

			fin >> title;
			while (title[title.length() - 1] != ',') {
				fin >> tempStr;
				title += (" " + tempStr);
			}
			title.pop_back();
			fin >> year;

			tempMoviePtr = factory.createMovie(genre, director, title, year);
			MovieInventory tempMovieInventory(tempMoviePtr);
			tempMovieInventory.setQuantity(quantity - 1);
			movieList.addMovie(tempMovieInventory);
		}

		else {
			string line;
			cout << "Non-valid Command!" << endl;
			getline(fin, line);
		}
	}
	
	cout << endl << endl << endl;
//	printInventory(movieList);
}

void Store::populateCustomer(string customerInfo)
{
	fstream infile(customerInfo);

	if (infile.fail())
	{
		cout << "No file found" << endl;
	}
	else
	{
		int Id;
		string lastName;
		string firstName;

		ifstream fin;
		fin.open(customerInfo);

		while (!fin.eof()) {
			fin >> Id;
			cout << Id << " " << endl;
			fin >> lastName;
			fin >> firstName;
			Customer * temp = new Customer(Id, firstName, lastName);
			overallCustomerList.addCustomer(temp);
		}
	}

}

void Store::populateCommandsFile(string fileName)
{	
	string p;
	fstream infile(fileName);

	while (getline(infile, p))
	{
		char command;
		int customerId;
		char mediaType;
		char movieType;
		stringstream firstline(p);
		firstline >> command;

		if (command == 'I' || command == 'R' || command == 'B' || command == 'H')
		{
			if (command == 'I')
			{
				printInventory(movieList);
			}

			if (command == 'H')
			{
				firstline >> customerId;
				if (overallCustomerList.getCustomer(customerId) != nullptr) {
					overallCustomerList.getCustomer(customerId)->printHistory();
				}
			}

		


		}
	}
}



void Store::commandHandler(char command)
{

}

void Store::printCustomerHistory(Customer * customer)
{
	customer->printHistory();
}

void Store::printInventory(MovieList &movieList)
{
	movieList.printByGenre('F');
	cout << endl;
	movieList.printByGenre('D');
	cout << endl;
	movieList.printByGenre('C');
	cout << endl;
}

void Store::borrowMovie(Customer * customer, MovieList * movieList, MovieInventory movieInventory)
{
	movieList->checkOut(movieInventory);
	customer->addHistory("B " + movieInventory.getMovie()->getMovieTitle());
}

void Store::returnMovie(Customer * customer, MovieList * movieList, MovieInventory movieInventory)
{
	movieList->checkIn(movieInventory);
	customer->addHistory("R " + movieInventory.getMovie()->getMovieTitle());
}

