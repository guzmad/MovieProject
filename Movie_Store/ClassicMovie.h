#pragma once

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE
#include "movie.h"
#include <vector>

class ClassicMovie : public Movie
{
public:
	ClassicMovie(char genre, string directorName, string movieTitle, string majorActor, int releaseMonth, int releaseYear);
	~ClassicMovie();

	virtual bool operator==(const Movie& rhs);
	virtual bool operator<(const Movie& rhs);
	virtual bool operator>(const Movie& rhs);
	virtual bool isSame(const Movie& rhs);
	virtual int getReleaseMonth() const;
	virtual void print(); // print out movie data and return string
	virtual string getMajorActor() const; // get the major actor for the movie
	virtual bool findMajorActor(string actor) const;

private:
	vector<string>majorActor;
	int releaseMonth;
};

#endif // !CLASSIC_MOVIE