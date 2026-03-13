CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -Iinclude

BUILD_DIR = build

# Source files
SRCS = main.cpp \
       memory/GarudaShredder.cpp \
       compute/YogaAttention.cpp \
       memory/AkashicRecords.cpp

# Object files will be placed in BUILD_DIR
# The patsubst function needs to handle source files in subdirectories
OBJS = $(addprefix $(BUILD_DIR)/, $(patsubst %.cpp,%.o,$(SRCS)))

TARGET = $(BUILD_DIR)/divine_kernel

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Generic rule to compile .cpp files into .o files
# This rule needs to handle sources in subdirectories and place objects in corresponding build subdirectories
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Executing Moksha Protocol (Cleaning build)..."
	rm -rf $(BUILD_DIR)/*
