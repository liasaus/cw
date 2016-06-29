.PHONY: all clean fclean re print_hex

ASM_NAME = asm
VM_NAME = corewar
PRINT_HEX = print_hex
CC = gcc
ASM_SRC_PATH = ./asm_src/
ASM_SRC_NAME = stockage_header.c stockage_ops.c write_to_file.c ft_strepur.c \
	   stock_cmnd.c stock_label.c param_tools.c main.c checkflags.c \
	   option_a.c bonus_annotated.c
VM_SRC_PATH = ./vm_src/
VM_SRC_NAME = main.c file_get_contents.c print_binary.c init.c init_parse.c \
		init_parse2.c use.c use2.c \
		join_a_b.c init_mem.c fight.c opcode.c zjmp.c ld.c st.c fork.c and_or.c \
		live_add_sub.c mem_use.c opcode_functions.c aff.c bonus.c r.c \
		print_info.c output.c
CFLAGS = -Wall -Wextra -Werror -g
LIB = -L./libft/ -lft
LIB_NAME = libft/libft.a
LIB_INC_PATH = libft/inc/
ASM_INC_PATH = ./asm_inc/
VM_INC_PATH = ./vm_inc/
ASM_OBJ_PATH = ./asm_obj/
VM_OBJ_PATH = ./vm_obj/
ASM_OBJ_NAME = $(ASM_SRC_NAME:.c=.o)
VM_OBJ_NAME = $(VM_SRC_NAME:.c=.o)
FLAGS = -Wall -Wextra -Werror -g
TESTS = ./asm_src/test.c
OBJ_TESTS = $(TESTS:.c=.o)

ASM_OBJ = $(addprefix $(ASM_OBJ_PATH), $(ASM_OBJ_NAME))
VM_OBJ = $(addprefix $(VM_OBJ_PATH), $(VM_OBJ_NAME))

all: $(ASM_NAME) $(VM_NAME)

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.c
	@mkdir $(ASM_OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "\033[36mASM:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I$(ASM_INC_PATH) -I$(LIB_INC_PATH)

$(VM_OBJ_PATH)%.o: $(VM_SRC_PATH)%.c
	@mkdir $(VM_OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "\033[36mCOREWAR:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I$(VM_INC_PATH) -I$(LIB_INC_PATH)

$(ASM_NAME): $(LIB_NAME) $(ASM_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(LIB) $^
	@echo "[\033[36m---------------------------------------\033[0m]"
	@echo "[\033[36m--------------- ASM - OK --------------\033[0m]"
	@echo "[\033[36m---------------------------------------\033[0m]"

$(VM_NAME): $(LIB_NAME) $(VM_OBJ)
	@$(CC) -ltermcap $(CFLAGS) -o $@ $(LIB) $^
	@echo "[\033[36m---------------------------------------\033[0m]"
	@echo "[\033[36m------------- COREWAR - OK ------------\033[0m]"
	@echo "[\033[36m---------------------------------------\033[0m]"

$(LIB_NAME):
	@make -C libft/

clean:
	@rm -rf $(ASM_OBJ_PATH) $(OBJ_TESTS) $(VM_OBJ_PATH)
	@make clean -C libft/

fclean: clean
	@rm -f $(ASM_NAME) $(VM_NAME) $(PRINT_HEX)
	@make fclean -C libft/
	@rm -f print_hex

re: fclean all

test_hex: $(PRINT_HEX)

$(OBJ_TESTS): $(TESTS)
	@mkdir $(ASM_OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "\033[36mTEST:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I$(ASM_INC_PATH) -I$(LIB_INC_PATH)

$(PRINT_HEX): $(LIB_NAME) $(OBJ_TESTS)
	@$(CC) $(TESTS) $(LIB_NAME) $(FLAGS) -o $@
	@echo "[\033[36m---------------------------------------\033[0m]"
	@echo "[\033[36m-------------- TEST - OK --------------\033[0m]"
	@echo "[\033[36m---------------------------------------\033[0m]"
