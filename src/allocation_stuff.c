#include "headers/main.h"

/**
 * add_line - add a new line to info.all_lines
 * by allocating a bigger block of memory
 * and freeing the current one
 */
void add_line(void)
{
	line_t *line;
	line_t **new_block;

	/* setup the new line */
	line = malloc(sizeof(line_t));
	if (!line)
		malloc_failed();

	line->size = get_argv();
	if (!line->size)
	{
		free(line);
		return;
	}
	line->tokens = info.curr_tokens;
	info.curr_tokens = NULL;

	if (!info.line_cnt)
		info.all_lines = malloc(sizeof(line_t *));
	else if (__builtin_popcount(info.line_cnt) == 1)
	{

		new_block = malloc(sizeof(line_t *) * (info.line_cnt * 2));
		/* just for testing */
		printf("WEEe a new Memory Block, Line: %lu\n", info.line_cnt);
		if (!new_block)
			malloc_failed();
		memcpy(new_block, info.all_lines, sizeof(line_t *) * (info.line_cnt));
		free(info.all_lines);
		info.all_lines = new_block;
	}

	info.all_lines[info.line_cnt] = line;
	info.line_cnt++;

}
