#pragma once
#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"

class DramaMovie : public Movie
{
public:
	DramaMovie(char genre, string directorName, string movieTitle, int releaseYear);
	~DramaMovie();
	
	virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
	virtual bool operator>(const Movie& rhs) const;



private:

};
#endif // !DRAMAMOVIE_H
