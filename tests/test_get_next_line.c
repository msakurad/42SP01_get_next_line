
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
	printf("Reading file...\n");
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
	printf("fd: %d\n", fd);
	printf("Reading file...\n");
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
	printf("fd: %d\n", fd);
	printf("Reading file...\n");
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
	printf("fd: %d\n", fd);
	printf("Reading file...\n");
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	printf("\n");
	free(str);
}

void	test_get_next_line_5_read_empty_file(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/empty.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	printf("Reading file...\n");
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	printf("%p", str);
	printf("\n");
	close(fd);
}

void	test_get_next_line_6_try_to_read_fd_again(void)
{
	int		fd;
	char	*str;

	fd = open("./files_to_read/alphabet2.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	printf("Reading file...\n");
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
	fd = open("./files_to_read/alphabet2.txt", O_RDONLY);
	if (fd == -1)
		perror("Error opening the file");
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	printf("\n");
	free(str);
}

void	run_test_get_next_line(void)
{
	UNITY_BEGIN();
	RUN_FT_TEST(1, test_get_next_line_1_reading_file)
	RUN_FT_TEST(2, test_get_next_line_2_reading_file)
	RUN_FT_TEST(3, test_get_next_line_3_reading_one_newline)
	RUN_FT_TEST(4, test_get_next_line_4_try_to_read_closedfd)
	RUN_FT_TEST(5, test_get_next_line_5_read_empty_file)
	RUN_FT_TEST(6, test_get_next_line_6_try_to_read_fd_again)
	UNITY_END();
}