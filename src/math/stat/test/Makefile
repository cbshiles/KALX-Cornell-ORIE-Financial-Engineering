CC = $(CXX)
CXXFLAGS = -Wall -pedantic -std=c++11
ifdef _DEBUG
CXXLAGES += -g -D_DEBUG
endif

PROJ = test_stat

SRCS = $(wildcard t*.cpp)
OBJS = $(SRCS:.cpp=.o)

test: $(PROJ)
	./$(PROJ)

$(PROJ): $(OBJS)

.PHONY: clean
clean:
	@rm  $(PROJ) *.exe *.o

deps: $(SRCS)
	gcc -MM $(SRCS) 

test_stat.o: test_stat.cpp ../combinatorics.h ../../../include/ensure.h
