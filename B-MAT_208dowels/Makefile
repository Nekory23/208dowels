##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

## Var def ##
SHELL		=	/bin/sh
CC			=	gcc
CPP			=	g++
RM			=	rm -f
#############

## Sources ##
MAIN		=	src/main.c

BIN_SRC		=	src/start.c				\
				src/error_handling.c	\
				src/dowels.c			\
				src/display_results.c	\

TEST_SRC	=	tests/test_error.c			\
				tests/test_displayhelp.c	\
				tests/test_returnvalues.c	\

INC			=	-I./include/
#############

##	Obj	   ##
MAIN_OBJ	=	$(MAIN:.c=.o)
SRC_OBJ		=	$(BIN_SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
#############

##	Flags  ##
CFLAGS		=	-Wall -Wextra -Werror -lm
CPPFLAGS	=	$(INC)
LDFLAGS		=	-lm
#############

##	Names  ##
BIN			=   208dowels
TEST_BIN	=	unit_tests
#############

##	Rules  ##
all:	$(MAIN_OBJ) $(SRC_OBJ)
	@$(CC) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(BIN) | tr ' ' '.'

# Debug
debug:	fclean
debug:	CFLAGS += -g3 -DDEBUG
debug:	all

# Unit Test
tests_run:	fclean
tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(SRC_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_BIN) $(BIN_SRC) $(TEST_SRC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(TEST_BIN)

# Coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

# Clear
clean:
	@$(RM) $(MAIN_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'
	@$(RM) $(SRC_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SRC_OBJ) | tr ' ' '.'
	@$(RM) $(TEST_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_OBJ) | tr ' ' '.'

fclean: clean
	@$(RM) $(BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(BIN) | tr ' ' '.'
	@$(RM) $(TEST_BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_BIN) | tr ' ' '.'
	@$(RM) */*.gc* *.gc*

# re
re : fclean all

# PHONY
.PHONY: all debug tests_run coverage clean fclean re