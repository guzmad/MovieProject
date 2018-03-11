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
	fin.open(fileName);

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
			cout << genre << " is not a valid genre" << endl;
			string line;
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
			fin >> lastName;
			fin >> firstName;
			Customer * temp = new Customer(Id, firstName, lastName);
			overallCustomerList.addCustomer(temp);
//			overallCustomerList.getCustomer(Id)->printHistory();
		}
	}

}

void Store::populateCommandsFile(string fileName)
{	
	string p;
	fstream infile(fileName);

	while (getline(infile, p))
	{
		Movie * tempMoviePtr;
		Customer * tempCustomer;
		MovieFactory factory;
		MovieInventory tempMovieInventory;
		string tempStr;
		char command;
		int customerId;
		char mediaType;
		char movieType;
		string title;
		string director;
		string actor;
		int year;
		int month;
		stringstream firstline(p);
		firstline >> command;

		if (command == 'I' || command == 'R' || command == 'B' || command == 'H')
		{
			if (command == 'I')
			{
				printInventory(movieList);
			}

			else if (command == 'H')
			{
				firstline >> customerId;
				firstline >> mediaType;
				firstline >> movieType;

				if (overallCustomerList.getCustomer(customerId) != nullptr && mediaType == 'D') {
					overallCustomerList.getCustomer(customerId)->printHistory();
				}
			}

			else if (command == 'B') {
				firstline >> customerId;
				firstline >> mediaType;
				firstline >> movieType;

				if (mediaType != 'D') {
					cout << mediaType << " is not a valid genre" << endl;
				}

				else if (movieType == 'F') {
					firstline >> title;
					while (title[title.length() - 1] != ',') {
						firstline >> tempStr;
						title += (" " + tempStr);
					}
					title.pop_back();
					firstline >> year;

					tempMoviePtr = factory.createMovie(movieType, "", title, year);
					Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
					MovieInventory tempMovieInventory(tempMoviePtr);
					if (overallCustomerList.getCustomer(customerId) != nullptr) {
						borrowMovie(tempCustomer, tempMoviePtr);
					}
				}

				else if (movieType == 'D') {
					firstline >> director;
					while (director[director.length() - 1] != ',') {
						firstline >> tempStr;
						director += (" " + tempStr);
					}
					director.pop_back();
					
					firstline >> title;
					while (title[title.length() - 1] != ',') {
						firstline >> tempStr;
						title += (" " + tempStr);
					}
					title.pop_back();

					tempMoviePtr = factory.createMovie(movieType, director, title, 0);
					Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
					MovieInventory tempMovieInventory(tempMoviePtr);
					if (overallCustomerList.getCustomer(customerId) != nullptr) {
						borrowMovie(tempCustomer, tempMoviePtr);
					}
				}

				else if (movieType == 'C') {
					firstline >> month;
					firstline >> year;

					firstline >> actor;
					while (!firstline.eof()) {
						firstline >> tempStr;
						actor += (" " + tempStr);
					}

					tempMoviePtr = factory.createMovie(movieType, "", "", actor, month, year);
					Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
					MovieInventory tempMovieInventory(tempMoviePtr);
					if (overallCustomerList.getCustomer(customerId) != nullptr) {
						borrowMovie(tempCustomer, movieList.findMovieWithActor(tempMovieInventory));
					}
				}
			}

			else if (command == 'R') {
				firstline >> customerId;
				firstline >> mediaType;
				firstline >> movieType;

				if (mediaType != 'D') {
					cout << mediaType << " is not a valid genre" << endl;
				}

				else if (movieType == 'F') {
					firstline >> title;
					while (title[title.length() - 1] != ',') {
						firstline >> tempStr;
						title += (" " + tempStr);
					}
					title.pop_back();
					firstline >> year;

					tempMoviePtr = factory.createMovie(movieType, "", title, year);
					Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
					MovieInventory tempMovieInventory(tempMoviePtr);
					if (overallCustomerList.getCustomer(customerId) != nullptr) {
						returnMovie(tempCustomer, tempMoviePtr);
					}
				}

				else if (movieType == 'D') {
					firstline >> director;
					while (director[director.length() - 1] != ',') {
						firstline >> tempStr;
						director += (" " + tempStr);
					}
					director.pop_back();

					firstline >> title;
					while (title[title.length() - 1] != ',') {
						firstline >> tempStr;
						title += (" " + tempStr);
					}
					title.pop_back();

					tempMoviePtr = factory.createMovie(movieType, director, title, 0);
					Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
					MovieInventory tempMovieInventory(tempMoviePtr);
					if (overallCustomerList.getCustomer(customerId) != nullptr) {
						returnMovie(tempCustomer, tempMoviePtr);
					}
				}

				else if (movieType == 'C') {
					firstline >> month;
					firstline >> year;

					firstline >> actor;
					while (!firstline.eof()) {
						firstline >> tempStr;
						actor += (" " + tempStr);
					}

					tempMoviePtr = factory.createMovie(movieType, "", "", actor, month, year);
					Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
					MovieInventory tempMovieInventory(tempMoviePtr);
					if (overallCustomerList.getCustomer(customerId) != nullptr) {
						returnMovie(tempCustomer, movieList.findMovieWithActor(tempMovieInventory));
					}
				}
				
			}
		
		}
		else {
			cout << command << " is not a valid command" << endl;
		}
	}
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

void Store::borrowMovie(Customer * customer, MovieInventory movieInventory)
{
	movieList.checkOut(movieInventory);
	customer->addHistory("B | " + movieInventory.getMovie()->getMovieTitle());
}

void Store::returnMovie(Customer * customer, MovieInventory movieInventory)
{
	movieList.checkIn(movieInventory);
	customer->addHistory("R | " + movieInventory.getMovie()->getMovieTitle());
}

