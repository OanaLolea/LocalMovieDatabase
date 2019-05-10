#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;
class Movie {
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;

public:
	Movie();
	Movie(const string& title, const string& genre, const int year, const int& likes, const string& trailer);

	/*
	The get functions return each attribute of the class
	IN: -
	OUT: the values of the class
	*/
	string getTitle()  { return this->title; }
	string getGenre()  { return this->genre; }
	string getTrailer()  { return this->trailer; }
	int getYear()  { return this->year; }
	int getLikes()  { return this->likes; }

	/*
	The set functions updates each attribute of the class
	IN: the new attribute
	OUT: - 
	*/
	void setTitle(string& t) { this->title = t; }
	void setGenre(string& g) { this->genre = g; }
	void setTrailer(string& t) { this->trailer = t; }
	void setYear(int y) { this->year = y; }
	void setLikes(int l) { this->likes = l; }

	/*
	The function overloads the comparison operator between two movies
	IN: variable of type Movie which the current element will be compared to
	OUT: 1 - if the current element and the parameter have the same title and release year
		 0 - otherwise
	*/
	bool operator == (const Movie m);

};