#pragma once

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
using namespace std;

class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();

	Movie * createMovie(char genre, string directorName, string movieTitle, string majorActor, int releaseMonth, int releaseYear);
	Movie * createMovie(char genre, string directorName, string movieTitle, int releaseYear);

};

#endif // !MOVIE_FACTORY_H

