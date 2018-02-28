CC = g++
DEBUG = -g
CFLAGS = -Wall -std=gnu++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LAB = lab08

compile: $(LAB).out

$(LAB).out: $(LAB).cpp
	$(CC) $(CFLAGS) -o $(LAB).out $(LAB).cpp

run: $(LAB).out
	./$(LAB).out '5.75 * ( ( 23.9 - 8.9 ) + 2 ) * 9 / 7.5'

	./$(LAB).out '6 + 4 * 2.5'
	./$(LAB).out '( 6 + 4 ) * 2.5'
	./$(LAB).out '( ( 6 + 4 ) * 2.5 )'
	./$(LAB).out '( 19.5 - 8 ) * 2 / 10 + 6'
	./$(LAB).out '5.75 * ( ( 23.9 - 8.9 ) + 2 ) * 9 / 7.5'
	./$(LAB).out '( 6 + 7.5 ) * ( ( 2 - 1.5 ) + 2.5 * 4 )'
	./$(LAB).out '( 5.5 + 3 ) * 2 - ( ( 0.5 / 0.25 ) + 39 * 10.5 - ( 3 + 2 + 4 ) )'
clean:
	rm *.out

