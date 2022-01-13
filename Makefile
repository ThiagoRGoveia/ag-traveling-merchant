all:
	gcc -o exec ./src/*.c

run:
	./exec

clean:
	rm output/*

zip:
	@zip -r Grupo_06.zip *.c *.h Makefile nodes.dat data.dat README.md