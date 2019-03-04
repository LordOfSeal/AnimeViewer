CC=gcc
CFLAGS += -Wall -g -c
LDFLAGS += -lsqlite3

all: main.o db.o
	$(CC) -o main main.o db.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) main.c
	
db.o: db.c
	$(CC) $(CFLAGS) db.c
