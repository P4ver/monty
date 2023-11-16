#include "monty.h"
stack_t *head = NULL;
/**
 * swb_nd - funct that creats a node,
 * @q: integer,
 * Return: return node,
 */
stack_t *swb_nd(int q)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_c(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 * lbr_nd - function that frees in stck,
 */
void lbr_nd(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
/**
 * main - the entry point,
 * @argc: arg cnt,
 * @argv: lst of arg,
 * Return: always 0,
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fth_fl(argv[1]);
	lbr_nd();
	return (0);
}
/**
 * zid_queue - funct adds node,
 * @nwnd: pntr to pntr,
 * @k: num of opcode,
 */
void zid_queue(stack_t **nwnd, __attribute__((unused))unsigned int k)
{
	stack_t *tmp;

	if (nwnd == NULL || *nwnd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nwnd;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *nwnd;
	(*nwnd)->prev = tmp;
}
