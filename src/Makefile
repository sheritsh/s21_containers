# /* created by Brilliance Storage Containers(BPA free) Team // sheritsh, bradamar, oznakban, melodiea ※ School 21, Kzn, 2023 */

TARGET = s21_containers.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++20 -lstdc++
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = testing_exe

all: test

clean:
	@echo "Deleting unnecessary files..."
	@rm -rf *.o *.a *.out *.log $(TEST_TARGET)

test: clean
	@$(CC) $(CFLAGS) tests/*.cc $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)

leaks: clean
	@$(CC) $(CFLAGS) tests/*.cc $(TEST_FLAGS) -o $(TEST_TARGET)
	leaks --atExit -- ./$(TEST_TARGET)

valgrind: clean
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" -v --verbose -q --quiet -s ./$(TEST_TARGET)

check_style:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@find . \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0 clang-format -n -style=Google

format_style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@find . \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0 clang-format -n -style=Google
