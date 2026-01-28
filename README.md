_This project was developed as part of the 42 curriculum by jbarreir._

# ft_libft

A custom C library that replicates the behavior of the standard `printf()` function. This project is a key milestone in the 42 curriculum, focusing on variadic functions and structured parsing in C.

## Description

The goal of this project is to recreate the well-known `printf` function. The function's prototype is:
```c
int ft_printf(char const *str, ...);
```
`ft_printf` writes the C string pointed to by `str` to the standard output (`stdout`). If `str` includes format specifiers (subsequences beginning with `%`), the additional arguments following the string are formatted and inserted, replacing their respective specifiers.

### Supported Conversions

- **`%c`**  
  Prints a single character.

- **`%s`**  
  Prints a string.

- **`%p`**  
  Prints a `void *` pointer argument in hexadecimal format.

- **`%d`**  
  Prints a decimal (base 10) number.

- **`%i`**  
  Prints an integer in base 10.

- **`%u`**  
  Prints an unsigned decimal (base 10) number.

- **`%x`**  
  Prints a number in hexadecimal (base 16) lowercase format.

- **`%X`**  
  Prints a number in hexadecimal (base 16) uppercase format.

- **`%%`**  
  Prints a percent sign.


## Instructions

### Compilation

The project includes a `Makefile` that complies with 42 standards. The main objective is to generate the static library file `libftprintf.a`.

### Available Commands

- **`make`**  
  Compiles the source files and creates the library.

- **`make clean`**  
  Removes object files.

- **`make fclean`**  
  Removes object files and the `.a` library.

- **`make re`**  
  Recompiles the entire project.

To use the library in your project, include the header and link the `.a` file during compilation:

```Bash
cc main.c libftprintf.a -o your_program
```

## Algorithm & Design Decisions

### 1. Independence from Libft

While the subject allows using the `libft` library, I decided to implement custom helper functions specifically tailored for this project. This ensures the library is lightweight, standalone, and avoids unnecessary dependencies.

### 2. The Parsing Loop

The algorithm follows a linear approach:

- **Iteration**  
  The function iterates through the input string character by character.

- **Counter**  
  A `total_len` variable keeps track of the number of characters printed.

- **Detection**  
  When a `%` is detected:
  - If followed by another `%`, it prints a single `%` and increments the length.
  - Otherwise, it calls an argument parser that identifies the conversion type.

- **Error Handling**  
  Every `write` operation is monitored. If a system call fails, the function propagates
  the error and returns `-1`.

### 3. Pointer Arithmetic

Instead of indexing (`str[i]`), the implementation heavily relies on pointer arithmetic (`*str++`) to navigate the format string, resulting in cleaner and more idiomatic C code.


## Resources

### Documentation & Manuals
- **Man Pages**: `man stdarg`, `man 2 read`.
- **Medium**: [Medium – Variadic Functions in C (`stdarg.h`)](https://medium.com/@scarletskynned/variadic-functions-in-c-stdarg-h-f466101f1d47).
- **UC3M**: [UC3M – `printf` Input/Output Notes (Spanish)](https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html).
- **GNU C Library**: [The GNU C Library Documentation](https://www.gnu.org/software/libc/manual/).
- **42 Intra**: Project subject PDF.

### Community Testers
- **Francinette**: [xicodomingues/francinette](https://github.com/xicodomingues/francinette) - Essential for checking memory leaks, undefined behavior, and edge cases in 42 projects.

### Video Tutorials
- **Variadic Functions**: [YouTube – Variadic Functions in C](https://www.youtube.com/watch?v=7Sph8JlRo0g).
- **Practical Examples**: [YouTube – `va_list`, `va_start`, and `va_arg` Explained](https://www.youtube.com/watch?v=kM-DOhKR080).
- **Implementation Overview**: [YouTube – `printf` Implementation Overview](https://www.youtube.com/watch?v=oDC208zvsdg).


## AI Usage Disclosure

In compliance with 42's evaluation standards regarding Artificial Intelligence:

- **Concept Clarification**: AI was used to understand the behavior of variadic macros (`va_start`, `va_arg`, `va_end`) and the specific hexadecimal formatting required for `%p` on different operating systems.
- **Translation & Localization**: AI assisted in translating technical explanations from Spanish to English to ensure professional documentation standards.
- **Debugging & Strategy**: AI was used to brainstorm edge cases (such as `INT_MIN` or `NULL` pointers) and to structure the `ssize_t` error-handling logic.
- **Strict Policy**: 
  - **No Copy-Paste**: No code was directly copied from AI. All implementations were written manually.
  - **Ownership**: Every line of code was understood and is capable of being replicated or modified by the author during a defense.
  - **Verification**: AI-generated suggestions were always cross-referenced with official documentation and verified using the testers mentioned in the Resources section.


## Annex: Testing Suite

To verify the correct behavior of `ft_printf`, I used a custom `main.c` that carries aout several edge cases and compares outputs to the original `printf`.

```

             ▐▘▗       ▘  ▗ ▐▘
             ▜▘▜▘  ▛▌▛▘▌▛▌▜▘▜▘
             ▐ ▐▖▄▖▙▌▌ ▌▌▌▐▖▐
                   ▌          
┌──────────────────────────────────────────┐
│        WELCOME TO FT_PRINTF TESTER       │
└──────────────────────────────────────────┘
                 jbarreir
```

### Test Main (`main.c`)
This main allows you to do your own tests, modifying the chosen parts to meet the evaluation sheet requirements.

```c
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
```