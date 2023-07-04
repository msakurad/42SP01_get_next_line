
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

#endif
