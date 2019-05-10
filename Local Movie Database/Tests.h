#pragma once
#include "Controller.h"

using namespace std;
class Test {
public:
	static void test_create();
	static void test_add();
	static void test_delete();
	static void test_update();
	static void test_getAll();
	static void test_increaseByTitleYear();

	static void test_getGenre();
	static void test_getPosition();
	static void test_operations();
	static void test_validations();
	static void test_watchlist();

	static void run_tests();
};