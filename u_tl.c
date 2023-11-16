#include "monty.h"
/**
 * fth_fl - funct that opens files,
 * @flnm:var of file name,
 */
void fth_fl(char *flnm)
{
	FILE *pf = fopen(flnm, "r");

	if (flnm == NULL || pf == NULL)
		err_c(2, flnm);

	lr_fl(pf);
	fclose(pf);
}
/**
 * lr_fl - funct that read file,
 * @pf: pntr to file,
 */
void lr_fl(FILE *pf)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, pf) != -1; line_number++)
	{
		format = ana_ln(buffer, line_number, format);
	}
	free(buffer);
}
/**
 * ana_ln - turn line to token,
 * @bfr: pointer,
 * @k: integer,
 * @jrm: enter as a stask if is null,
 * Return: 0 or 1,
 */
int ana_ln(char *bfr, int k, int jrm)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (bfr == NULL)
		err_c(4);

	opcode = strtok(bfr, delim);
	if (opcode == NULL)
		return (jrm);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	trv_fct(opcode, value, k, jrm);
	return (jrm);
}
/**
 * trv_fct - find funct for opcode,
 * @opcode: opcode,
 * @argop: opc argument,
 * @k: integer,
 * @jrm: enter as a stack if node is null,
 */
void trv_fct(char *opcode, char *argop, int k, int jrm)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", zidl_stck},
		{"pall", aff_stck},
		{"pint", foq_aff},
		{"pop", foq_pp},
		{"nop", np_d},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			apl_fct(func_list[i].f, opcode, argop, k, jrm);
			flag = 0;
		}
	}
	if (flag == 1)
		err_c(3, k, opcode);
}
/**
 * apl_fct - funct that calls required func,
 * @fct: pntr,
 * @opc: var string,
 * @nmvl: strinf value,
 * @k: integer,
 * @jrm: enter as stack if node is null,
 */
void apl_fct(op_func fct, char *opc, char *nmvl, int k, int jrm)
{
	stack_t *node;
	int flg;
	int q;

	flg = 1;
	if (strcmp(opc, "push") == 0)
	{
		if (nmvl != NULL && nmvl[0] == '-')
		{
			nmvl = nmvl + 1;
			flg = -1;
		}
		if (nmvl == NULL)
			err_c(5, k);
		for (q = 0; nmvl[q] != '\0'; q++)
		{
			if (isdigit(nmvl[q]) == 0)
				err_c(5, k);
		}
		node = swb_nd(atoi(nmvl) * flg);
		if (jrm == 0)
			fct(&node, k);
		if (jrm == 1)
			zid_queue(&node, k);
	}
	else
		fct(&head, k);
}
