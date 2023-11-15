#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <monty.h>

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char line[1024];
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *opcode;
            line_number++;

        opcode = strtok(line, " \t\n");
        if (opcode)
        {
            instruction_t instructions[] = {
                {"push", push},
                {"pall", pall},
                {"", NULL}};

            int i = 0;
            while (instructions[i].opcode[0])
            {
                if (strcmp(instructions[i].opcode, opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
                i++;
            }

            if (!instructions[i].opcode[0])
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free_stack(stack);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    free_stack(stack);
    fclose(file);

    return EXIT_SUCCESS;
}
