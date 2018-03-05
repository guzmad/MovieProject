#pragma once

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE
#include "movie.h"

class ClassicMovie : public Movie
{
public:
	ClassicMovie(char genre, string directorName, string movieTitle, string majorActor, int releaseMonth, int releaseYear);
	~ClassicMovie();

	virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
	virtual bool operator>(const Movie& rhs) const;

	virtual int getReleaseMonth() const;
	virtual void display() const; // print out movie data and return string
	virtual string getMajorActor() const; // get the major actor for the movie	

private:
	string majorActor;
	int releaseMonth;
};

#endif // !CLASSIC_MOVIE