CXX ?= g++
CXXFLAGS = -std=c++17 -Wall -I./src/header

SRC_DIR := src
BUILD_DIR := build
HEADER_DIR := $(SRC_DIR)/header

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o,$(SRCS))

TARGET := $(BUILD_DIR)/game

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/*.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

run: all
	./$(TARGET)


.PHONY: all clean run