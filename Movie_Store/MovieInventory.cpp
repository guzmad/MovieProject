#include "stdafx.h"
#include "MovieInventory.h"
#include <iostream>

using namespace std;


MovieInventory::MovieInventory()
{
}

MovieInventory::MovieInventory(Movie * movieptr)
{
	this->movie = movieptr;
	mediaType = "DVD";
	quantity = 1;
}


MovieInventory::~MovieInventory()
{
}

int MovieInventory::getQuantity()
{
	return quantity;
}

void MovieInventory::incrementQuantity()
{
	quantity++;
}

void MovieInventory::decrementQuantity()
{
	if (quantity > 0) {
		quantity--;
	}
	else {
		cout << "OUT OF STOCK" << endl;
	}
}

void MovieInventory::setQuantity(int val)
{
	quantity += val;
}

Movie * MovieInventory::getMovie()
{
	return movie;
}

string MovieInventory::getMediaType()
{
	return mediaType;
}
