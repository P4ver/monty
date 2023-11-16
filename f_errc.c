#include "monty.h"
/**
 * err_c - funct will show err msg,
 * @cd_err: variable show err code,
 */
void err_c(int cd_err, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, cd_err);
	switch (cd_err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	lbr_nd();
	exit(EXIT_FAILURE);
}
/**
 * err_ktr - function that treats the err,
 * @cd_err: variable show err code,
 */
void err_ktr(int cd_err, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, cd_err);
	switch (cd_err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	lbr_nd();
	exit(EXIT_FAILURE);
}
