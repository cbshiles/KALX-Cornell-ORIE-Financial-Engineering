// tprob.cpp - test prob module
#include <iostream>

void test_normal_pdf(void);
void test_normal_cdf(void);

int main()
{
	try {
		test_normal_pdf();
		test_normal_cdf();
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;

		return -1;
	}

	return 0;
}
