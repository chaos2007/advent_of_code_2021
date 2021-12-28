COMMON = common
ODIR = out/common

SRCS := $(wildcard $(COMMON)/*.cpp)
OBJS := $(patsubst common/%, $(ODIR)/%, $(SRCS:.cpp=.o))
FOLDERS := $(wildcard day_*)

ALL_SRCS := $(wildcard */*.cpp)

all: $(FOLDERS)

$(OBJS): $(SRCS)
	mkdir -p $(@D)
	g++ -c $< -o $@

$(FOLDERS): $(OBJS)
	$(MAKE) -f inner.mk DIR=$@


clean:
	rm -rf out/

format: $(ALL_SRCS)
	clang-format --style=google -i $(ALL_SRCS)

.PHONY: all $(FOLDERS) format
