#include "monty.h"

void free_stack(stack_t *stack)
{
    while (stack)
    {
        stack_t *tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
void push(stack_t **stack, unsigned int line_number)
{
    extern FILE *file;

    char *arg = strtok(NULL, " \t\n");
    int value;
    stack_t *new_node;

    if (!arg || !isdigit(*arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(*stack);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*stack);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current;
    (void)line_number;

    current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
