CC = gcc
CFLAGS = -g -std=c99 -Wall

report.exe: report.o temp_functions.o
	$(CC) -o report.exe report.o temp_functions.o

report.i: report.c temp_functions.h
	$(CC) $(CFLAGS) -E report.c -o report.i

report.s: report.i
	$(CC) $(CFLAGS) -S report.i -o report.s

report.o: report.c temp_functions.h
	$(CC) $(CFLAGS) -c report.c

temp_functions.i: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -E temp_functions.c -o temp_functions.i

temp_functions.s: temp_functions.i
	$(CC) $(CFLAGS) -S temp_functions.i -o temp_functions.s

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -c temp_functions.c

clean:
	rm -f *.i *.s *.o report.exe
