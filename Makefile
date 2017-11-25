CC=gcc
OBJECTS=\
	template.o \
	main.o

note_taker: $(OBJECTS)
	$(CC) $(OBJECTS) -o note_taker
