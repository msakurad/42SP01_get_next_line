

# Directories
PATH_SRC := ./srcs/
PATH_TEST := ./tests/
PATH_INCLUDES := ./includes/
PATH_UNITY := ./Unity/src

INCLUDES := -I $(PATH_SRC) -I $(PATH_TEST) -I $(PATH_INCLUDES) -I $(PATH_UNITY)

# Files
SRCS_FILES := *.c
SRCS := $(addprefix $(PATH_SRC), $(SRCS_FILES))
TESTS_FILES := test_get_next_line.c
TESTS := $(addprefix $(PATH_TEST), $(TESTS_FILES))
UNITY = $(PATH_UNITY)unity.c
EXECUTABLE := ./a.out

# FLAGS
CC_FLAGS = -O2 -Wall -Wextra -Werror

all:
	cc $(CC_FLAGS) $(SRCS) $(TESTS) $(UNITY) $(INCLUDES)
	$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)

fclean: clean

re: fclean all
