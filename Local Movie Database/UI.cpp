#include "UI.h"
#include "Watchlist.h"
#include <iostream>
using namespace std;

void UI::addUI()
{
	string title, genre, link;
	cout << "Give the title: "; getline(cin, title);
	cout << "Give the genre: "; getline(cin, genre);
	int year, likes;
	cout << "Give the year of publication: "; cin >> year; cin.ignore();
	while (!validYear(year)) {
		cout << "Wrong year! \n";
		cout << "Give the year: "; cin >> year; cin.ignore();
	}
	cout << "Give the number of likes: "; cin >> likes; cin.ignore();
	while (!validLike(likes)) {
		cout << "Wrong likes! \n";
		cout << "Give the likes: "; cin >> likes; cin.ignore();
	}
	cout << "Give the trailer link: "; cin >> link; cin.ignore();
	if (!this->ctrl.addMovieToRepo(title, genre, year, likes, link))
		cout << "The movie already exists!";
	else
		cout << "The insertion was successful!";

	cout << endl << endl;
}

void UI::deleteUI()
{
	if (this->ctrl.getLenghtOfRepo() == 0)
		cout << "There are no movies!\n";
	else {
		string title;
		cout << "Give the title: "; getline(cin, title);
		int year;
		cout << "Give the year of publication: "; cin >> year; cin.ignore();
		while (!validYear(year)) {
			cout << "Wrong year! \n";
			cout << "Give the year: "; cin >> year; cin.ignore();
		}
		if (!this->ctrl.deleteMovieFromRepo(title, year))
			cout << "There is no item to delete!\n";
		else
			cout << "The removal was successful!\n";
		cout << endl;
	}
}

void UI::updateUI()
{
	string otitle;
	cout << "Give the old title: "; cin >> otitle;
	int oyear;
	cout << "Give the old year of publication: "; cin >> oyear; cin.ignore();
	while (!validYear(oyear)) {
		cout << "Wrong old year! \n";
		cout << "Give the old year: "; cin >> oyear; cin.ignore();
	}

	string title, genre, link;
	cout << "Give the new title: "; getline(cin, title);
	cout << "Give the new genre: "; getline(cin, genre);
	int year, likes;
	cout << "Give the new year of publication: "; cin >> year; cin.ignore();
	while (!validYear(year)) {
		cout << "Wrong year! \n";
		cout << "Give the year: "; cin >> year; cin.ignore();
	}
	cout << "Give the new number of likes: "; cin >> likes; cin.ignore();
	while (!validLike(likes)) {
		cout << "Wrong likes! \n";
		cout << "Give the likes: "; cin >> likes; cin.ignore();
	}
	cout << "Give the new trailer link: "; cin >> link; cin.ignore();
	if (!this->ctrl.updateMovieFromRepo(otitle, oyear, title, genre, year, likes, link))
		cout << "The update failed!\n";
	else
		cout << "The update was successful!\n";
	cout << endl;
}

void UI::showUI()
{
	cout << "The movies are: \n";
	for (int i = 0; i < this->ctrl.getLenghtOfRepo(); i++)
		showMovie(this->ctrl.getRepo().getAllMovies()[i]);
	cout << endl << endl;
}

void UI::showMovie(Movie m)
{
	cout << "\t";
	cout << m.getTitle() << " of genre " << m.getGenre() << ", from the year " << m.getYear() << " and has " << m.getLikes() << " likes." << endl;
}

void UI::playTrailer(Movie m)
{
	ShellExecuteA(NULL, NULL, "chrome.exe", m.getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}



void UI::startUI() {
	int mode;
	cout << "Choose option 1) for administrator mode and 2) for user mode.\n";
	cout << "Give the mode: "; cin >> mode; cin.ignore();
	while (!validMode(mode))
	{
		cout << "Wrong mode! Pick only 1 or 2! \n";
		cout << "Give the mode: "; cin >> mode; cin.ignore();
	}
	cout << endl;
	if (mode == 0)
		return;
	if (mode == 1 && mode!=0) {
		int op;
		while (true) {
			printMenu0();
			cout << "Give the option: "; cin >> op; cin.ignore();
			if (op == 0) {
				this->startUI();
				break;
			}
			while (!validOption(op)) {
				cout << "Wrong option! \n";
				cout << "Give the option: "; cin >> op; cin.ignore();
			}
			switch (op) {
			case 1: {
				this->addUI();
				break;
			}

			case 3: {
				this->updateUI();
				break;
			}
			case 2: {
				this->deleteUI();
				break;
			}
			case 4: {
				this->showUI();
				break;
			}
			case 0:
				break;
			}
		}
	}
	else
		if (mode == 2 && mode !=0) {
			string genre;
			cout << "Give the genre: "; getline(cin, genre);
			vector<Movie> d{};
			d = this->ctrl.getMoviesByGenreFromRepo(genre);
			this->playWatchlist(d);
		}
		else
			cout << "Bye!\n\n";

	

}

void UI::printOptionsUser()
{
	cout << "Your options: \n\t";
	cout << "1. Add movie to the watchlist. \n\t";
	cout << "2. Give a like \n\t";
}


void UI::printMenu0(){
	cout << "Here are your options: \n\t 1. Add a movie. \n\t 2. Delete a movie\n\t 3. Update a movie\n\t 4. Show all the movies\n\t 0. Exit\n";
	cout << endl;

}

void UI::printOptionMovie()
{
	cout << "\n1. See the movies to add them to the watchlist.\n2. Delete a movie from the watchlist. \n3. See the watchlist\n0. Back\n";
}



void UI::playWatchlist(vector<Movie>& dv)
{
	int i=0, op;
	while (true) {
		printOptionMovie();
		cout << "Give the option: "; cin >> op; cin.ignore();
		if (op == 0) {
			this->startUI();
			break;
		}
		switch (op) {
		case 1: {
			this->seeMovies(dv);
			break;
		}
		case 2: {
			this->deleteMovies();
			break;
		}
		case 3: {
			if (this->ctrl.lenghtWatch() == 0)
				cout << "The watchlist is empty!\n";
			else 
				for (i = 0; i < this->ctrl.lenghtWatch(); i++)
					showMovie(this->ctrl.getWatchlist().getList()[i]);
			break;
		}
		}
		
	}
}

void UI::seeMovies(vector<Movie>& dv)
{
	int i = 0;
	string s, t;
	while (true) {
		cout << "The current element is: \n";	showMovie(dv[i]);
		//playTrailer(dv[i]);
		cout << "Do you want to add this movie to your watchlist? (Y/N) ";
		getline(cin, s);
		if (s == "Y" or s == "y") {
			t = dv[i].getTitle();
			this->ctrl.addToWatchlist(t, dv[i].getYear());
		}
		if (i == dv.size() - 1) {
			cout << "Want to see the movies again? (Y/N) ";
			getline(cin, s);
			//validation of s 
			if (s == "Y" or s == "y")
				i = 0;
			else
				break;
		}
		else
			i++;
		cout << endl;

	}
}

void UI::deleteMovies()
{
	string title, s;
	if (this->ctrl.getWatchlist().lenght() == 0)
		cout << "The watchlist is empty!\n";
	else {
		cout << "Give the title: "; getline(cin, title);
		int year;
		cout << "Give the year of publication: "; cin >> year; cin.ignore();
		while (!validYear(year)) {
			cout << "Wrong year! \n";
			cout << "Give the year: "; cin >> year; cin.ignore();
		}
		int i = this->ctrl.getWatchlist().getPosByTitleYear(title, year), k;
		if (i == -1)
			cout << "The movie does not exist!\n";
		else {
			cout << "Did you enjoyed the movie? (Y/N) "; getline(cin, s);
			//validation of s 
			if (s == "Y" or s == "y") {
				if (!this->ctrl.increaseLikes(title, year))
					cout << "The movie does not exist in the database!\n";

			}
			if (!this->ctrl.getWatchlist().deleteByTitleYear(title, year))
				cout << "The movie does not exist in the database!\n";
		}
	}
}
