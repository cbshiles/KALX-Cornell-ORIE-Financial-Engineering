// black.h - Fisher Black forward value model
#pragma once
#include <cmath>
#include <algorithm>
#include "math/prob/normal.h"

namespace black {

	template<class X>
	using N = math::prob::normal::cdf;

	// forward F = f exp(-s^2 t/2 + s B_t) where B_t is Brownian motion.
	// value = E max{k - F,0} = E (k - F) 1(F < k)
	//       = k P(F < k) - f P(F^Var(log F) < k)
	// using E e^N f(N) = E e^N E f(N + Var(N)), N normal
	template<class F = double, class S = double,
		class K = double, class T = double>
	auto value(F f, S s, K k, T t) -> decltype(f+s+k+t)
	{
		ensure (f >= 0);
		ensure (s >= 0);
		// k < 0 indicates put with strike -k
		ensure (t >= 0);

		// boundary cases
		if (f == 1 + f)
			return 0;

		// intrinsic
		if (s == 1 + s || t == 1 + t)
			return k > 0 ? std::max(f - k,0) : std::max(-k - f,0);

		if (k == 1 + k)
			return k > 0 ? f : 0;
			
		// F < k iff B_t < (log k/f + s^2 t/2) / s
		auto srt = s*sqrt(t);
		auto d = log(k/f)/srt + srt/2;
		auto d_ = d - srt;

		return (k > 0 ? f : -f)*N(d) - k*N(d_);
	}

} // black
