#include "Controller.h"

bool Controller::addMovieToRepo( string & title,  string & genre,  int year,  int likes,  string & trailer)
{
	Movie m = Movie(title, genre, year, likes, trailer);
	return this->repo.add(m);
}

bool Controller::deleteMovieFromRepo( string & title,  int year)
{
	return this->repo.del( title,  year);
}

bool Controller::updateMovieFromRepo( string & otitle, int oyear, string & title, string & genre,  int year,  int likes,  string & trailer)
{
	Movie m = Movie(title, genre, year, likes, trailer);
	return this->repo.update( otitle,  oyear, m);
}

int Controller::getLenghtOfRepo()
{
	return this->repo.getLenght();
}

int Controller::getPosition(string & title, int year)
{
	return this->repo.getPosition(title, year);
}

vector<Movie> Controller::getMoviesByGenreFromRepo(string & genre)
{
	return this->repo.getMovieByGenre(genre);
}

bool Controller::addToWatchlist(string & title, int year)
{
	int i = this->getPosition(title, year);
	return this->w.addWatch(this->repo.getAllMovies()[i]);
}

bool Controller::deleteByTitleYearCtrl(string & title, int year)
{
	 return this->w.deleteByTitleYear(title, year);
}

int Controller::lenghtWatch()
{
	return this->w.lenght();
}

bool Controller::increaseLikes(string & title, int year)
{
	return this->getRepo().increaseByTitleYear(title, year);
}
