#include "stdafx.h"
#include "MovieList.h"
#include <iostream>

using namespace std;

MovieList::MovieList()
{
	movieList.assign(3, vector<MovieInventory>(0));
}

MovieList::~MovieList()
{
}

bool MovieList::addMovie(MovieInventory movieInventory) 
{
	char genre;
	int element;
	int left;
	int right;

	genre = movieInventory.getMovie()->getGenre();

	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
		return false;
	}
	
	if (movieList[element].empty()) {
		movieList[element].push_back(movieInventory);
		return true;
	}

	for (int i = 0; i < movieList[element].size(); i++) {
		if (movieList[element][i].getMovie() == (movieInventory.getMovie())) {
			changeQuantity(movieList[element][i], movieInventory.getQuantity());
			return false;
		}
	}

	movieList[element].push_back(movieInventory);

	left = 0;
	right = movieList[element].size() - 1;

	quickSort(movieList, left, right, element);

	return true;
}

bool MovieList::incrementMovie(MovieInventory &movieInventory)
{
	movieInventory.incrementQuantity();
	return true;
}

bool MovieList::decrementMovie(MovieInventory &movieInventory)
{
	movieInventory.decrementQuantity();
	return true;
}

bool MovieList::changeQuantity(MovieInventory & movieInventory, int val)
{
	movieInventory.setQuantity(val);
	return true;
}

void MovieList::printByGenre(const char x)
{
	char genre = x;
	int element;

	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
	}


	for (int i = 0; i < movieList[element].size(); i++) {
		
		movieList[element][i].getMovie()->print();
		cout << "  " << movieList[element][i].getMediaType() << "  " << movieList[element][i].getQuantity() << endl;
	}


}

int MovieList::getWall(vector<vector<MovieInventory>>& movieList, int left, int right, int element)
{
	MovieInventory temp;
	MovieInventory pivot = movieList[element][right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++) {
		if (movieList[element][j].getMovie() < pivot.getMovie()) {  // this is where the problem is 
			i++;
			temp = movieList[element][j];
			movieList[element][j] = movieList[element][i];
			movieList[element][i] = temp;
		}
	}

	temp = movieList[element][right];
	movieList[element][right] = movieList[element][i + 1];
	movieList[element][i + 1] = temp;

	return (i + 1);
}

void MovieList::quickSort(vector<vector<MovieInventory>>& movieList, int left, int right, int element)
{
	if (left < right) {
		int wall = getWall(movieList, left, right, element);

		quickSort(movieList, left, wall - 1, element);
		quickSort(movieList, wall + 1, right, element);
	}

}

bool MovieList::checkOut(MovieInventory &MovieInventory)
{
	char genre = MovieInventory.getMovie()->getGenre();
	int element;

	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
		return false;
	}

	for (int i = 0; i < movieList[element].size(); i++) {
		if (movieList[element][i].getMovie()==MovieInventory.getMovie()) {
			decrementMovie(movieList[element][i]);
			return true;
		}
	}
	cout << "Movie Not in Stock!" << endl;
	return false;
}

bool MovieList::checkIn(MovieInventory &MovieInventory)
{
	char genre = MovieInventory.getMovie()->getGenre();
	int element;

	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
		return false;
	}

	for (int i = 0; i < movieList[element].size(); i++) {
		if (movieList[element][i].getMovie() == MovieInventory.getMovie()) {
			incrementMovie(movieList[element][i]);
			return true;
		}
	}
	cout << "Movie Not in Stock!" << endl;
	return false;
}




