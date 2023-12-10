#include "headers/main.h"
#include "headers/init.h"

all_reg regs = INIT_REGS;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	char **tokens;
	FILE *file;
	size_t size = 0;
	ssize_t cntr_line = 1;
	unsigned int counter = 0;

	/*check if the file name is already exist or not*/
	if (argc != 2)
	{
                printf("Usage: ./mipsify <file name>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*read line by line*/
        while (cntr_line > 0)
	{
		content = NULL;
		cntr_line = getline(&content, &size, file);
		tokens = get_argv(content);
		
		counter++;

	}
	/* exist */
	fclose(file);
	overview();
	credits();

	return (0);
}
