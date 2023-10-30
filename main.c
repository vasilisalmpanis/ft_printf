#include "ft_printf.h"
#include <stdio.h>


int main()
{
	int	*ptr;
	int	a;

	a = 10;
	ptr = &a;

	ft_printf("%d\n", 1234);
	printf("%d\n", 1234);
	ft_printf("%p\n", "0");
	printf("%p\n", "0");
	ft_printf(" %u\n", -1);
	printf(" %u\n", -1);
	ft_printf(" %%%\n");
	// printf(" %%%\n");
	ft_printf(" %p %p \n", 0, 0);
	//printf(" %p %p \n", 0, 0);
	return(0);
}