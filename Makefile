CC = gcc
CFLAGS = -W -Wall
TARGET = calendar.exe
OBJECTS = ./inc/calendar.o ./inc/CRUD_calendar.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm ./inc/*.o *.exe