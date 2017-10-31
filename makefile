all: stat.c
	gcc -o things stat.c

clean:
	rm blah.txt
	rm things
	rm *~

run: all
	./things
