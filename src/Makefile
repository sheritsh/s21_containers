all: test

clean:
	@rm -rf *.o *.a *.out test

test: clean
	@gcc -Wall -Werror -Wextra -lstdc++ -std=c++20 -lgtest tests/*.cc -o test
	./test

leaks: clean
	@gcc -Wall -Werror -Wextra -lstdc++ -std=c++20 -lgtest tests/*.cc -o test
	leaks --atExit -- ./test
