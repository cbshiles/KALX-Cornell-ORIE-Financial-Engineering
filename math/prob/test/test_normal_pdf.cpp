// test_normal_pdf.cpp - test normal::pdf
#include <iostream>
#include <limits>
#include "../normal.h"

template<class X>
void test_normal_pdf(void)
{
	X y;
	X eps = std::numeric_limits<X>::epsilon();
	prob::normal<X> n;

	struct { X x, y; } test_normal_pdf_dat[] = {
#include "test_normal_pdf.dat"
	};
	for (auto xy : test_normal_pdf_dat) {
		y = n.pdf(xy.x);
		ensure (static_cast<X>(fabs(y - xy.y) < eps));
	}
}

void test_normal_pdf(void)
{
	test_normal_pdf<float>();
	test_normal_pdf<double>();
}
