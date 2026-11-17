CXX = clang++

CXXFLAGS = -std=c++20 -Wall -Wextra -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# 要编译的子项目: minigame | art | drawing | animation | soundboard
PROJECT ?= minigame
SRC = $(PROJECT)/main.cpp
TARGET = $(PROJECT)/main

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f minigame/main art/main drawing/main animation/main soundboard/main
