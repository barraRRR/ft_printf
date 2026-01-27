#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	void	*p;

	ft_printf("Pues parece que ya he terminado el proyecto.\n p: %p\n", p);
	ft_printf("s: %s\n", "hello world");
	ft_printf("d: %d\n", 1923);
	ft_printf("i: %i\n", INT_MIN);
	ft_printf("u: %u\n", -42);
	ft_printf("u: %u\n", INT_MAX);
	ft_printf("x: %x\n", 34);
	ft_printf("X: %X\n", 42069193);
	ft_printf("%%:\n");

	return (0);
}