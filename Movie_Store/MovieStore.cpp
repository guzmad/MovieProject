// MovieStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "MovieFactory.h"
#include "MovieInventory.h"
#include "MovieList.h"
#include "customer.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{

	ClassicMovie test('c', "nora Ephron", "auck you Diego", "aam", 9, 1999);
	ClassicMovie test2('c', "nora Ephron", "auck you Diego", "aam", 9, 1999);

	
	MovieFactory a;
	Movie * temp = a.createMovie('F', "Nora Ephron", "Zou've Got Mail", 1998);
	MovieInventory test5(temp);

	MovieFactory * ptr = &a;


	temp = a.createMovie('F', "Nora Ephron", "You've Got Mail", 1998);
	MovieInventory test7(temp);

	temp = a.createMovie('F', "Nora Ephron", "You've Got Mail", 1998);
	MovieInventory newtest(temp);

	temp = a.createMovie('C', "George Cukor", "Holiday", "Katherine Hepburn", 9, 1998);
	MovieInventory test8(temp);

	temp = a.createMovie('C', "George Cukor", "Holiday", "Cary Grant", 9, 1998);
	MovieInventory test9(temp);

	temp = a.createMovie('C', "George Cukor", "Holiday", "Cary Grant", 9, 1998);
	MovieInventory test16(temp);

	temp = a.createMovie('C', "George", "Ho", "cary Grant", 9, 1998);
	MovieInventory test11(temp);

	temp = a.createMovie('D', "Steve", "Schindler's", 1993);
	MovieInventory test10(temp);

	temp = a.createMovie('D', "Steven Spielberg", "Schindler's List", 1993);
	MovieInventory test6(temp);


	MovieList q;
	q.addMovie(test5);
	q.addMovie(test6);
	q.addMovie(test7);
	q.addMovie(test8);
	q.addMovie(test9);
	q.addMovie(test16);
	q.addMovie(test10);
	q.addMovie(test11);
	q.addMovie(newtest);

	q.printByGenre('F');
	cout << endl;
	q.printByGenre('D');
	cout << endl;
	q.printByGenre('C');
	cout << endl;


	Customer nathan(123, "Nathan", "Fixx");
	q.checkOut(test7);
	q.checkOut(test5);

	q.checkIn(test9);
	q.checkIn(test9);
	q.checkIn(test9);
	q.checkIn(test9);
	q.checkIn(test9);
	q.checkIn(test9);
	q.checkIn(test9);
	q.checkIn(test9);

	
	q.printByGenre('F');

	cout << endl;

	q.printByGenre('C');

	system("pause");
    return 0;
}

