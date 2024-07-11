CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17

SOURCES = player.cpp catan.cpp board.cpp
HEADERS = player.hpp catan.hpp board.hpp CTools.hpp
OBJECTS = $(SOURCES:.cpp=.o)

GAME_SOURCES = TheGame.cpp
GAME_OBJECTS = $(GAME_SOURCES:.cpp=.o)
GAME_TARGET = catan

TEST_SOURCES = Test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_TARGET = test

all: $(GAME_TARGET) $(TEST_TARGET)

$(GAME_TARGET): $(GAME_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(GAME_TARGET) $(GAME_OBJECTS) $(OBJECTS)

$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJECTS) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(GAME_OBJECTS) $(GAME_TARGET) $(TEST_OBJECTS) $(TEST_TARGET)

distclean: clean
	rm -f *~ *.bak *.tmp

clean_obj:
	rm -f $(OBJECTS)

rebuild: clean all

.PHONY: all clean distclean clean_obj rebuild
