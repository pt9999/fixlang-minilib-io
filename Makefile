all:

test:
	fix test

clean:
	fix clean
	rm -f *.o
	rm -rf .tmp

%.o : %.c
	gcc -Wall -o $@ -c $<
