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

	ft_printf("%ls", L"αρχη");
	printf("\n%ls", L"αρχη");

	ft_printf("%f", 15.45);
	printf("\n1 = %f\n\n", 15.45);

	ft_printf("%f", 19.9999999);
	printf("\n1 = %f\n\n", 19.9999999);

	ft_printf("%d", 1545);
	printf("\n%d\n\n", 1545);

	ft_printf("%p", 0x25f);
	printf("\n%p\n\n", 0x25f);

	ft_printf("%p%d", 0x25f, 25);
	printf("\n%p%d\n\n", 0x25f, 25);

	ft_printf("1 = %f!\n", 15.45);
	printf("1 = %f!\n\n", 15.45);

	ft_printf("1 = %f %d!\n", 15.45, 25);
	printf("1 = %f %d!\n\n", 15.45, 25);

	ft_printf("%o\n", 056);
	printf("%o\n\n", 056);

	ft_printf("%i\n", 46);
	printf("%i\n\n", 46);

	ft_printf("%u\n", -36);
	printf("%u\n\n", -36);

	ft_printf("%x\n", 0x56f);
	printf("%x\n\n", 0x56f);

	int len1 = ft_printf("%x\n", 0x56f);
	int len2 = printf("%x\n", 0x56f);
	ft_printf("%d\n%d\n", len1, len2);

	int len01 = ft_printf("%d\n", 0);
	int len02 = printf("%d\n", 0);
	ft_printf("%d\n%d\n", len01, len02);

	ft_printf("%x\n", -22);
	printf("%x\n\n", -22);

	ft_printf("%x\n", 22);
	printf("%x\n\n", 22);

}
int main()
{
	setlocale(LC_ALL, "");
//	tests();

	int len1 = ft_printf("%c\n", 'f');
	int len2 = printf("%c\n\n", 'f');
	ft_printf("%d\n%d\n", len1, len2);

	return (0);
}
