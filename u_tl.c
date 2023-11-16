#include "monty.h"
void fth_fl(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err_c(2, file_name);

	lr_fl(fd);
	fclose(fd);
}
void lr_fl(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = ana_ln(buffer, line_number, format);
	}
	free(buffer);
}
int ana_ln(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err_c(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	trv_fct(opcode, value, line_number, format);
	return (format);
}

void trv_fct(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", zidl_stck},
		{"pall", aff_stck},
		{"pint", foq_aff},
		{"pop", foq_pp},
		/*{"nop", nop},
		{"swap", swap_nodes},*/
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			apl_fct(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err_c(3, ln, opcode);
}

void apl_fct(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err_c(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_c(5, ln);
		}
		node = swb_nd(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			zid_queue(&node, ln);
	}
	else
		func(&head, ln);
}
