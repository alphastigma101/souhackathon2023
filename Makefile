all: Poetry


Poetry:
	g++ -g -std=c++14 -g Poetry_On_Crack.cpp -Wall -Wextra -o Poetry_On_Crack.o


clean:
	rm -r *.o
