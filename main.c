#include "headers/main.h"

all_reg regs = {
	{
		{"$s0", 0, NULL},
		{"$s1", 0, NULL},
		{"$s2", 0, NULL},
		{"$s3", 0, NULL},
		{"$s4", 0, NULL},
		{"$s5", 0, NULL},
		{"$s6", 0, NULL},
		{"$s7", 0, NULL}
	},
	{
		{"$a0", 0, NULL},
		{"$a1", 0, NULL},
		{"$a2", 0, NULL},
		{"$a3", 0, NULL}
	},
	{
		{"$t0", 0, NULL},
		{"$t1", 0, NULL},
		{"$t2", 0, NULL},
		{"$t3", 0, NULL},
		{"$t4", 0, NULL},
		{"$t5", 0, NULL},
		{"$t6", 0, NULL},
		{"$t7", 0, NULL},
		{"$t8", 0, NULL},
		{"$t9", 0, NULL}
	},
	{
		{"$v0", 0, NULL},
		{"$v1", 0, NULL}
	},
	{"$zero", 0, NULL}
};

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t cntr_line = 1;
	unsigned int counter = 0;

	/*check if the file name is already exist or not*/
	if (argc != 2)
	{
		printf("Write the file name and try again\n");
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
		counter++;
		if (cntr_line > 0)
		{
			readline(content, counter, file);
		}
		free(content);
	}
	fclose(file);
	return (0);
}
