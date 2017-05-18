CC := gcc
CFLAGS := -c -Wall -Werror
EXE := bin/canalize

all: $(EXE)

$(EXE): build/src/main.o build/src/process.o build/src/strings.o
		$(CC) build/src/main.o build/src/process.o build/src/strings.o -o $@

build/src/main.o: src/main.c
		$(CC) -I src $(CFLAGS) src/main.c -o $@   

build/src/process.o: src/process.c
		$(CC) -I src $(CFLAGS) src/process.c -o $@

build/src/strings.o: src/strings.c
		$(CC) -I src $(CFLAGS) src/strings.c -o $@ 

.PHONY: all clean
clean:	
		rm -rf build/src/*.o
		rm -rf bin/*
