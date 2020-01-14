##
## EPITECH PROJECT, 2019
## CPool_Day10_2019
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		is_only_num.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	libmy.a

CLEAN = clean

HEADER	=	my.h	\
			list.	\

all : $(NAME) $(CLEAN)

$(CLEAN) :
		rm -f $(OBJ)

$(NAME) :
		cd ../../ && mkdir -p include && cd lib/my/
		cp ./my.h ../../include/
		gcc -c $(SRC) -I./
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../

