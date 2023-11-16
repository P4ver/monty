#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void fth_fl(char *file_name);
int ana_ln(char *buffer, int line_number, int format);
void lr_fl(FILE *);
/*
int len_chars(FILE *);
*/
void trv_fct(char *, char *, int, int);

stack_t *swb_nd(int n);
void lbr_nd(void);
void aff_stck(stack_t **, unsigned int);
void zidl_stck(stack_t **, unsigned int);
void zid_queue(stack_t **, unsigned int);

void apl_fct(op_func func, char *op, char *val, int ln, int format);

void foq_aff(stack_t **, unsigned int);
void foq_pp(stack_t **, unsigned int);
/*
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
*/
void err_c(int error_code, ...);
void err_ktr(int error_code, ...);
/*
void string_err(int error_code, ...);
*/
#endif
