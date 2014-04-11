// test_stat.cpp - test statistics module
#include <iostream>
#include "../combinatorics.h"

using namespace combinatorics;

void test_factorial(void)
{
	ensure  (factorial(0) == 1);
	ensure  (factorial(1) == 1);
	ensure  (factorial(2) == 2);
	ensure  (factorial(3) == 6);
	ensure  (factorial(10) == 3628800);
}

void test_choose(void)
{
	ensure (choose(0,0) == 1);
	ensure (choose(1,0) == 1);
	ensure (choose(1,1) == 1);
	ensure (choose(2,0) == 1);
	ensure (choose(2,1) == 2);
	ensure (choose(2,2) == 1);
	ensure (choose(10,5) == 252);
}

int main(void)
{
	try {
		test_factorial();
		test_choose();
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;

		return -1;
	}

	return 0;
}
