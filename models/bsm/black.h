// black.h - Fisher Black forward value model
#pragma once
#include "math/prob/normal.h"

namespace black {

	// Negative strike means put instead of call.
	// E max{F - k,0}, k > 0; E max{-k - F,0}, k < 0
	template<class F = double, class S = double,
		class K = double, class T = double>
	auto value(F f, S s, K k, T t) -> decltype(f+s+k+t)
	{
		auto srt = s*sqrt(t);
		auto d = (ln(k/f) + s*s*t/2)/srt;
		auto d_ = d - srt;

		return k > 0 ? f*N(d) - k*N(
	}


} // black
