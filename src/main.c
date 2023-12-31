#include "headers/main.h"
#include "headers/init.h"

info_t info = INIT_INF;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	size_t len = 1, i;
	ssize_t read = 1;

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
	while (read)
	{
		read = getline(&info.curr_line, &len, info.file);
		if (read == EOF)
			break;
		add_line();
	}

    for (i = 0; i < info.line_cnt; i++)
    {
    	i = decision(i);
		i--;
    }
	/* exist */
	printf("\n");
    overview();
    credits();
	free_all();
	printf("\n");
	ascii();
	return (0);
}
