#pragma once
#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H

#include "movie.h"
#include <iostream>
#include <iomanip>
using namespace std;

class ComedyMovie : public Movie
{
public:
	ComedyMovie(char genre, string directorName, string movieTitle, int releaseYear);
	~ComedyMovie();

	virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
	virtual bool operator>(const Movie& rhs) const;

	virtual void print();

};

#endif // !COMEDY_MOVIE_H