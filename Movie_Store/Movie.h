#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie
{
public:
	Movie(char genre, string directorName, string movieTitle, int releaseYear);
	~Movie();

	// overloaded operators
	virtual bool operator==(const Movie & rhs) = 0;
	virtual bool operator<(const Movie& rhs) = 0;
	virtual bool operator>(const Movie& rhs) = 0;
	
	// Accessors
	string getMovieTitle() const;
	string getDirectorName() const;
	int getReleaseYear() const;
	char getGenre() const;

	virtual int getReleaseMonth() const;
	virtual string getMajorActor() const;


	// print function
	virtual void print() const;

protected:
	string movieTitle;
	string directorName;
	int releaseYear;
	char genre;
};

#endif