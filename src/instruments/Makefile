PROJ = main
CXXFLAGS = -Wall -std=c++11 -I$(ROOT)

all:: $(PROJ)
debug: CXXFLAGS += -g
debug: all

im: im.cpp
	$(CXX) $(CXXFLAGS) $< -o $@.exe
