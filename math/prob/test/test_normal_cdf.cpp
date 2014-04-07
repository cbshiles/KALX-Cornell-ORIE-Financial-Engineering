// test_normal_cdf.cpp - test normal::cdf
#include <iostream>
#include <limits>
#include "../normal.h"

template<class X>
void test_normal_cdf(void)
{
	X y;
	X eps = std::numeric_limits<X>::epsilon();
	prob::normal<X> n;

	struct { X x, y; } test_normal_cdf_dat[] = {
#include "test_normal_cdf.dat"
	};
	for (auto xy : test_normal_cdf_dat) {
		y = n.cdf(xy.x);
		ensure (static_cast<X>(fabs(y - xy.y) < 10*eps));
		y = erfc(-xy.x/M_SQRT2)/2;
		ensure (static_cast<X>(fabs(y - xy.y) < 2*eps));
	}
}

void test_normal_cdf(void)
{
	test_normal_cdf<float>();
	test_normal_cdf<double>();
}
