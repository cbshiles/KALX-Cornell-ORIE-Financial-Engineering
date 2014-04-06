// timer.h - timing functions
#pragma once
#include <chrono>
#include <functional>

namespace timer {

	class time {
		double elapsed_;
		std::function<void(void)> f_;
	public:
		time(const std::function<void(void)>& f)
			: f_(f)
		{ }
		void run(size_t count = 1)
		{
			std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();

			while (count--)
				f_();

			std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

			elapsed_ = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0).count();
		}
		double elapsed(void) const
		{
			return elapsed_;
		}
	};

} // timer