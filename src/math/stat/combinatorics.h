// combinatorics.h - various combinatorial routines
#pragma once
#include <assert.h>
#include "../../include/ensure.h"
#include <map>
#include <vector>

namespace combinatorics {

	inline unsigned long long factorial(size_t n)
	{
		typedef unsigned long long ullong;
		static std::vector<ullong>f{1,1,2,6};

		if (n >= f.size()) {
			ullong f_ = factorial(n - 1);
			assert (f.size() == n);
			f.push_back(f_*n);
		}

		return f[n];
	}

	inline unsigned long long choose(size_t n, size_t k)
	{
		typedef unsigned long long ullong;
		static std::map<std::pair<size_t,size_t>,ullong> c
			{{std::make_pair(0,0),1},
			 {std::make_pair(1,0),1},
			 {std::make_pair(1,1),1}};

		ensure (k <= n);

		auto nk = std::make_pair(n,k);
		auto cnk = c.find(nk);
		if (cnk == c.end()) {
			return c[nk] = (k == 0 || k == n)
				? 1 : choose(n-1,k-1) + choose(n-1,k);
		}

		return cnk->second;
	}
}
