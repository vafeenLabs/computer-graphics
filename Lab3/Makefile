CC = g++
CFLAGS = -std=c++17 -Wall
LDFLAGS = -lglfw -lGL -lGLEW
TARGET = program
SRC = *.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
