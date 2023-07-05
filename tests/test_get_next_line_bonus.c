
#include "tests.h"
#include "get_next_line_bonus.h"

void	test_get_next_line_bonus_1_reading_file(void)
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

void	test_get_next_line_bonus_2_reading_file(void)
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

void	test_get_next_line_bonus_3_reading_one_newline(void)
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

void	test_get_next_line_bonus_4_try_to_read_closedfd(void)
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

void	test_get_next_line_bonus_5_read_empty_file(void)
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

void	test_get_next_line_bonus_6_try_to_read_fd_again(void)
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

void	test_get_next_line_bonus_7_reading_2files(void)
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
	printf("fd2: %d\n", fd2);
	str2 = get_next_line(fd2);
	printf("fd2: \"%s\"\n", str2);
	free(str2);
	str1 = get_next_line(fd1);
	printf("fd1: \"%s\"\n", str1);
	free(str1);
	printf("\n");
	close(fd1);
	close(fd2);
}

void	run_test_get_next_line_bonus(void)
{
	UNITY_BEGIN();
	RUN_FT_TEST(1, test_get_next_line_bonus_1_reading_file)
	RUN_FT_TEST(2, test_get_next_line_bonus_2_reading_file)
	RUN_FT_TEST(3, test_get_next_line_bonus_3_reading_one_newline)
	RUN_FT_TEST(4, test_get_next_line_bonus_4_try_to_read_closedfd)
	RUN_FT_TEST(5, test_get_next_line_bonus_5_read_empty_file)
	RUN_FT_TEST(6, test_get_next_line_bonus_6_try_to_read_fd_again)
	RUN_FT_TEST(7, test_get_next_line_bonus_7_reading_2files)
	UNITY_END();
}
