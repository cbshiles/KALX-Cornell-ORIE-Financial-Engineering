// iota.cpp - 0,1,2,...
#include "../xll8/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY _T("XLL")
#endif

using namespace xll;

typedef traits<XLOPERX>::xfp xfp;
typedef traits<XLOPERX>::xword xword;

static AddInX xai_itoa(
	FunctionX(XLL_FPX, _T("?xll_iota"), _T("IOTA"))
	.Arg(XLL_LONGX, _T("Count"), _T("is the number of cells to return."))
	.Arg(XLL_DOUBLEX, _T("_Start"), _T("is the optional initial value. Default is 0."))
	.Arg(XLL_DOUBLEX, _T("_Step"), _T("is the optional increment. Default is 1."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Return {Start, Start + Step, Start + 2*Step, ...}."))
);
xfp* xll_iota(LONG count, double start, double step)
{
#pragma XLLEXPORT
	static FPX x;

	try {
		ensure (count <= traits<XLOPERX>::rwmax);

		if (step == 0)
			step = 1;

		x.resize(static_cast<xword>(count), 1);
		for (xword i = 0; i < count; ++i)
			x[i] = start + i*step;
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());

		return 0;
	}

	return x.get();
}