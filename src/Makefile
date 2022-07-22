CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

MatrixCalculator: calculator.o driver.o
	$(CC) $(LFLAGS) calculator.o driver.o -o MatrixCalculator

calculator.o: calculator.h calculator.c
	$(CC) $(CFLAGS) calculator.c

driver.o: driver.h calculator.h calculator.c driver.c
	$(CC) $(CFLAGS) driver.c

clean:
	rm -f *.o MatrixCalculator