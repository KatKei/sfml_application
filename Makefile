test.o :
	g++ -c test.cpp
	g++ -c sprite2.cpp
	g++ -c edibles.cpp
	g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lpng -lz

all: $(OBJS) clean

clean :
	rm -f *.o $(EXENAME)
