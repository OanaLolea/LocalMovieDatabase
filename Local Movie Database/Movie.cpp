#include "Movie.h"
using namespace std;

Movie::Movie() : title(""), genre(""), year(0), likes(0), trailer(""){}

Movie::Movie(const string& title, const string& genre, const int year, const int& likes, const string& trailer) {
	this->title = title;
	this->genre = genre;
	if (!validYear(year)) {
		//cout << "The year you introduced is incorrect! ";
		return;
	}
	this->year = year;
	if (!validLike(likes)) {
		//cout << "The number of likes cannot be negative!";
		return;
	}
	this->likes = likes;
	this->trailer = trailer;

}



bool Movie::operator==(const Movie m)
{
	if (this->title == m.title && this->year == m.year)
		return true;
	return false;
}

