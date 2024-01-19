#include "monty.h"

/**
 * process_file - Read and process the Monty byte code file line by line
 * @filename: Name of the file to process
 */
void process_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL; // Assume a global stack variable

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        process_line(line, &stack, line_number);
    }

    free(line);
    fclose(file);
}

/**
 * process_line - Process a line of Monty byte code
 * @line: Line of Monty byte code to process
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode, *arg;
    int value;

    opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");
        if (arg == NULL)
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        value = atoi(arg);
        if (!is_valid_integer(arg, value))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        push(stack, value);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(*stack);
    }
    // Add more opcodes as needed
}

/**
 * is_valid_integer - Check if a string is a valid integer
 * @str: String to check
 * @value: Pointer to store the integer value
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_integer(const char *str, int *value)
{
    char *endptr;
    *value = strtol(str, &endptr, 10);

    // Check for conversion errors
    if (*endptr != '\0')
        return 0;

    return 1;
}

