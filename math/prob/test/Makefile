CC = $(CXX)
CXXFLAGS = -Wall -pedantic -std=c++11
ifdef _DEBUG
CXXLAGES += -g -D_DEBUG
endif

PROJ = test_prob

SRCS = $(wildcard t*.cpp) test_normal_pdf.cpp test_normal_cdf.cpp
OBJS = $(SRCS:.cpp=.o)

test: test_prob
	./test_prob

$(PROJ): $(OBJS)

test_normal_pdf.cpp: test_normal_pdf.sh
	./test_normal_pdf.sh

test_normal_cdf.cpp: test_normal_cdf.sh
	./test_normal_cdf.sh

.PHONY: clean
clean:
	@rm *.exe *.o test_normal_pdf.cpp
