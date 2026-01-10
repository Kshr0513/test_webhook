CXX = g++
CXXFLAGS = -std=c++20 -I../inc
TARGET = main

SRCS = main.cpp funcJson.cpp funcWebhook.cpp
OBJS = $(SRCS:.cpp=.o)

LIBS = -lcurl

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)