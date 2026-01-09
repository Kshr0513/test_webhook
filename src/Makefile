CC = g++
CFLAGS = -std=c++20
TARGET = main
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
INCDIR = -I../inc
LIBDIR =
LIBS = -lcurl
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)
all: clean $(OBJS) $(TARGET)
clean:
	-rm -f $(OBJS) $(TARGET) *.d
run: $(TARGET)
	./$(TARGET)