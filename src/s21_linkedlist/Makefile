all: clean
	@gcc -Wall -Werror -Wextra -std=c++17 -O3 -lstdc++ list.cc

clean:
	@rm -rf *.o *.a a.out test

test: clean
	@gcc -Wall -Werror -Wextra -lstdc++ -std=c++17 -lgtest tests.cc -o test
	./test

leaks: clean
	@gcc -Wall -Werror -Wextra -lstdc++ -std=c++17 -lgtest tests.cc -o test
	leaks --atExit -- ./test