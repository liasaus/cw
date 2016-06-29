.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
SRC_PATH = ./src/
SRC_NAME = ft_putchar.c ft_putstr.c ft_tolower.c ft_toupper.c ft_strlen.c \
		   ft_memset.c ft_strcpy.c ft_isascii.c ft_isalpha.c ft_isdigit.c \
		   ft_isalnum.c ft_isprint.c ft_putchar_fd.c ft_putstr_fd.c \
		   ft_putendl.c ft_putendl_fd.c ft_strdup.c ft_bzero.c ft_putnbr.c \
		   ft_strchr.c ft_strrchr.c ft_atoi.c ft_strdel.c ft_memcpy.c \
		   ft_memalloc.c ft_strclr.c ft_strncpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		   ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_memdel.c \
		   ft_strnew.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		   ft_strsplit.c ft_itoa.c ft_putnbr_fd.c ft_lstnew.c ft_lstiter.c \
		   ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_putstr_dbcote.c \
		   ft_puttab.c ft_printf.c ft_printf_find.c \
		   ft_printf_find2.c ft_printf_flag.c ft_litoa.c ft_putw.c ft_putc.c \
		   ft_printf_printv.c ft_printf_printc.c ft_printf_utils.c \
		   ft_printf_bonus.c ft_printf_flag2.c ft_putc2.c ft_latoi.c \
		   ft_dela_to_b.c ft_tlen.c get_next_line.c ft_isspace.c\
		   a_clear.c  a_event.c  a_handle.c a_handle2.c a_mode.c \
		   a_print.c  a_screen.c a_listener.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_PATH = ./inc/

CFLAGS = -Wall -Wextra -Werror -g

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[36mLIBFT:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ) $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo "[\033[36m------------------------------------------\033[0m]"
	@echo "[\033[36m---------------- LIBFT - OK --------------\033[0m]"
	@echo "[\033[36m------------------------------------------\033[0m]"

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "[\033[31mSuppression des .o\033[0m]"

fclean: clean
	@rm -fv $(NAME)
	@echo "[\033[31mSuppression de \033[36m$(NAME)\033[0m\033[0m]"

re: fclean all
