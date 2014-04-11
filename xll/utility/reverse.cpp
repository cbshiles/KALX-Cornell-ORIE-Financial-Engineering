// reverse.cpp - reverse elements of an array or range
#define EXCEL12
#include "../xll8/xll/xll.h"
#include <algorithm>

#ifndef CATEGORY
#define CATEGORY _T("XLL")
#endif

using namespace xll;

typedef traits<XLOPERX>::xfp xfp;

static AddInX xai_array_reverse(
	FunctionX(XLL_FPX, _T("?xll_array_reverse"), _T("ARRAY.REVERSE"))
	.Arg(XLL_FPX, _T("Array"), _T("is an array of numbers to reverse."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Return numbers of Array in opposite order."))
);
xfp* xll_array_reverse(xfp* pa)
{
#pragma XLLEXPORT
	std::reverse(begin(*pa), end(*pa));

	return pa;
}

static AddInX xai_range_reverse(
	FunctionX(XLL_LPXLOPERX, _T("?xll_range_reverse"), _T("RANGE.REVERSE"))
	.Arg(XLL_LPOPERX, _T("Range"), _T("is a Range of cells to reverse."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Return cells of range in opposite order."))
);
LPXLOPERX xll_range_reverse(LPOPERX po)
{
#pragma XLLEXPORT
	static OPERX o(*po);

	std::reverse(o.begin(), o.end());

	return &o;
}
