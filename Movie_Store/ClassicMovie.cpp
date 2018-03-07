#include "stdafx.h"
#include "ClassicMovie.h"
#include <iomanip>
#include <iostream>


ClassicMovie::ClassicMovie(char genre, string directorName, string movieTitle, string majorActor, int releaseMonth, int releaseYear) :
	Movie(genre, directorName, movieTitle, releaseYear)
{
	this->majorActor = majorActor;
	this->releaseMonth = releaseMonth;
}

ClassicMovie::~ClassicMovie()
{
}

int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}

void ClassicMovie::print()
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
		<< setw(20) << getDirectorName() << setw(20) << getMajorActor() << setw(7) << getReleaseMonth() << setw(7) << getReleaseYear();
}

string ClassicMovie::getMajorActor() const
{
	return majorActor;
}

bool ClassicMovie::operator==(const Movie & rhs)
{
	if (releaseMonth == rhs.getReleaseMonth() && releaseYear == rhs.getReleaseYear())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool ClassicMovie::operator<(const Movie & rhs)
{
	if (releaseYear < rhs.getReleaseYear())
	{
		return true;
	}
	else if (releaseYear == rhs.getReleaseYear() && releaseMonth == rhs.getReleaseMonth())
	{
		if (getMajorActor() < rhs.getMajorActor()) {
			return true;
		}

		else {
			return false;
		}
	}

	else if (releaseYear == rhs.getReleaseYear()) {
		if (releaseMonth < rhs.getReleaseMonth()) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

bool ClassicMovie::operator>(const Movie & rhs)
{
	if (releaseYear > rhs.getReleaseYear()) 
	{
		return true;
	}
	else if (releaseYear == rhs.getReleaseYear() && releaseMonth == rhs.getReleaseMonth()) 
	{
		if (getMajorActor() > rhs.getMajorActor()) {
			return true;
		}

		else {
			return false;
		}
	}

	else if (releaseYear == rhs.getReleaseYear()) {
		if (releaseMonth > rhs.getReleaseMonth()) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

