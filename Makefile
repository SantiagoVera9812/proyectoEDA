# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11
# Linker flags
LFLAGS =
# Source files
SRCS = funcionalidades.cpp conversionUnidades.cpp main.cpp simulacion_de_movimiento.cpp struct.cpp kdTree.h
# Header files
HDRS = funcionalidades.h conversionUnidades.h simulacion_de_movimiento.h struct.h
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
TARGET = myprogram

# Default rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

