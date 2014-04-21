// bsm.h - Black-Scholes/Merton model
#pragma once
#include "black.h"

namespace bsm {

	// spot X = exp(-rt) F where F is the forward
	template<class R = double, class X = double, class S = double,
		class K = double, class T = double>
	auto value(R r, X x, S s, K k, T t) -> decltype(r+f+s+k+t)
	{
		auto R = exp(r*t);

		return black::value(R*x, s, k, t)/R;
	}

} // bsm
