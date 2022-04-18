#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
		case '-':
			f->minus = 1;
			i = 1;
			break;
		case '0':
			f->zero = 1;
			i = 1;
			break;
	}

	return (i);
}
/**
 * get_modifier - finds the modifier and invokes corresponding func
 * @s: format string
 * @handler: handler struct
 *
 *Return: 1 if modifier is valid
 */
int get_modifier(char *s, han_s *handler)
{
	int i = 0;

	switch (s)
	{
	case 'h':
		i = 1;
		handler->h_mod = 1;
		break;
	case 'l':
		i = 1;
		handler->l_mod = 1;
		break;
	}
	return (i);
}
/**
 * get_width - gets width from a width specifier
 * @s: format string
 * @handler: struct
 * @list: list to increment
 *
 * Return: string
 */
char *get_width(char *s, han_s handler, va_list list)
{
	int width = 0;

	if (*s == '*')
	{
		width = va_arg(list, int);
		s++;
	}
	else
	{
		while (*s >= 0 && *s <= 9)
		{
			width = width * 10 + (*s++ - '0');
		}
	}
	handler->width = width;
	return (s);
}
