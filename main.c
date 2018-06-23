#include "libftprintf.h"
#include <stdio.h>

void tests()
{
	ft_printf("Hello %%!");
	printf("\nHello %%!\n\n");

	ft_printf("1 = %f", 15.45);
	printf("\n1 = %f\n\n", 15.45);

	ft_printf("2 = %f", 0.15);
	printf("\n2 = %f\n\n", 0.15);

	ft_printf("%ls", L"αρχη");
	printf("\n%ls\n\n", L"αρχη");

	ft_printf("1 = %f", 15.45);
	printf("\n1 = %f\n\n", 15.45);

	ft_printf("1 = %f", 19.9999999);
	printf("\n1 = %f\n\n", 19.9999999);

	ft_printf("%d", 1545);
	printf("\n%d\n\n", 1545);

	ft_printf("%p", 0x25f);
//	printf("\n%p\n\n", 0x25f);

	ft_printf("%p%d", 0x25f, 25);
//	printf("\n%p%d\n\n", 0x25f, 25);

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
	ft_printf("%d%d\n\n", len1, len2);

	int len01 = ft_printf("%d\n", 0);
	int len02 = printf("%d\n", 0);
	ft_printf("%d%d\n\n", len01, len02);

	ft_printf("%x\n", -22);
	printf("%x\n\n", -22);

	ft_printf("%x\n", 22);
	printf("%x\n\n", 22);

	ft_printf("%5%\n");
	printf("%5%\n\n");

	ft_printf("%x\n", 0);
	printf("%x\n\n", 0);

	ft_printf("%X\n", 0);
	printf("%X\n\n", 0);

	ft_printf("%x\n", 4294967296);
//	printf("%x\n\n", 4294967296);

	ft_printf("%X\n", 4294967296);
//	printf("%X\n\n", 4294967296);

	ft_printf("%hx\n", 4294967296);
//	printf("%hx\n\n", 4294967296);

	ft_printf("%hhX\n", 4294967296);
//	printf("%hhX\n\n", 4294967296);

	ft_printf("%#x\n", 42);
	printf("%#x\n\n", 42);

	ft_printf("%#llx\n", 9223372036854775807);
//	printf("%#llx\n\n", 9223372036854775807);

	ft_printf("%#x\n", 0);
	printf("%#x\n\n", 0);

	ft_printf("%#X\n", 42);
	printf("%#X\n\n", 42);

	ft_printf("%#8x\n", 42);
	printf("%#8x\n\n", 42);

	ft_printf("%#08x\n", 42);
	printf("%#08x\n\n", 42);

	ft_printf("%#-08x\n", 42);
//	printf("%#-08x\n\n", 42);

	ft_printf("%-10s is a string\n", "");
	printf("%-10s is a string\n\n", "");

	ft_printf("%s\n", "abc");
	printf("%s\n\n", "abc");

	ft_printf("%10s is a string\n", "this");
	printf("%10s is a string\n\n", "this");

	ft_printf("%.2s is a string\n", "this");
	printf("%.2s is a string\n\n", "this");

	ft_printf("%10s is a string\n", "this");
	printf("%10s is a string\n\n", "this");

	ft_printf("%s\n", "abc");
	printf("%s\n\n", "abc");

	ft_printf("%5.2s is a string\n", "this");
	printf("%5.2s is a string\n\n", "this");

	ft_printf("%.2s is a string\n", "this");
	printf("%.2s is a string\n\n", "this");

	ft_printf("%10s is a string\n", "");
	printf("%10s is a string\n\n", "");

	ft_printf("%5.2s is a string\n", "");
	printf("%5.2s is a string\n\n", "");

	ft_printf("%-5.2s is a string\n", "this");
	printf("%-5.2s is a string\n\n", "this");

	ft_printf("%-5.2s is a string\n", "");
	printf("%-5.2s is a string\n\n", "");

	ft_printf("%#6o\n", 2500);
	printf("%#6o\n\n", 2500);

	ft_printf("@moulitest: %s\n", NULL);
	printf("@moulitest: %s\n\n", NULL);

	//	ft_printf("%x\n", test);
	//	printf("%x\n\n", test);

	ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
//	printf("%s %s %s %s string. gg!\n\n", "this", "is", "a", "multi", "string");

	ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	printf("%s%s%s%s%s\n\n", "this", "is", "a", "multi", "string");

	ft_printf("%s %s\n", NULL, "string");
	printf("%s %s\n\n", NULL, "string");

	ft_printf("%-#6o\n", 2500);
	printf("%-#6o\n\n", 2500);

	ft_printf("@moulitest: %o\n", 0);
	printf("@moulitest: %o\n\n", 0);

	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("@moulitest: %#.o %#.0o\n\n", 0, 0);

	ft_printf("%c\n", 42);
	printf("%c\n\n", 42);

	len1 = ft_printf("%c\n", 'f');
	len2 = printf("%c\n", 'f');
	ft_printf("%d\n%d\n\n", len1, len2);

	ft_printf("%5c\n", 42);
	printf("%5c\n\n", 42);

	ft_printf("%-5c\n", 42);
	printf("%-5c\n\n", 42);

//	ft_printf("%lld\n", -9223372036854775808);
//	printf("%lld\n\n", -9223372036854775808);

//	ft_printf("%jd\n", -9223372036854775808);
//	printf("%jd\n\n", -9223372036854775808);

	ft_printf("%10.5d\n", 4242);
	printf("%10.5d\n\n", 4242);

	ft_printf("%+10.5d\n", 4242);
	printf("%+10.5d\n\n", 4242);

	ft_printf("% 10.5d\n", 4242);
	printf("% 10.5d\n\n", 4242);

	ft_printf("%03.2d\n", 0);
	printf("%03.2d\n\n", 0);

	ft_printf("%03.2d\n", 1);
	printf("%03.2d\n\n", 1);

	ft_printf("%03.2d\n", -1);
	printf("%03.2d\n\n", -1);

	ft_printf("@moulitest: %.d %.0d\n", 0, 0);
	printf("@moulitest: %.d %.0d\n\n", 0, 0);

	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	printf("@moulitest: %5.d %5.0d\n\n", 0, 0);

	ft_printf("%u\n", 0);
	printf("%u\n\n", 0);

	ft_printf("%u\n", 4294967296);
//	printf("%u\n\n", 4294967296);

	ft_printf("% u\n", 4294967295);
	ft_printf("% u\n\n", 4294967295);

	ft_printf("%+u\n", 4294967295);
	ft_printf("%+u\n\n", 4294967295);

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n\n", 0, 0);

	ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	printf("@moulitest: %.x %.0x\n\n", 0, 0);

	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("@moulitest: %5.x %5.0x\n\n", 0, 0);

	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	printf("@moulitest: %.o %.0o\n\n", 0, 0);

	ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
	printf("@moulitest: %5.o %5.0o\n\n", 0, 0);

	ft_printf("%4.15d\n", 42);
	printf("%4.15d\n\n", 42);

	ft_printf("%.10d\n", 4242);
	printf("%.10d\n\n", 4242);

	ft_printf("%-10.5d\n", 4242);
	printf("%-10.5d\n\n", 4242);

	ft_printf("%-+10.5d\n", 4242);
	printf("%-+10.5d\n\n", 4242);

	ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	printf("@moulitest: %.d %.0d\n\n", 42, 43);

	ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
	printf("@moulitest: %5.o %5.0o\n\n", 0, 0);

	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("@moulitest: %#.o %#.0o\n\n", 0, 0);

	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	printf("@moulitest: %5.d %5.0d\n\n", 0, 0);

	ft_printf("% u\n", 4294967295);
//	printf("% u\n\n", 4294967295);

	ft_printf("%+u\n", 4294967295);
//	printf("%+u\n\n", 4294967295);

	int i;
	i = ft_printf("%S", L"Á±≥");
	printf("%d\n", i);
	i = printf("%S", L"Á±≥");
	printf("%d\n", i);

    i =	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n",
                     L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
                     L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
    printf("%d\n", i);
    i = printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n",
               L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
               L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
    printf("%d\n", i);

}

int main()
{
	setlocale(LC_ALL, "");
	tests();
    int i;

//  ft_printf("% Zoooo\n");
//  printf("% Zoooo\n");


    return (0);
}
