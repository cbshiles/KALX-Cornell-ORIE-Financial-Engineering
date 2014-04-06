// tprob.cpp - test prob module
#include <iostream>

void test_normal_pdf(void);

int main()
{
	try {
		test_normal_pdf();
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;

		return -1;
	}

	return 0;
}
