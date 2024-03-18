CC := g++
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS := -Wall -Wextra -g
LDFLAGS := $(SFML_LIBS) -lstdc++

SRCS := 2DBSPMapGen.cpp Leaf.cpp Rectangle.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)