CXX = g++
CXXFLAGS = -Wall -std=c++11
DEBUG_CXXFLAGS = -g -DDEBUG

TARGET = chess
SOURCES = main.cpp game.cpp
OBJECTS = $(SOURCES:.cpp=.o)

debug: CXXFLAGS += $(DEBUG_CXXFLAGS)
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(CXXFLAGS) $(OBJECTS) $(DEBUG) -o $(TARGET)

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
