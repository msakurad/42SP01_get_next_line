
#include "tests.h"

void	test_get_next_line_1_reading_file(void)
{
	int		fd;
	char	*str;

	fd = open("alphabet1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
	}
	printf("check point 0\n");
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
	}
	printf("\n");
	close(fd);
	free(str);
}

void	test_get_next_line_2_reading_file(void)
{
	int		fd;
	char	*str;

	fd = open("alphabet2.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
	}
	// str = get_next_line(fd);
	// printf("%s", str);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("\n");
	close(fd);
}

void	run_test_get_next_line(void)
{
	UNITY_BEGIN();
	// RUN_TEST(test_get_next_line_1_reading_file);
	RUN_TEST(test_get_next_line_2_reading_file);
	UNITY_END();
}