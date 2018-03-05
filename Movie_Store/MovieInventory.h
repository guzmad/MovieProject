#pragma once
#ifndef MOVIE_INVENTORY_H
#define MOVIE_INVENTORY_H
#include "Movie.h"



class MovieInventory
{
public:
	MovieInventory();
	MovieInventory(Movie * movieptr);
	~MovieInventory();

	int getQuantity();
	void incrementQuantity();
	void decrementQuantity();
	Movie * getMovie();
	string getMediaType();


private:
	Movie * movie;
	string mediaType;
	int quantity;

};
#endif // !MOVIE_INVENTORY_H
