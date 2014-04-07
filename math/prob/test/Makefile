CC = $(CXX)
CXXFLAGS = -Wall -pedantic -std=c++11
#ifdef _DEBUG
CXXFLAGS += -g -D_DEBUG
#endif

PROJ = test_prob

SRCS = $(wildcard t*.cpp) test_normal_cdf.cpp test_normal_pdf.cpp
OBJS = $(SRCS:.cpp=.o)

test: test_prob
	./test_prob

$(PROJ): $(OBJS)

test_normal_cdf.cpp: test_normal_cdf.sh
	./test_normal_cdf.sh

test_normal_pdf.cpp: test_normal_pdf.sh
	./test_normal_pdf.sh

.PHONY: clean
clean:
	@rm  $(PROJ) *.exe *.o test_normal_cdf.cpp test_normal_pdf.cpp

deps:
	gcc -MM $(SRCS)

test_normal_cdf.o: test_normal_cdf.cpp ../normal.h \
 ../../stat/combinatorics.h ../../stat/../../include/ensure.h \
 test_normal_cdf.dat
test_normal_pdf.o: test_normal_pdf.cpp ../normal.h \
 ../../stat/combinatorics.h ../../stat/../../include/ensure.h \
 test_normal_pdf.dat
test_prob.o: test_prob.cpp
test_normal_cdf.o: test_normal_cdf.cpp ../normal.h \
 ../../stat/combinatorics.h ../../stat/../../include/ensure.h \
 test_normal_cdf.dat
test_normal_pdf.o: test_normal_pdf.cpp ../normal.h \
 ../../stat/combinatorics.h ../../stat/../../include/ensure.h \
 test_normal_pdf.dat
