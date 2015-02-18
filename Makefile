
TARGET = hton-helper
CC     = cc
CFLAGS = -Wall -g

all: $(TARGET)

$(TARGET): hton-helper.c
	$(CC) $(CFLAGS) $(TEST_FILES) -o $@ hton-helper.c

test: all
	./$(TARGET)

.PHONY: clean
clean:	
	rm -f *.o $(TARGET)
