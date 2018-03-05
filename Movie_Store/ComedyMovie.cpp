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