lab1_output: lab1A.o lab1Main.o
	gcc lab1A.o lab1Main.o -o lab1_output
lab1A.o: lab1A.c
	gcc -Wall -std=c99 -c lab1A.c
lab1B.o: lab1B.c
	gcc -Wall -std=c99 -c lab1B.c
lab1Main.o: lab1Main.c
	gcc -Wall -std=c99 -c lab1Main.c
clean:
	rm *.o lab1_output
