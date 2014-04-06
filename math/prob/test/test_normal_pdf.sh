#!/bin/sh

TARGET=test_normal_pdf

cat > ${TARGET}.cpp <<EoF
// ${TARGET}.cpp - test normal::pdf
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
pi = 4*a(1)
sqrt2pi = sqrt(2*pi)
for (x = -8; x < 8; x += 0.01) {
	print "\ty0 = n.pdf(", x, ");\n"
	print "\ty1 = ", e(-x*x/2)/sqrt2pi, ";\n"
	print "\tensure (static_cast<X>(fabs(y0 - y1) < eps));\n"
}
EoF

cat >> ${TARGET}.cpp <<EoF
}

void test_normal_pdf(void)
{
	${TARGET}<float>();
	${TARGET}<double>();
}
EoF
