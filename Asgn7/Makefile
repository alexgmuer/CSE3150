CC=g++
CFLAGS=-g -std=c++14
DEPS = Simulator.hpp
OBJ = main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	@rm -rf *.o *~ main *.dSYM