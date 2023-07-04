
#include "tests.h"
#include "get_next_line.h"

void	test_get_next_line_1_reading_file(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/alphabet1.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
	}
	close(fd);
	free(str);
}

void	test_get_next_line_2_reading_file(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/alphabet2.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
}

void	test_get_next_line_3_reading_one_newline(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/onenewline.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("%p", str);
	close(fd);
}

void	test_get_next_line_4_try_to_read_closedfd(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/alphabet2.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
}

void	test_get_next_line_5_read_empty_file(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/empty.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("%p", str);
	close(fd);
}

void	run_test_get_next_line(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_1_reading_file);
	printf("\n----------------------------\n\n");
	RUN_TEST(test_get_next_line_2_reading_file);
	printf("\n----------------------------\n\n");
	RUN_TEST(test_get_next_line_3_reading_one_newline);
	printf("\n----------------------------\n\n");
	RUN_TEST(test_get_next_line_4_try_to_read_closedfd);
	printf("\n----------------------------\n\n");
	RUN_TEST(test_get_next_line_5_read_empty_file);
	printf("\n----------------------------\n\n");
	UNITY_END();
}