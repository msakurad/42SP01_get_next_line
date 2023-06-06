
#include "tests.h"

void	test_get_next_line_1_reading_file(void)
{
	int		fd;
	char	*str;

	fd = open("texttoread.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
	}
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
	}
	printf("\n");
	close(fd);
}

void	run_test_get_next_line(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_1_reading_file);
	UNITY_END();
}