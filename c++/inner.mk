COMMON = common
ODIR = out/$(DIR)
COMMON_ODIR := out/$(COMMON)
TARGET := $(ODIR)/a.out

COMMON_OBJS := $(wildcard $(COMMON_ODIR)/*.o)
SRCS := $(wildcard $(DIR)/*.cpp)
OBJS := $(patsubst $(DIR)/%, $(ODIR)/%, $(SRCS:.cpp=.o))
CFLAGS := -I$(COMMON)

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	g++ $< $(COMMON_OBJS) -o $(TARGET)

$(OBJS): $(SRCS)
	mkdir -p $(@D)
	g++ -c $< $(CFLAGS) -o $@

