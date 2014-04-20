#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<class P = double>
class i {
public:
	template<typename I>
	i(I x)
		: i_(make_shared<const im<I>>(std::move(x)))
	{ }
	i(const i&) noexcept = default;
	i& operator=(const i&) noexcept = default;
	i(i&&) noexcept = default;
	i& operator=(i&&) noexcept = default;
	~i() noexcept = default;

	template<typename M>
	friend P value(const i& x, const M& m)
	{
		return m(x.i_);
	}

private:
	// interface
	struct in {
		virtual ~in() = default;
		template<class M>
		virtual P value_(const M&) const = 0;
	};
	// implementation
	template<typename I>
	struct im : in {
		im(I&& x)
			: x_(move(x))
		{ }
		template<class M>
		P value_(const M& m) const override
		{
			return value(x_,m);
		}
	private:
		I x_;
	};
	shared_ptr<const in> i_;
};

struct option {
	double k, t;
};
template<class M>
double value(const option& o, const M& m)
{
	return o.k + o.t;
}

struct orward {
	double f, t;
};
template<class M>
double value(const orward& o, const M& m)
{
	return o.f - o.t;
}
using portfolio = vector<i<double>>;

template<class M>
double value(const portfolio& p, const M& m)
{
	double a(0);

	for (const auto& i : p)
		a += value(i);

	return a;
}

int main()
{
	portfolio p;
	option o{3,4}, o2(o), o3;
	o3 = o;
	assert (o.k == 3 && o.t == 4);
	assert (o2.k == 3 && o2.t == 4);
	assert (o3.k == 3 && o3.t == 4);

	p.emplace_back(option{1,2});
	p.emplace_back(orward{1,2});

	cout << value(p) << endl;

	return 0;
}
