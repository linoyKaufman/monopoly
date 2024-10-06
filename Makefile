# The name of the final executable for the main game
TARGET = monopoly

# The name of the test executable
TEST_TARGET = test_game

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Object files for the main game
OBJS = Board.o Player.o Cube.o Property.o Railroad.o Utility.o SpecialSpace.o main.o

# Object files for the test
TEST_OBJS = Board.o Player.o Cube.o Property.o Railroad.o Utility.o SpecialSpace.o test_game.o

# The default target, build the executable
all: $(TARGET)

# Linking the object files to create the executable for the main game
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Linking the object files to create the executable for the test
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Compile individual source files into object files
Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Cube.o: Cube.cpp Cube.hpp
	$(CXX) $(CXXFLAGS) -c Cube.cpp

Property.o: Property.cpp Property.hpp
	$(CXX) $(CXXFLAGS) -c Property.cpp

Railroad.o: Railroad.cpp Railroad.hpp
	$(CXX) $(CXXFLAGS) -c Railroad.cpp

Utility.o: Utility.cpp Utility.hpp
	$(CXX) $(CXXFLAGS) -c Utility.cpp

SpecialSpace.o: SpecialSpace.cpp SpecialSpace.hpp
	$(CXX) $(CXXFLAGS) -c SpecialSpace.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile the test game source file into an object file
test_game.o: test_game.cpp
	$(CXX) $(CXXFLAGS) -c test_game.cpp

# Clean the build (remove object files and the executable)
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET) *.o
