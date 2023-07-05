
#ifndef TESTS_H
# define TESTS_H

# include "unity.h"
# include "unity_internals.h"
# include <unistd.h> // read
# include <stdlib.h> // malloc free
# include <fcntl.h> // open
# include <stdio.h> // printf
# include <string.h>
# include <limits.h>

void	run_test_get_next_line(void);
void	run_test_get_next_line_bonus(void);

#define RUN_FT_TEST(id, ftname) \
	printf("\n-------------------------------\n\n"); \
	printf("\n\033[1;36mTESTE N%s: %s\033[0m\n\n", #id, #ftname); \
	RUN_TEST((ftname)); \

#endif
