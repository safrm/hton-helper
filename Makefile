
TARGET = hton-helper
CC     = cc
CFLAGS = -Wall -g

all: $(TARGET)

$(TARGET): hton-helper.c
	$(CC) $(CFLAGS) $(TEST_FILES) -o $@ hton-helper.c

install:
	mkdir -p $(DESTDIR)/usr/bin
	install -m 755 $(TARGET) $(DESTDIR)/usr/bin

test: all
	./$(TARGET)

.PHONY: clean
clean:	
	rm -f *.o $(TARGET)
