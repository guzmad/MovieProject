#pragma once
#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H

#include "movie.h"

class ComedyMovie : public Movie
{
public:
	ComedyMovie(char genre, string directorName, string movieTitle, int releaseYear);
	~ComedyMovie();

	virtual bool operator==(const Movie& rhs);
	virtual bool operator<(const Movie& rhs);
	virtual bool operator>(const Movie& rhs);

	virtual void ComedyMovie::print() = 0;
};

#endif // !COMEDY_MOVIE_H