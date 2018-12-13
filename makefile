CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=Point.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core