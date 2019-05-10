#pragma once
#include "Controller.h"
#include <iostream>
#include "Validation.h"
#include "Watchlist.h"
using namespace std;

class UI {
private:
	Controller& ctrl;
public:
	UI( Controller& c) : ctrl(c) {};

	void addUI();
	void deleteUI();
	void updateUI();
	void showUI();

	/*
	Prints the components of the current element
	IN: -
	OUT: prints each attribute
	*/
	static void showMovie(Movie m);
	static void playTrailer(Movie m);


	void startUI();

	static void printOptionsUser();
	
	static void printMenu0();

	static void printOptionMovie();

	void playWatchlist(vector<Movie>& dv);

	void seeMovies(vector<Movie>& dv);

	void deleteMovies();

};