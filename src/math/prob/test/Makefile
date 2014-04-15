include test.top

# more stuff here

# generated files
GENS = test_normal_cdf.cpp test_normal_pdf.cpp

include test.bot

foo:
	echo $(SRCS)

# r!make depends
test_prob.o: test_prob.cpp
test_normal_inv.o: test_normal_inv.cpp ../normal.h \
 $(ROOT)/include/ensure.h
