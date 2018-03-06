#include "stdafx.h"
#include "Movie.h"

#include <iostream>
#include <iomanip>

Movie::Movie(char genre, string directorName, string movieTitle, int releaseYear)
{
	this->movieTitle = movieTitle;
	this-> directorName = directorName;
	this->releaseYear = releaseYear;
	this->genre = genre;
}

string Movie::getMovieTitle() const
{
	return movieTitle;
}

string Movie::getDirectorName() const
{
	return directorName;
}

int Movie::getReleaseYear() const
{
	return releaseYear;
}

char Movie::getGenre() const
{
	return genre;
}

string Movie::getMajorActor() const
{
	return "";
}

int Movie::getReleaseMonth() const
{
	return 0;
}

void Movie::print() const
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
		<< setw(20) << getDirectorName() << setw(7) << getReleaseYear();
}

bool Movie::operator==(Movie * rhs)
{
	return this->movieTitle == rhs->movieTitle && this->releaseYear == rhs->releaseYear;
}

bool Movie::operator<(Movie * rhs) 
{
	/*return this->releaseYear < rhs->releaseYear;*/
}

bool Movie::operator>(Movie * rhs)
{
	return this->releaseYear > rhs->releaseYear;
}

Movie::~Movie()
{
}
