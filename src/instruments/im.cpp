#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

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

	friend double price(const i& x)
	{
		return x.i_->price_();
	}

private:
	// interface
	struct in {
		virtual ~in() = default;
		virtual double price_() const = 0;
	};
	// implementation
	template<typename I>
	struct im : in {
		im(I&& x)
			: x_(move(x))
		{ }
		double price_() const override
		{
			return price(x_);
		}
	private:
		I x_;
	};
	shared_ptr<const in> i_;
};

struct option {
	double k, t;
};
double price(const option& o)
{
	return o.k + o.t;
}

struct orward {
	double f, t;
};
double price(const orward& o)
{
	return o.f - o.t;
}
using portfolio = vector<i>;

double price(const portfolio& p)
{
	double a(0);

	for (const auto& i : p)
		a += price(i);

	return a;
}

int main()
{
	portfolio p;

	p.push_back(option{1,2});
	p.push_back(orward{1,2});

	cout << price(p) << endl;

	return 0;
}
