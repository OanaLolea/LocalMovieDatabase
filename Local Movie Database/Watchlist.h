#pragma once
#include<vector>
#include "Movie.h"
#include <string>

using namespace std;

class Watchlist
{
private:
	vector<Movie> list;
public:
	Watchlist();

	/*
	THe function returns the position of the given movie
	IN: title - string
		year - integer between 1950 and 2021
	OUT:the position of the movie in the array
	*/
	int getPosByTitleYear(string& title, int year);

	/*
	The function adds the given movie to the watchlist
	IN: m - Movie 
	OUT: true - if the movie didn't exist and was added successfully
		false - otherwise
	*/
	bool addWatch(Movie& m);

	/*
	THe function returns the size of the list 
	IN: - 
	OUT: the lenght of the Dynamic Array
	*/
	int lenght() { return this->list.size(); }

	/*
	The function returns the vector of movies
	IN: -
	OUT: DynamicVector<Movie> - the list of elements
	*/
	vector<Movie>& getList() { return this->list; }

	/*
	The functions deletes from the watchlist the movie defined by the given title and year
	IN: title - string
		year - integer between 1950 and 2021
	OUT: true - if the given movie exists and it was deleted successfully
		false - if the movie doesn't exist	*/
	bool deleteByTitleYear(string& title, int year);
};

