# Makefile for compiling all C files in the current directory

CC = gcc
CFLAGS = -m32 -nostdlib -ffreestanding -O0 -g
LDFLAGS = -Wl,--build-id=none -Wl,-e,_start -O0 -g
OUTPUT = TestElf

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(OUTPUT)

build: $(OUTPUT)
	mkdir -p build
	cp $(OUTPUT) ../RawExecution/Drivers/ELF/$(OUTPUT)

clean:
	rm -f $(OUTPUT) $(OBJECTS)