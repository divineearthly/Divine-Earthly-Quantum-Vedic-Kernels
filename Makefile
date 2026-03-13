CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -Iinclude

SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/divine_kernel
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful! Run with: ./$(TARGET)"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Executing Moksha Protocol (Cleaning build)..."
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
