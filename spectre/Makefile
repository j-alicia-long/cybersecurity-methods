CFLAGS=-no-pie
all: assignment-unsafe

assignment-unsafe: assignment-unsafe.s
	gcc assignment-unsafe.s -o assignment-unsafe $(CFLAGS)

clean:
	rm -f  assignment-unsafe *.o
