CC = g++
DEBUG = -g -O0
CFLAGS = -std=c++17 -Wall -c -fopenmp `gsl-config --cflags` `gsl-config --libs` $(DEBUG)
LFLAGS = -Wall -fopenmp `gsl-config --cflags` `gsl-config --libs` $(DEBUG)
MALLOC_CHECK = 2

CPP_FILES = functions.cpp main.cpp
HEADER_FILES = functions.h global.h
OBJECT_FILES = functions.o main.o

functions.o : functions.h global.h functions.cpp
		$(CC) $(CFLAGS) functions.cpp

main.o : $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) main.cpp

introtocpp :  $(OBJECT_FILES)
	$(CC) $(LFLAGS) $(DEBUG) $(OBJECT_FILES) -o introtocpp

clean :
	rm -f $(OBJECT_FILES) introtocpp
	echo Clean done
