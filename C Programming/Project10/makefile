permits: permits.o readline.o request.o
	gcc -o permits permits.o readline.o request.o

permits.o: readline.h request.h permits.c
	gcc -c permits.c 

request.o: request.c request.h
	gcc -c request.c

readline.o: readline.h readline.c
	gcc -c readline.c


