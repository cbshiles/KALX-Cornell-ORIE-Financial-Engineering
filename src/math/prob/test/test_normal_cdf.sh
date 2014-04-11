#!/bin/sh

TARGET=test_normal_cdf

bc -l > ${TARGET}.dat <<EoF
scale=32
const=0.5*l(8*a(1))
define phi(x) {
    auto s,t,b,q,i
    s=x; t=0; b=x; q=x*x; i=1
    while(s!=t)
        s=(t=s)+(b*=q/(i+=2))
    return (.5+s*e(-.5*q-const))
}
for (x = -8; x < 8; x += 0.01) {
	print "{", x, ", ", phi(x), "},\n"
}
EoF

cat > ${TARGET}.cpp <<EoF
// ${TARGET}.cpp - test normal::cdf
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
		y = n.cdf(xy.x);
		ensure (static_cast<X>(fabs(y - xy.y) < 10*eps));
		y = erfc(-xy.x/M_SQRT2)/2;
		ensure (static_cast<X>(fabs(y - xy.y) < 2*eps));
	}
}

void ${TARGET}(void)
{
	${TARGET}<float>();
	${TARGET}<double>();
}
EoF
