include test.top

# more stuff here

.PHONY: data
data:
	test_normal_cdf.sh
	test_normal_pdf.sh

include test.bot

# r!make depends
test_prob.o: test_prob.cpp
test_normal_inv.o: test_normal_inv.cpp ../normal.h \
 $(ROOT)/include/ensure.h
