#include "stdafx.h"
#include "ComedyMovie.h"


ComedyMovie::ComedyMovie(char genre, string directorName, string movieTitle, int releaseYear):
Movie(genre, directorName, movieTitle, releaseYear)
{
}


ComedyMovie::~ComedyMovie()
{
}

bool ComedyMovie::operator<(const Movie & rhs) const
{
	if (this->movieTitle < rhs.getMovieTitle())
	{
		return true;
	}
	else if (movieTitle == rhs.getMovieTitle() && releaseYear < rhs.getReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ComedyMovie::operator>(const Movie & rhs) const
{
	if (movieTitle > rhs.getMovieTitle())
	{
		return true;
	}
	else if (movieTitle == rhs.getMovieTitle() && releaseYear > rhs.getReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ComedyMovie::operator==(const Movie &rhs) const
{
	if (movieTitle == rhs.getMovieTitle() && releaseYear == rhs.getReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ComedyMovie::print()
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
		<< setw(20) << getDirectorName() << setw(7) << getReleaseYear();
}