// xllnormal.cpp - normal distrbution
#include "xll/xllcorfe.h"
#include "math/prob/normal.h"

using namespace xll;

static AddInX xai_normal_pdf(
	FunctionX(XLL_DOUBLEX, _T("?xll_normal_pdf"), CATEGORY_PREFIX _T("NORMAL.PDF"))
	.Num(_T("x"), _T("is a number."))
	.ThreadSafe()
	.Category(CATEGORY)
	.FunctionHelp(_T("Return the standard normal probability density function."))
);
double WINAPI xll_normal_pdf(double x)
{
#pragma XLLEXPORT
	return prob::normal<>().pdf(x);
}

static AddInX xai_normal_cdf(
	FunctionX(XLL_DOUBLEX, _T("?xll_normal_cdf"), CATEGORY_PREFIX _T("NORMAL.CDF"))
	.Num(_T("x"), _T("is a number."))
	.Category(CATEGORY)
	.ThreadSafe()
	.FunctionHelp(_T("Return the standard normal cumulative distribution function."))
);
double WINAPI xll_normal_cdf(double x)
{
#pragma XLLEXPORT
	return prob::normal<>().cdf(x);
}

static AddInX xai_normal_inv(
	FunctionX(XLL_DOUBLEX, _T("?xll_normal_inv"), CATEGORY_PREFIX _T("NORMAL.INV"))
	.Num(_T("x"), _T("is a number."))
	.Category(CATEGORY)
	.ThreadSafe()
	.FunctionHelp(_T("Return the inverse of the standard normal cumulative distribution function."))
);
double WINAPI xll_normal_inv(double x)
{
#pragma XLLEXPORT
	double_ i;

	try {
		i = prob::normal<>().inv(x);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return i;
}