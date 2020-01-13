##
## EPITECH PROJECT, 2019
## CPool_infinadd_2019
## File description:
## Makefile
##

SRC_DIR	=	src/

FILE_LIST	=	my_getnbr.c	\
				my_nbr_base_to_str.c	\
				my_nbr_to_str.c	\
				my_print_base.c	\
				my_print_char.c	\
				my_print_nbr.c	\
				my_print_float.c	\
				my_print_pointeur.c	\
				my_print_str.c	\
				my_printf.c	\
				my_putchar.c	\
				my_putnbr_sized.c	\
				my_putstr_sized.c	\
				my_putstr.c	\
				my_putstrfull.c	\
				my_strcat.c	\
				my_strdup.c	\
				my_strlen.c	\
				my_strncpy.c	\
				my_float_to_str.c	\
				length_tags.c	\
				params.c

SRC	=	$(addprefix $(SRC_DIR), $(FILE_LIST))

MAIN = src/main.c

NAME = libmy_printf.a

OBJ	=	$(SRC:.c=.o)

LIB = -L./ -lmy

CFLAGS += -W -Wall -Wextra -pedantic -I./include -g3

DEBUG += -W -Wall -Wextra -pedantic -g3

all : $(NAME)

$(NAME) : $(OBJ)
	mkdir -p ../../include
	cp include/*.h ../../include
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	make clean

clean :
	rm -f src/*.gc*
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f print
	rm -f tests/unit_tests

re : fclean all

test :
	make -C ./ re
	gcc $(MAIN) -o print -I./ $(LIB) $(CFLAGS)

tests_run : clean
	make -C tests/ tests_run

tests_clean	: clean
	make -C tests/ clean

tests_fclean : fclean
	make -C tests/ fclean

debug :
	make -C ./ re
	gcc $(MAIN) -o print -I./include $(LIB) $(DEBUG)