#################################################################
# Makefile to Automate the compilation and execute the code	#
# 1. make 	to compile					#
# 2. make run	to execute the simple shell			#
# 3. make clean to clean the previous compiled			#
# 4. make mleak to execute valgrind and check memory leaks	#
#################################################################

all:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

run:
	./hsh

clean:
	rm hsh
mleak:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh
