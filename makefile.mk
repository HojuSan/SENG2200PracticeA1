CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core