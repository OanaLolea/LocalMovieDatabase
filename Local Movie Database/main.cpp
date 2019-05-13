#include<iostream>
#include"UI.h"
#include "Tests.h"

using namespace std;

int main() {
	{
		// pentru lab 8 datele trebuie citite din fisier text
		Test::run_tests();
		Movie m1 = Movie("Titanic", "Drama", 1997, 10000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
		Movie m2 = Movie("Avengers: Endgame", "Action", 2019, 9999, "https://www.youtube.com/watch?v=TIQZjO5dfnQ");
		Movie m3 = Movie("Hellboy", "Action", 2019, 200, "https://www.youtube.com/watch?v=ZsBO4b3tyZg");
		Movie m4 = Movie("A Star is Born", "Romance", 2018, 1200, "https://www.youtube.com/watch?v=4-tcHHyy1Rw");
		Movie m5 = Movie("Dear John", "Romance", 2010, 1200, "https://www.youtube.com/watch?v=r0fq5dd0C60");
		Movie m6 = Movie("Guardians of the Galaxy", "Action", 2014, 3000, "https://www.youtube.com/watch?v=d96cjJhvlMA");
		Movie m7 = Movie("Hitman", "Action", 2007, 7777, "https://www.youtube.com/watch?v=XJhNzHyq-IE");
		Movie m8 = Movie("Doctor Strange", "Action", 2016, 1234, "https://www.youtube.com/watch?v=HSzx-zryEgM");
		Movie m9 = Movie("10 Things I Hate About You", "Comedy", 1999, 3000, "https://www.youtube.com/watch?v=d96cjJhvlMA");
		Movie m10 = Movie("The Butterfly Effect", "Thriller", 2004, 5555, "https://www.youtube.com/watch?v=B8_dgqfPXFg");
		Repository repo = Repository();
		repo.add(m1);
		repo.add(m2);
		repo.add(m3);
		repo.add(m4);
		repo.add(m5);
		repo.add(m6);
		repo.add(m7);
		repo.add(m8);
		repo.add(m9);
		repo.add(m10);
		Watchlist w{};
		Controller c = Controller(repo, w);
		UI ui = UI(c);
		
		ui.startUI();
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
