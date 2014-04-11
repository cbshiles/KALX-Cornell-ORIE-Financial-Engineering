CC = $(CXX)
CXXFLAGS = -Wall -pedantic -std=c++11 -g

HDRS = $(wildcard *.h)
SRCS = $(wildcard *.cpp)
OBJS = $(TSRCS:.cpp=.o)

.PHONY: test
test: 
	$(MAKE) test -C test

.PHONY: clean
clean: 
	$(MAKE) clean -C test

