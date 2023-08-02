all: clean
	gcc -Wall -Werror -Wextra -std=c++17 -O3 -lstdc++ stack.cc

clean:
	@echo "Deleting unnecessary files..."
	@rm -rf *.o *.a a.out test

test: clean
	gcc -Wall -Werror -Wextra -lstdc++ -std=c++17 -lgtest tests.cc -o test
