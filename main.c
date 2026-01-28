#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	print_welcome(void)
{
	printf(
	"\n             ▐▘▗       ▘  ▗ ▐▘\n  "
    "           ▜▘▜▘  ▛▌▛▘▌▛▌▜▘▜▘\n  "
    "           ▐ ▐▖▄▖▙▌▌ ▌▌▌▐▖▐\n   "
    "                ▌          \n"
	);
	printf(
	"┌──────────────────────────────────────────┐\n"
	"│        WELCOME TO FT_PRINTF TESTER       │\n"
	"└──────────────────────────────────────────┘\n"
	"                 jbarreir\n\n"
	);
	printf("--------------------------------------------\n\n");
}

void	test_header(char *title)
{
	printf("\n--- %s ---\n", title);
}

int	main(void)
{
	int	res_orig;
	int	res_ft;

	print_welcome();

	// 0. First evaluation edge cases
	/*
	test_header("FIRST EVALUATION BLOCK (NO ARG)");
	printf("NOTHING\n");
	ft_printf();
	printf("---\n");
	printf("SIMPLE STR\n");
	ft_printf("hola evaluador ;)\n");
	printf("---\n");
	*/

	// 1. NULL and Empty Strings
	test_header("NULL & EMPTY");
	res_orig = printf("Original: %s\n", (char *)NULL);
	res_ft = ft_printf("Mine    : %s\n", (char *)NULL);
	printf("resurn - Orig: %d | Mine: %d\n", res_orig, res_ft);

	res_orig = printf("Original: Empty string: [%s]\n", "");
	res_ft = ft_printf("Mine    : Empty string: [%s]\n", "");
	printf("resurn - Orig: %d | Mine: %d\n", res_orig, res_ft);

	// 2. Integers - Extreme Cases
	test_header("INTEGERS (d/i)");
	res_orig = printf("Original: Min: %d | Max: %d | Zero: %d\n", INT_MIN, INT_MAX, 0);
	res_ft = ft_printf("Mine    : Min: %d | Max: %d | Zero: %d\n", INT_MIN, INT_MAX, 0);
	printf("resurn - Orig: %d | Mine: %d\n", res_orig, res_ft);

	// 3. Pointers - The NULL test
	test_header("POINTERS (p)");
	void *ptr = (void *)0x7fff5fbff608;
	res_orig = printf("Original: Valid: %p | Null: %p\n", ptr, NULL);
	res_ft = ft_printf("Mine    : Valid: %p | Null: %p\n", ptr, NULL);
	printf("resurn - Orig: %d | Mine: %d\n", res_orig, res_ft);

	// 4. Hexadecimal and Unsigned
	test_header("HEX & UNSIGNED");
	res_orig = printf("Original: %x | %X | %u\n", 4294967295U, 4294967295U, 4294967295U);
	res_ft = ft_printf("Mine    : %x | %X | %u\n", 4294967295U, 4294967295U, 4294967295U);
	printf("resurn - Orig: %d | Mine: %d\n", res_orig, res_ft);

	// 5. Mixed Combinations
	test_header("COMBINATIONS");
	res_orig = printf("Original: %%%c%s%d%i%u%x%X%%\n", 'A', "42", 42, 42, 42, 42, 42);
	res_ft = ft_printf("Mine    : %%%c%s%d%i%u%x%X%%\n", 'A', "42", 42, 42, 42, 42, 42);
	printf("resurn - Orig: %d | Mine: %d\n", res_orig, res_ft);

    printf("\n-------------------------------------------");
    printf("\nThanks for evaluating ft_printf by jbarreir\n");
    printf(  "-------------------------------------------\n");

	return (0);
}