#pragma once
#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"
#include <iostream>
#include <iomanip>

using namespace std;

class DramaMovie : public Movie
{
public:
	DramaMovie(char genre, string directorName, string movieTitle, int releaseYear);
	~DramaMovie();
	
	virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
	virtual bool operator>(const Movie& rhs) const;

	virtual void print();

private:

};
#endif // !DRAMAMOVIE_H
