#include "stdafx.h"
#include "DramaMovie.h"


DramaMovie::DramaMovie(char genre, string directorName, string movieTitle, int releaseYear):
Movie(genre, directorName, movieTitle, releaseYear)
{
}


DramaMovie::~DramaMovie()
{
}

bool DramaMovie::operator<(const Movie & rhs)
{
	if (directorName < rhs.getDirectorName()) 
	{ 
		return true;
	}
	else if (directorName == rhs.getDirectorName() && movieTitle < rhs.getMovieTitle()) 
	{
		return true;
	}
	else 
	{
		return false;
	}

	
}

bool DramaMovie::operator>(const Movie & rhs)
{
	if (directorName > rhs.getDirectorName()) 
	{
		return true;
	}
	else if(directorName == rhs.getDirectorName() && movieTitle > rhs.getMovieTitle())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DramaMovie::operator==(const Movie &rhs)
{
	if (directorName == rhs.getDirectorName() && movieTitle == rhs.getMovieTitle()) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
