#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // TODO: Read and process the file line by line
    // TODO: Implement the Monty interpreter logic

    fclose(file);
    return EXIT_SUCCESS;
}

