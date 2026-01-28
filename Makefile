# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 07:52:24 by jbarreir          #+#    #+#              #
#    Updated: 2026/01/28 08:29:55 by jbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

# List of source files
SRC     = ft_printf.c ft_printf_format_str.c ft_printf_format_nbr.c
# List of object files (replaces .c with .o)
OBJ     = $(SRC:.c=.o)
# Header file
INCLUDE = ft_printf.h

# Main rule
all: $(NAME)

# Create the static library
$(NAME): $(OBJ)
	$(AR) $@ $^

# Compile source files into object files
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJ)

# Remove object files and the library
fclean: clean
	$(RM) $(NAME)

# Remake: full cleanup and rebuild
re: fclean all

# Declare rules as non-file targets
.PHONY: all clean fclean re