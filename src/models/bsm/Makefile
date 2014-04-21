HDRS = $(wildcard *.h)
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp:.o)

INST = $(subst /src/,/include/,$(realpath .))

install: $(HDRS)
	install $(HDRS) $(INST)
