#!/bin/sh

TARGET=test_normal_cdf

cat > ${TARGET}.cpp <<EoF
// ${TARGET}.cpp - test normal::cdf
#include <iostream>
#include <limits>
#include "../normal.h"

template<class X>
void ${TARGET}(void)
{
	double y0, y1;
	double eps = std::numeric_limits<X>::epsilon();
	corfe::prob::normal<X> n;
EoF

bc -l >> ${TARGET}.cpp <<EoF
const=0.5*l(8*a(1))
define phi(x) {
    auto s,t,b,q,i
    s=x; t=0; b=x; q=x*x; i=1
    while(s!=t)
        s=(t=s)+(b*=q/(i+=2))
    return (.5+s*e(-.5*q-const))
}
for (x = -8; x < 8; x += 0.01) {
	print "\ty0 = n.cdf(", x, ");\n"
	print "\ty1 = ", phi(x), ";\n"
	print "\tensure (static_cast<X>(fabs(y0 - y1) < eps));\n"
}
EoF

cat >> ${TARGET}.cpp <<EoF
}

void ${TARGET}(void)
{
	${TARGET}<float>();
	${TARGET}<double>();
}
EoF
