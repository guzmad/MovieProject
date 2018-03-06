#include "stdafx.h"
#include "Store.h"
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

			char putBack = majorActor[majorActor.length() - 1];
			fin.putback(putBack);

			majorActor.pop_back();
			majorActor.pop_back(); //gets rid of white space

			fin >> month;
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
	printInventory(movieList);
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
		string s; // This string contains the first line in the file

		if (infile.good())  // it reads the first line of the file containing the 
		{
			getline(infile, s);
		}

		int customerId;
		string lastName;
		string firstName;

		stringstream firstline(s);
		firstline >> customerId>>lastName>>firstName;
		
		cout << customerId <<" "<<lastName<<" " <<firstName<< endl;


		//string p;



		//while (getline(infile, p))
		//{
		//	insertMazeValues(p, height, width, maze);
		//}


		//if (!found)
		//{
		//	cout << "No exit - Sartre was right" << endl;
		//}
		//else
		//{
		//	cout << endl;

		//	printMaze(maze);

		//	for (int i = moves.size() - 1; i >= 0; i--) {
		//	cout << moves[i];
		//	}
		//}

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

