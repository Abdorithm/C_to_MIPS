#include "headers/main.h"
#include "headers/init.h"

info_t info = INIT_REGS;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	size_t size = 0;
	ssize_t cntr_line = 1;

	/*check if the file name is already exist or not*/
	if (argc != 2)
	{
		printf("Usage: ./mipsify <file name>\n");
		exit(EXIT_FAILURE);
	}
	info.file = fopen(argv[1], "r");
	if (!info.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*read line by line*/
	while (cntr_line > 0)
	{
		cntr_line = getline(&info.content, &size, info.file);
		if (cntr_line == EOF)
		{
			free(info.content);
			break;
		}
		info.tokens = get_argv(info.content);
		free_2d(info.tokens);

	}
	/* exist */
	free_all();
	overview();
	credits();

	return (0);
}
