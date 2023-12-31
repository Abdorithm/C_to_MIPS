#include "headers/main.h"
#include <stdio.h>

/**
 * overview - ..
 *
 * return: void
 */
void overview(void)
{
	int i;

	printf("\n/*****************************************************/\n"
			" *** \tMAPPING OF REGISTERS:\n"
			" *\n");
	for (i = 0; i < 4; i++)
	{
		if (info.reg_a[i].var != NULL)
			printf(" * [%s]\t%s ---> %d\n", info.reg_a[i].var, info.reg_a[i].name, info.reg_a[i].value);
	}

	for (i = 0; i < 8; i++)
	{
		if (info.reg_s[i].var != NULL)
			printf(" * [%s]\t%s ---> %d\n", info.reg_s[i].var, info.reg_s[i].name, info.reg_s[i].value);
	}

	for (i = 0; i < 10; i++)
	{
		if (info.reg_t[i].var != NULL)
			printf(" * [%s]\t%s ---> %d\n", info.reg_t[i].var, info.reg_t[i].name, info.reg_t[i].value);
	}
}

/**
 * credits - ..
 *
 * return: void
 */
void credits(void)
{
	printf("\n/*****************************************************/\n"
			" *** \tMIPSify - a C-to-MIPS parser\n"
			" *\n"
			" * MIPSify is a tool that converts C code to MIPS assembly language,\n"
			" * enabling developers to analyze and understand the MIPS assembly\n"
			" * representation of their C programs.\n"
			" *\n"
			" * copyright (c) 2023 computer & control dept.\n"
			" *\n"
			" * contributors: Abdelrahman Magdi, Youssef Elzedy, Eslam Samy,\n"
			" *               Mohamed Hamdy, Hazem Osama, Omar Essam\n"
			" *****************************************************/\n\n");
}


void ascii(void)
{
        printf(LIME);
        printf(" ███▄ ▄███▓ ██▓ ██▓███    ██████  ██▓  █████▒▓██   ██▓\n");
        printf("▓██▒▀█▀ ██▒▓██▒▓██░  ██▒▒██    ▒ ▓██▒▓██   ▒  ▒██  ██▒\n");
        printf("▓██    ▓██░▒██▒▓██░ ██▓▒░ ▓██▄   ▒██▒▒████ ░   ▒██ ██░\n");
        printf("▒██    ▒██ ░██░▒██▄█▓▒ ▒  ▒   ██▒░██░░▓█▒  ░   ░ ▐██▓░\n");
        printf("▒██▒   ░██▒░██░▒██▒ ░  ░▒██████▒▒░██░░▒█░      ░ ██▒▓░\n");
        printf("░ ▒░   ░  ░░▓  ▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░░▓   ▒ ░       ██▒▒▒ \n");
        printf("░  ░      ░ ▒ ░░▒ ░     ░ ░▒  ░ ░ ▒ ░ ░       ▓██ ░▒░ \n");
        printf("░      ░    ▒ ░░░       ░  ░  ░   ▒ ░ ░ ░     ▒ ▒ ░░  \n");
        printf("       ░    ░                 ░   ░           ░ ░      \n");
        printf("                                              ░ ░      \n");
        printf(RESET);
        printf(CYAN);
        printf(" ███▄ ▄███▓ ██▓ ██▓███    ██████  ██▓  █████▒▓██   ██▓\n");
        printf("▓██▒▀█▀ ██▒▓██▒▓██░  ██▒▒██    ▒ ▓██▒▓██   ▒  ▒██  ██▒\n");
        printf("▓██    ▓██░▒██▒▓██░ ██▓▒░ ▓██▄   ▒██▒▒████ ░   ▒██ ██░\n");
        printf("▒██    ▒██ ░██░▒██▄█▓▒ ▒  ▒   ██▒░██░░▓█▒  ░   ░ ▐██▓░\n");
        printf("▒██▒   ░██▒░██░▒██▒ ░  ░▒██████▒▒░██░░▒█░      ░ ██▒▓░\n");
        printf("░ ▒░   ░  ░░▓  ▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░░▓   ▒ ░       ██▒▒▒ \n");
        printf("░  ░      ░ ▒ ░░▒ ░     ░ ░▒  ░ ░ ▒ ░ ░       ▓██ ░▒░ \n");
        printf("░      ░    ▒ ░░░       ░  ░  ░   ▒ ░ ░ ░     ▒ ▒ ░░  \n");
        printf("       ░    ░                 ░   ░           ░ ░      \n");
        printf("                                              ░ ░      \n");
        printf(RESET);
        printf(LIGHTRED);
        printf(" ███▄ ▄███▓ ██▓ ██▓███    ██████  ██▓  █████▒▓██   ██▓\n");
        printf("▓██▒▀█▀ ██▒▓██▒▓██░  ██▒▒██    ▒ ▓██▒▓██   ▒  ▒██  ██▒\n");
        printf("▓██    ▓██░▒██▒▓██░ ██▓▒░ ▓██▄   ▒██▒▒████ ░   ▒██ ██░\n");
        printf("▒██    ▒██ ░██░▒██▄█▓▒ ▒  ▒   ██▒░██░░▓█▒  ░   ░ ▐██▓░\n");
        printf("▒██▒   ░██▒░██░▒██▒ ░  ░▒██████▒▒░██░░▒█░      ░ ██▒▓░\n");
        printf("░ ▒░   ░  ░░▓  ▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░░▓   ▒ ░       ██▒▒▒ \n");
        printf("░  ░      ░ ▒ ░░▒ ░     ░ ░▒  ░ ░ ▒ ░ ░       ▓██ ░▒░ \n");
        printf("░      ░    ▒ ░░░       ░  ░  ░   ▒ ░ ░ ░     ▒ ▒ ░░  \n");
        printf("       ░    ░                 ░   ░           ░ ░      \n");
        printf("                                              ░ ░      \n");
        printf(RESET);
}
