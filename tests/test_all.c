#include "tests.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (1);
	printf("argv1 %s\n", argv[1]);
	if (!strcmp(argv[1], "bonus"))
	{
		printf("check-point 1\n");
		run_test_get_next_line_bonus();
	}
	else
	{
		printf("check-point 2\n");
		run_test_get_next_line();
	}
	return (0);
}
