#include "headers/main.h"

/**
 * add_line - add a new line to info.all_lines
 * by allocating a bigger block of memory
 * and freeing the current one
 */
void add_line(void)
{
	line_t *line = NULL;
	line_t **new_block = NULL;

	line = malloc(sizeof(line_t));
	if (!line)
		malloc_failed();

	line->size = get_argv();
	if (!line->size)
	{
		free(line);
		return;
	}
	info.line_cnt++;
	line->tokens = info.curr_tokens;
	info.curr_tokens = NULL;

	new_block = malloc(sizeof(line_t *) * (info.line_cnt + 1));
	if (!new_block)
		malloc_failed();

	memcpy(new_block, info.all_lines, sizeof(line_t *) * (info.line_cnt - 1));
	free(info.all_lines);
	new_block[info.line_cnt - 1] = line;
	new_block[info.line_cnt] = NULL;
	info.all_lines = new_block;
}
