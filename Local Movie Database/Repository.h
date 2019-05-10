#pragma once
#include"Movie.h"
#include <vector>
class Repository {
private:
	vector<Movie> movies;
public:
	Repository(){}


	/*
	The function inserts an object of type Movie in the DynamicVector
	IN: an object of the type Movie
	OUT: true - if the element was successfully added
		false - if the element already exists and it can't be added
	*/
	bool add(Movie& m);

	/*
	The functions removes a given object from the Dynamic Vector
	IN: the searched movie
	OUT: true - if the element was successfully deleted
		false  - if the element does not exist
	*/
	bool del(string& title, int yearm);

	/*
	The function updates an existing object if it exists in the Dynamic Vector
	IN: oldm - an object of class Movie that represents the movie that will be modified
		newm - an object of class Movie that contains the data that will be changed in the Dynamic Vector
	OUT: true - if the given movie was successfully updated
		false - if the movie does not exist
	*/
	bool update(string& title, int year, Movie& newm);
	bool exists(string& title, int year);

	int getPosition(string& title, int year);

	/*
	The function computes the lenght of the array
	IN: - 
	OUT: the lenght of the Dynamic Vector, obtained from getSize()
	*/
	int getLenght();


	/*
	The function retrieves all the elements from the Dynamic Vector
	IN: - 
	OUT: a class of the type Dynamic Vector, which contains all the movies
	*/
	vector<Movie> getAllMovies();

	/*
	*/
	vector<Movie> getMovieByGenre(string& genre);

	bool increaseByTitleYear(string& title, int year);
};