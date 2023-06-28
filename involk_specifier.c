#include"main.h"
/**
 * get_specifier - get specifier function
 * @s: character specifier
 * Return: a function that takes two arguments
 * of va_list type and pointer to function
*/
void (*get_specifier(char s))(va_list *, int *)
{
	spec_op specs[] = {
		{'c', spec_c},
		{'s', spec_s},
		{'%', spec_per},
		{'d', spec_d},
		{'i', spec_i},
		{'b', spec_b},
		{'\0', NULL}
	};
	int j;

	j = 0;
	while (specs[j].sp)
	{
		if (specs[j].sp == s)
		{
			return (specs[j].f);
		}
		j++;
	}
	return (specs[j].f);
}
