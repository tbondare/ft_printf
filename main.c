#include "libftprintf.h"
#include <stdio.h>

void tests()
{
	ft_printf("Hello %%!");
	printf("\nHello %%!\n\n");

	ft_printf("%f", 15.45);
	printf("\n1 = %f\n\n", 15.45);

	ft_printf("%f", 0.15);
	printf("\n2 = %f\n\n", 0.15);
}
int main()
{
	setlocale(LC_ALL, "");
//	tests();
	ft_printf("%ls", L"αρχη");
	printf("\n%ls", L"αρχη");
//	ft_printf("%f", 15.45);
//	printf("\n1 = %f\n\n", 15.45);
	return (0);
}
