CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs -pthread

OBJECTS = NameRunner.o VigenereCipher.o Parser.o PasswordGenerator.o StringHasher.hpp StringHashTable.o StringNode.o


main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gc* *.dSYM test/test core main