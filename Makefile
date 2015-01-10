all:
	gcc -Wall -pedantic -std=c99 ./src/fileeditor.c -Iinclude -lncurses -o ./bin/output

run:
	./bin/output

clean:
	rm ./bin/output