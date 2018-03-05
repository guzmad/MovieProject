#include "stdafx.h"
#include "MovieFactory.h"
#include "movie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"


MovieFactory::MovieFactory()
{
}

Movie * MovieFactory::createMovie(char genre, string directorName, string movieTitle, string majorActor, int releaseMonth, int releaseYear)
{
	Movie * newMovie = NULL;

		newMovie = new ClassicMovie(genre, directorName, movieTitle, majorActor, releaseMonth, releaseYear);
		return newMovie;
	
}

Movie * MovieFactory::createMovie(char genre, string directorName, string movieTitle, int releaseYear)
{
	Movie * newMovie = NULL;

	if (genre == 'F') {
		newMovie = new ComedyMovie(genre, directorName, movieTitle, releaseYear);
		return newMovie;
	}

	else if (genre == 'D') {
		newMovie = new DramaMovie(genre, directorName, movieTitle, releaseYear);
		return newMovie;
	}
}


MovieFactory::~MovieFactory()
{
}
