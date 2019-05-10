#include "Watchlist.h"



Watchlist::Watchlist()
{
	this->list = vector<Movie>{};
}

int Watchlist::getPosByTitleYear(string & title, int year)
{
	for (int i = 0; i < this->list.size(); i++)
		if (this->list[i].getTitle() == title && this->list[i].getYear() == year)
			return i;
	return -1;
}

bool Watchlist::addWatch(Movie & m)
{
	string s = m.getTitle();
	int i = this->getPosByTitleYear(s, m.getYear());
	if (i != -1)
		return false;
	this->list.push_back(m);
	return true;
}

bool Watchlist::deleteByTitleYear(string & title, int year)
{
	int i = this->getPosByTitleYear(title, year);
	if (i == -1)
		return false;
	this->list.erase(this->list.begin() + i);
	return true;
}


