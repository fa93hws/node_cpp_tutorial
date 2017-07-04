CC=g++
CFLAG=-O2 -s -DNDEBUG

all: demo_lib.o
	$(CC) $(CFLAG) -o hello.exe demo_lib.o main.cpp

demo_lib.o: demo_lib.h demo_lib.cpp
	$(CC) -c demo_lib.cpp


clean:
	rm demo_lib.o

run:
	./hello.o