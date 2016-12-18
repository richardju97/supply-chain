all:
	gcc -Wall -Werror -g -o main main.c supply-chain.c

clean:
	rm *.out
