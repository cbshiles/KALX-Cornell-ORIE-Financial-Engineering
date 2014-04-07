// xllcorfe.h -  Cornell Operations Research Financial Engineering
#pragma once
#define EXCEL12
#include "../../xll8/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY _T("CORFE")
#endif
#define CATEGORY_PREFIX CATEGORY _T(".")

/// double that defaults to NaN
struct double_ {
	double x_;
	double_(double x = std::numeric_limits<double>::quiet_NaN())
		: x_(x)
	{ }
	operator double() const
	{
		return x_;
	}
	operator double&()
	{
		return x_;
	}
};