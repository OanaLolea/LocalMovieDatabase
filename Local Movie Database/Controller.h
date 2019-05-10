#pragma once
#include "Repository.h"
#include "Watchlist.h"
#include <iostream>

using namespace std;

class Controller
{
private:
	Repository& repo;
	Watchlist& w;

public:
	Controller(Repository& repo, Watchlist& w): repo(repo), w(w) {}


	/*
	The function returns by reference the repository
	IN: - 
	OUT: repo - of class Repository
	*/
	Repository& getRepo() { return this->repo; }

	/*
	The function returns by reference the watchlist
	IN: -
	OUT: repo - of class Watchlist
	*/
	Watchlist& getWatchlist() { return this->w; }
	

	/*
	The function creates an object of the type Movie and adds it to the repository
	IN: title - string
		genre - string
		year - integer between 1950 and 2021
		likes - positive integer
		trailer - string
	OUT: true - if the given movie doesn't already exists and it was added successfully
		false - otherwise
	*/
	bool addMovieToRepo( string& title,  string& genre,  int year,  int likes,  string& trailer);


	/*
	The function searches for a movie that has the given title and year and deletes it
	IN: title - string
		year - integer between 1950 and 2021
	OUT: true - if the given movie exists and it was deleted successfully
		false - if the movie doesn't exist
	*/
	bool deleteMovieFromRepo( string& title,  int year);
	

	/*
	The function creates an object of the type Movie and searches the movie that has the title otitle and year oyear to be updated
	IN: otitle - string
		oyear - integer
		title - string
		genre - string
		year - integer between 1950 and 2021
		likes - positive integer
		trailer - string
	OUT: true - if the given movie updated successfully
		false - if the movie doesn't exist and can't be updated
	*/
	bool updateMovieFromRepo( string& otitle,  int oyear,  string& title,  string& genre,  int year,  int likes,  string& trailer);


	/*
	The function returns the lenght of the repository
	IN: - 
	OUT: int - the number of movies
	*/
	int getLenghtOfRepo();


	/*
	The functions returns the position of the movied identified by the given year and title
	IN: title - string
		year - integer between 1950 and 2021
	OUT: int - the position of the movie in the repository, starting from 0
	*/
	int getPosition(string& title, int year);


	/*
	The function filters the repository by the genre of the elements
	IN: genre - string
	OUT: DYnamicVector<Movie> - a list of filtered elements
	*/
	vector<Movie> getMoviesByGenreFromRepo(string& genre);

	/*
	The functions adds to the watchlist the movie from the repo defined by the given title and year
	IN: title - string
		year - integer between 1950 and 2021
	OUT: true - if the given movie doesn't already exist and it was added successfully
		false - if the movie already exists
	*/
	bool addToWatchlist(string& title, int year);

	/*
	The functions deletes from the watchlist the movie from the repo defined by the given title and year
	IN: title - string
		year - integer between 1950 and 2021
	OUT: true - if the given movie exists and it was deleted successfully
		false - if the movie doesn't exist	*/
	bool deleteByTitleYearCtrl(string& title, int year);


	/*
	The function determine the lenght of the Watchlist
	IN: - 
	OUT: int - the no. of elements of the Watchilist
	*/
	int lenghtWatch();

	/*
	THe function increases by one the number of likes of the movie having the given title and year
	IN: title - string
		year - integer between 1950 and 2021
	OUT: true - if the movie doens't exist in the repository
		false - otherwise
	*/
	bool increaseLikes(string& title, int year);
};