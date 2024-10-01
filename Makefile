# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Executable name
EXEC = monopoly

# List of all source files
SRCS = Board.cpp Cube.cpp Game.cpp Player.cpp Property.cpp Railroad.cpp SpecialSpace.cpp Utility.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the executable
all: $(EXEC)

# Rule to link object files and create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f *.o $(EXEC)

# Phony targets
.PHONY: all clean
