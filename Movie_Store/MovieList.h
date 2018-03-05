#pragma once

#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "MovieInventory.h"
#include <vector>
using namespace std;

class MovieList
{
public:
	MovieList();
	~MovieList();

	bool addMovie(MovieInventory movieInventory);
	bool incrementMovie(MovieInventory &movieInventory); 
	bool decrementMovie(MovieInventory &movie);
	void printByGenre(const char x);
	int getWall(vector<vector<MovieInventory>> &movieList, int left, int right, int element);
	void quickSort(vector<vector<MovieInventory>> &movieList, int left, int right, int element);

private:
	
	vector<vector<MovieInventory>> movieList;
};

#endif // !MOVIELIST_H
