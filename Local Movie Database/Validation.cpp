#include "Validation.h"

bool validOption(int op) {
	if (op >= 0 && op <= 4)
		return true;
	return false;
}

bool validYear(int y)
{
	return (y>1930 && y<2021);
}

bool validLike(int l)
{
	return (l>=0);
}

bool validMode(int m)
{
	if (m == 1 || m == 2 || m == 0)
		return true;
	return false;
}
/*
bool validGenre(string & genre, DynamicVector<Movie>& v)
{
	for (int i = 0; i < v.getSize(); i++)
		if (v[i].getGenre() == genre)
			return true;
	return false;
}*/
