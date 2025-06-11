.POSIX:
.SUFFIXES:
CC     = cc
CFLAGS += \
    -O3 \
    -std=c2x -Wno-gnu-alignof-expression \
    -Wall \
    -Wextra \
    -Wconversion \
    -Wdouble-promotion \
    -Wno-unused-parameter \
    -Wno-unused-function \
    -Wno-sign-conversion \
    -Wno-unknown-pragmas
LDLIBS = 

all: fun
run: fun
	./bin/fun
fun: src/main.o
	$(CC) $(LDFLAGS) -o ./bin/fun main.o $(LDLIBS)
src/main.o: src/main.c
clean:
	rm -f bin/* main.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
