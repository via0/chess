CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = chess
SOURCES = main.cpp game.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	g++ $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
