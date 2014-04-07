#!/bin/sh

TARGET=test_normal_pdf

# table of pdf values
bc -l > ${TARGET}.dat <<EoF
pi = 4*a(1)
sqrt2pi = sqrt(2*pi)
for (x = -8; x < 8; x += 0.01) {
	print "{", x, ", ", e(-x*x/2)/sqrt2pi, "},\n"
}
EoF

cat > ${TARGET}.cpp <<EoF
// ${TARGET}.cpp - test normal::pdf
#include <iostream>
#include <limits>
#include "../normal.h"

template<class X>
void ${TARGET}(void)
{
	X y;
	X eps = std::numeric_limits<X>::epsilon();
	prob::normal<X> n;

	struct { X x, y; } ${TARGET}_dat[] = {
#include "${TARGET}.dat"
	};
	for (auto xy : ${TARGET}_dat) {
		y = n.pdf(xy.x);
		ensure (static_cast<X>(fabs(y - xy.y) < eps));
	}
}

void ${TARGET}(void)
{
	${TARGET}<float>();
	${TARGET}<double>();
}
EoF
