#include "Tests.h"
#include<assert.h>
#include <iostream>
#include <string>
using namespace std;


void Test::test_create(){
	Movie m = Movie("Titanic", "Drama", 1992, 10000, "link1");
	assert(m.getTitle() == "Titanic");
	assert(m.getGenre() == "Drama");
	assert(m.getYear() ==  1992);
	assert(m.getLikes() == 10000);
	assert(m.getTrailer() == "link1");
	string s1 = "Saw";
	m.setTitle(s1);
	assert(m.getTitle() == "Saw");
	s1 = "Thriller";
	m.setGenre(s1);
	assert(m.getGenre() == s1);
	m.setYear(2001);
	assert(m.getYear() == 2001);
	m.setLikes(20000);
	assert(m.getLikes() == 20000);
	s1 = "link2";
	m.setTrailer(s1);
	assert(m.getTrailer() == "link2");
	Repository repo;
	Watchlist w{};
	assert(repo.getLenght() == 0);
	Controller ctrl{ repo, w };
	assert(ctrl.getLenghtOfRepo() == 0);
	Movie movie{ "title", "genre", 1000, -10, "link" };
	Movie m1{ "Saw", "Parody", 2001, 12, "link2" };
	assert(m == m1);
	assert(!(m == movie));
	Movie mm{ "title", "genre", -10, -10, "trailer" };
	Movie mm2{ "title", "genre", 2000, -10, "trailer" };
	//m1.playTrailer();
	//m1.showMovie();
}

void Test::test_add()
{
	Movie m1{"Titanic", "Drama", 1992, 10000, "link1"};
	Movie m2{ "Hellboy", "Action", 2019, 10000, "link2" };
	Movie m3{ };
	Repository repo = Repository();
	Watchlist w{};
	Controller ctrl{ repo , w};
	assert(repo.getLenght() == 0);
	assert(ctrl.getLenghtOfRepo() == 0);
	repo.add(m1);
	assert(repo.getLenght() == 1);
	assert(ctrl.getLenghtOfRepo() == 1);
	repo.add(m1);
	assert(ctrl.getLenghtOfRepo() == 1);
	assert(repo.getLenght() == 1);
	string s = "aaa";
	ctrl.addMovieToRepo(s, s, 2000, 10, s);
	assert(ctrl.getLenghtOfRepo() == 2);
	vector<Movie> dv;
	dv.push_back(m1);
	dv.push_back(m2);
	dv.push_back(m3);
	assert(dv.size() == 3);
}

void Test::test_delete()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	Watchlist w{};
	Controller ctrl{ repo, w };
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	string s = m2.getTitle();
	repo.del(s, m2.getYear());
	s = "Titanic";
	ctrl.deleteMovieFromRepo(s, 1992);
	assert(repo.getLenght() == 1);
	assert(ctrl.getLenghtOfRepo() == 1);

	repo.del(s, m2.getYear());
	ctrl.deleteMovieFromRepo(s, 1992);
	assert(repo.getLenght() == 1);
	assert(ctrl.getLenghtOfRepo() == 1);
}

void Test::test_update()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	Watchlist w{};
	Controller ctrl{ repo ,w};
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	Movie m = Movie("title1", "genre1", 2000, 100, "link");
	string s = m2.getTitle();
	repo.update(s, m2.getYear(), m);
	s = "Titanic";
	string s1 = "genre1", s2 = "link1", s3 ="title";
	ctrl.updateMovieFromRepo(s, 1992, s3, s1, 2000, 100, s2);
	assert(repo.getAllMovies()[1].getTitle() == "title1");
	assert(ctrl.getRepo().getAllMovies()[0].getTitle() == s3);

	repo.update(s, m2.getYear(), m);
	ctrl.updateMovieFromRepo(s, 1992, s3, s1, 2000, 100, s2);
	assert(repo.getAllMovies()[1].getTitle() == "title1");
	assert(ctrl.getRepo().getAllMovies()[1].getTitle() == "title1");
}

void Test::test_getAll()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	Watchlist w{};
	Controller ctrl{ repo, w };
	assert(repo.getAllMovies()[0].getTitle() == "Titanic");
	assert(repo.getAllMovies()[1].getTitle() == "Avengers");
	assert(repo.getAllMovies()[2].getTitle() == "Hellboy");
	string s = "";
	repo.getMovieByGenre(s);
}

void Test::test_increaseByTitleYear()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	Watchlist w{};
	Controller ctrl{ repo, w };
	string s1 = "Hellboy", s2 = "aaa";
	assert(repo.increaseByTitleYear(s1, 2019));
	assert(ctrl.increaseLikes(s1, 2019));
	assert(!repo.increaseByTitleYear(s2, 2019));
	assert(!ctrl.increaseLikes(s2, 2010));
}



void Test::test_getGenre()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	repo.add(m1);
	repo.add(m2);
	repo.add(m3); 
	Watchlist w{};
	Controller ctrl{ repo, w };
	string s = "Action";
	vector<Movie> m = ctrl.getMoviesByGenreFromRepo(s);
	//cout << m.size() << endl;
	assert(ctrl.getMoviesByGenreFromRepo(s).size() == 2);
}

void Test::test_getPosition()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	Watchlist w{};
	Controller ctrl{ repo, w };
	string s = "aaa";
	assert(repo.getPosition(s, 2019) == -1);
	s = "Hellboy";
	assert(repo.getPosition(s, 2019) == 2);
	s = "Hellboy";
	assert(ctrl.getPosition(s, 2019) == 2);
	s = "aaa";
	assert(ctrl.getPosition(s, 2019) == -1);
}

void Test::test_operations(){
	vector<Movie> dv{ 10 };
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	dv.push_back(m1);
	vector<Movie> newdv;
	newdv.push_back(m2);
	newdv.push_back(m3);
	assert(newdv.size() == 2);
}

void Test::test_validations()
{
	int x;
	x = 1;
	assert(validMode(x));
	assert(validOption(x));
	x = 100;
	assert(!validMode(x));
	assert(!validOption(x));
}

void Test::test_watchlist()
{
	Movie m1 = Movie("Titanic", "Drama", 1992, 10000, "link1");
	Movie m2 = Movie("Avengers", "Action", 2014, 9999, "link2");
	Movie m3 = Movie("Hellboy", "Action", 2019, 200, "link3");
	Repository repo = Repository();
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	Watchlist w{};
	w.addWatch(m1);
	w.addWatch(m2);
	assert(!w.addWatch(m1));
	assert(w.lenght() == 2);
	Controller ctrl{ repo, w };
	assert(ctrl.lenghtWatch() == 2);
	string s1 = "Avengers", s2="aaa", s3="Hellboy";
	ctrl.getWatchlist();
	w.getList();
	assert(ctrl.addToWatchlist(s3, 2019));
	assert(!ctrl.addToWatchlist(s3, 2019));

	assert(w.getPosByTitleYear(s1, 2014) == 1);

	assert(w.deleteByTitleYear(s1, 2014));
	assert(!w.deleteByTitleYear(s2, 2014));

	s1 = "Hellboy";
	assert(ctrl.deleteByTitleYearCtrl(s1, 2019));
	assert(!ctrl.deleteByTitleYearCtrl(s2, 2019));
}

void Test::run_tests()
{
	test_create();
	test_add();
	test_delete();
	test_update();
	test_getAll();
	test_getGenre();
	test_getPosition();
	test_operations();
	test_validations();
	test_watchlist();
	test_increaseByTitleYear();
}

