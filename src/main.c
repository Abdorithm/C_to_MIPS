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
	size_t len = 1;
	ssize_t read = 1;
	notUsed	size_t i, j;

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
	/*
	put_in_register("a", 0, 's');
	put_in_register("5", 5, 't');
	put_in_register("10", 10, 't');
	printf("%s %s %d\n",return_reg("5", 't').name, return_reg("5", 't').var ,return_reg("5", 't').value);
	printf("%s %s %d\n",return_reg("10", 't').name, return_reg("10", 't').var ,return_reg("10", 't').value);
	*/
	while_loop(0);
	/* just for testing */
	/*
	for (i = 0; i < info.line_cnt; i++)
	{
		for (j = 0; j < info.all_lines[i]->size; j++)
			printf("%s ", info.all_lines[i]->tokens[j]);
		printf("\n");
	}
	*/
	/* exist */
	free_all();

	return (0);
}
