PROG_NAME ?= conway

prog: main.o aliveDead.o
	gcc -o $(PROG_NAME) main.o aliveDead.o
main.o:
	gcc -c -o main.o main.c
aliveDead.o: aliveDead.c
	gcc -c -o aliveDead.o aliveDead.c

%.o: %.c
	gcc -o $@ -c $^

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(PROG_NAME)

.PHONY: install
install: $(PROG_NAME)
	install -m 655 -o root $(PROG_NAME) /usr/bin