CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17 -Iinclude
TARGET = vedic_engine

SOURCES = main.cpp vedic_logic.cpp sutras/main_sutra_1.cpp sutras/main_sutra_10.cpp sutras/main_sutra_11.cpp sutras/main_sutra_12.cpp sutras/main_sutra_13.cpp sutras/main_sutra_14.cpp sutras/main_sutra_15.cpp sutras/main_sutra_16.cpp sutras/main_sutra_2.cpp sutras/main_sutra_3.cpp sutras/main_sutra_4.cpp sutras/main_sutra_5.cpp sutras/main_sutra_6.cpp sutras/main_sutra_7.cpp sutras/main_sutra_8.cpp sutras/main_sutra_9.cpp sutras/sub_sutra_1.cpp sutras/sub_sutra_10.cpp sutras/sub_sutra_11.cpp sutras/sub_sutra_12.cpp sutras/sub_sutra_13.cpp sutras/sub_sutra_14.cpp sutras/sub_sutra_15.cpp sutras/sub_sutra_16.cpp sutras/sub_sutra_2.cpp sutras/sub_sutra_3.cpp sutras/sub_sutra_4.cpp sutras/sub_sutra_5.cpp sutras/sub_sutra_6.cpp sutras/sub_sutra_7.cpp sutras/sub_sutra_8.cpp sutras/sub_sutra_9.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
