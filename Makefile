CC = gcc
CFLAGS = -Wall -Isrc
LIBS=`pkg-config --cflags --libs check`

SRC = src/math_utils.c
TEST_SRC = test/test_math.c
TARGET = test_runner

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
