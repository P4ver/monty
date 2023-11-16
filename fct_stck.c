#include "monty.h"
/**
 * zidl_stck - funct that adds node,
 * @nwnd: pntr to pntr,
 * @k: integer,
 */
void zidl_stck(stack_t **nwnd, __attribute__((unused))unsigned int k)
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
	head = *nwnd;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * aff_stck - funct that add node,
 * @stck: pntr to pntr,
 * @k: integer num opcode,
 */
void aff_stck(stack_t **stck, unsigned int k)
{
	stack_t *tmp;

	(void) k;
	if (stck == NULL)
		exit(EXIT_FAILURE);
	tmp = *stck;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * foq_pp - funcitn that add node,
 * @stck: pntr to pntr,
 * @k: integer num opcode,
 */
void foq_pp(stack_t **stck, unsigned int k)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL)
		err_ktr(7, k);

	tmp = *stck;
	*stck = tmp->next;
	if (*stck != NULL)
		(*stck)->prev = NULL;
	free(tmp);
}
/**
 * foq_aff - functin that add node,
 * @stck: pntr to pntr,
 * @k: integer num opcode,
 */
void foq_aff(stack_t **stck, unsigned int k)
{
	if (stck == NULL || *stck == NULL)
		err_ktr(6, k);
	printf("%d\n", (*stck)->n);
}
