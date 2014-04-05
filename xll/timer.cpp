// timer.cpp - time a cell
#include "include/timer.h"
#include "../../xll8/xll/xll.h"

using namespace xll;

static AddInX xai_timer(
	FunctionX(XLL_DOUBLEX, _T("?xll_timer"), _T("XLL.TIMER"))
	.Arg(XLL_LPXLOPER, _T("Cell"), _T("is a reference to a cell."))
	.Arg(XLL_LONGX, _T("_Count"), _T("is the optional number of times to evaluate the cell."))
	.Category(_T("XLL"))
	.FunctionHelp(_T("Return time in seconds to evaluate a cell."))
);
double WINAPI xll_timer(LPXLOPERX pRef, LONG count)
{
#pragma XLLEXPORT
	double t(std::numeric_limits<double>::quiet_NaN());

	try {
		if (count == 0)
			count = 1;

		timer::time f([=](void) { XLL_XLF(Evaluate, *pRef); });
		f.run(count);

		t = f.elapsed();
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return t;
}
