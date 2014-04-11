CC = $(CXX)
CXXFLAGS = -Wall -pedantic -std=c++11 -I$(ROOT)

all: test
debug: CXXFLAGS += -g -D_DEBUG
debug: test

PROJ = test_prob

GENS = test_normal_cdf.cpp test_normal_pdf.cpp
SRCS = $(wildcard *.cpp) $(GENS)
OBJS = $(SRCS:.cpp=.o)

test: $(PROJ)
	./$(PROJ)

$(PROJ): $(OBJS)

$(GENS): $(GENS:.cpp=.sh)
	./$*.sh

.PHONY: clean
clean:
	-rm -f  $(PROJ) *.exe *.o $(GENS)

.PHONY: depend
depend:
	gcc -MM $(CXXFLAGS) $(SRCS)

# :r!make depend
test_normal_cdf.o: test_normal_cdf.cpp ../normal.h \
 $(ROOT)/include/ensure.h test_normal_cdf.dat
test_normal_inv.o: test_normal_inv.cpp ../normal.h \
 $(ROOT)/include/ensure.h
test_normal_pdf.o: test_normal_pdf.cpp ../normal.h \
 $(ROOT)/include/ensure.h test_normal_pdf.dat
test_prob.o: test_prob.cpp
test_normal_cdf.o: test_normal_cdf.cpp ../normal.h \
 $(ROOT)/include/ensure.h test_normal_cdf.dat
test_normal_pdf.o: test_normal_pdf.cpp ../normal.h \
 $(ROOT)/include/ensure.h test_normal_pdf.dat
