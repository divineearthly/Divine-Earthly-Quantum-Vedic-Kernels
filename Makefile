CXX = g++
CXXFLAGS = -std=c++17 -O3 -I./

# Source files
SRC = main.cpp \
      AIAgent.cpp \
      Tokenizer.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Target executable name
TARGET = ai_agent_demo

# Default rule
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
