
#include "tests.h"

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
	printf("\n");
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
	printf("\n");
	printf("fd: %d\n", fd);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("\n");
	close(fd);
}

void	test_get_next_line_3_reading_one_newline(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/onenewline.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("\n");
	printf("fd: %d\n", fd);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("%p", str);
	printf("\n");
	close(fd);
}

void	test_get_next_line_4_try_to_read_closedfd(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/alphabet2.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("\n");
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	printf("\n");
}

void	test_get_next_line_5_read_empty_file(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/empty.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("\n");
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("%p", str);
	printf("\n");
	close(fd);
}

void	test_get_next_line_6_reading_2files(void)
{
	int		fd1;
	int		fd2;
	char	*str1;
	char	*str2;

	fd1 = open("./files_to_read/alphabet1.txt", O_RDONLY);
	if (fd1 == -1)
		perror("Error opening the file");
	printf("\n");
	printf("fd1: %d\n", fd1);
	str1 = get_next_line(fd1);
	printf("fd1: \"%s\"\n", str1);
	free(str1);
	fd2 = open("./files_to_read/texttoread.txt", O_RDONLY);
	close(fd1);
	printf("fd2: %d\n", fd2);
	str2 = get_next_line(fd2);
	printf("fd2: \"%s\"\n", str2);
	free(str2);
	str1 = get_next_line(fd1);
	printf("fd1: \"%s\"\n", str1);
	free(str1);
	printf("\n");
	close(fd2);
}

void	run_test_get_next_line(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_1_reading_file);
	RUN_TEST(test_get_next_line_2_reading_file);
	RUN_TEST(test_get_next_line_3_reading_one_newline);
	RUN_TEST(test_get_next_line_4_try_to_read_closedfd);
	RUN_TEST(test_get_next_line_5_read_empty_file);
	RUN_TEST(test_get_next_line_6_reading_2files);
	UNITY_END();
}