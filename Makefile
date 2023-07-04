
# Directories
PATH_SRC := ./srcs/
PATH_TEST := ./tests/
PATH_INCLUDES := ./includes/
PATH_UNITY := ./Unity/src

INCLUDES_MANDAT := -I $(PATH_SRC) -I $(PATH_TEST) -I $(PATH_INCLUDES) -I $(PATH_UNITY)
INCLUDES_BONUS := -I $(PATH_SRC) -I $(PATH_TEST) -I $(PATH_INCLUDES) -I $(PATH_UNITY)

# Files
SRCS_FILES := get_next_line.c get_next_line_utils.c
SRCS := $(addprefix $(PATH_SRC), $(SRCS_FILES))
SRCS_FILES_BONUS := get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_BONUS := $(addprefix $(PATH_SRC), $(SRCS_FILES_BONUS))
TESTS_FILES := test_all.c test_get_next_line.c
TESTS := $(addprefix $(PATH_TEST), $(TESTS_FILES))
UNITY = $(PATH_UNITY)/unity.c
EXECUTABLE := ./a.out

# FLAGS
CC_FLAGS = -O2 -Wall -Wextra -Werror

# cc -Wall -Wextra -Werror 
all:
	cc $(CC_FLAGS) $(SRCS) $(TESTS) $(UNITY) $(INCLUDES_MANDAT)
	$(EXECUTABLE)

+%:
	cc $(CC_FLAGS) -D BUFFER_SIZE=$@ $(SRCS) $(TESTS) $(UNITY) $(PATH_SRC)get_next_line.h $(INCLUDES_MANDAT)
	$(EXECUTABLE)

bonuss:
	cc $(CC_FLAGS) $(SRCS_BONUS) $(TESTS) $(UNITY) $(INCLUDES_BONUS)
	$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)

fclean: clean

re: fclean all
