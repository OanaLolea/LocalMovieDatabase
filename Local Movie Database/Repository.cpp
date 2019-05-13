#include "Repository.h"
using namespace std;

bool  Repository::add(Movie& m){
	string s = m.getTitle();
	if(this->exists(s, m.getYear()))
		return false;
	this->movies.push_back(m);
	return true;
}

bool Repository::exists(string& title, int year) {
	for (auto m : this->movies)
		if (m.getTitle() == title && m.getYear() == year)
			return true;
	return false;
}

int Repository::getPosition(string & title, int year)
{
	for (int i = 0; i < this->movies.size(); i++)
		if (this->movies[i].getTitle() == title && this->movies[i].getYear() == year)
			return i;
	return -1;
}

int Repository::getLenght()
{
	return this->movies.size();
}

vector<Movie> Repository::getAllMovies() 
{
	return this->movies;
}

// as inlocui aici cu copy_if (cerinta lab 8)
vector<Movie> Repository::getMovieByGenre(string & genre)
{
	vector<Movie> v{};
	if (genre == "")
		return this->movies;
	for (auto m : this->movies)
		if (m.getGenre() == genre)
			v.push_back(m);
	return v;
}

bool Repository::increaseByTitleYear(string & title, int year)
{
	if(!this->exists(title, year))
		return false;
	int i = this->getPosition(title, year);
	int l = this->movies[i].getLikes();
	this->movies[i].setLikes(l + 1);
	return true;
}

bool Repository::del(string& title, int year) {
	if (!this->exists(title, year))
		return false;
	int i = this->getPosition(title, year);
	this->movies.erase(this->movies.begin() + i);
	return true;
}

bool Repository::update(string& title, int year, Movie & newm)
{
	if (!this->exists(title, year))
		return false;
	int i = this->getPosition(title, year);
	this->movies[i] = newm;
	return true;
}
