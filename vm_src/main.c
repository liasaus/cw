
#include "header.h"

t_instruction g_instruction[19] =
{
	{"live", 4, 1, {T_DIR}, 0x1, 0, 4, 10, 0, 0},
	{"ld", 2, 2, {T_DIR | T_IND, T_REG}, 0x2, 1, 4, 5, 1, 0},
	{"st", 2, 2, {T_REG, T_IND | T_REG}, 0x3, 1, 0, 5, 0, 0},
	{"add", 3, 3, {T_REG, T_REG, T_REG}, 0x4, 1, 0, 10, 0, 0},
	{"sub", 3, 3, {T_REG, T_REG, T_REG}, 0x5, 1, 0, 10, 0, 0},
	{"and", 3, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		0x6, 1, 4, 6, 1, 1},
	{"or", 2, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		0x7, 1, 4, 6, 1, 1},
	{"xor", 3, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		0x8, 1, 4, 6, 1, 1},
	{"zjmp", 4, 1, {T_DIR}, 0x9, 0, 2, 20, 0, 0},
	{"ldi", 3, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		0xA, 1, 2, 25, 1, 0},
	{"sti", 3, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		0xB, 1, 2, 25, 0, 0},
	{"fork", 4, 1, {T_DIR}, 0xC, 0, 2, 800, 1, 0},
	{"lld", 3, 2, {T_DIR | T_IND, T_REG}, 0xD, 1, 4, 10, 0, 0},
	{"lldi", 4, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		0xE, 1, 2, 50, 0, 0},
	{"lfork", 5, 1, {T_DIR}, 0xF, 0, 2, 1000, 0, 0},
	{"aff", 3, 1, {T_REG}, 0x10, 1, 0, 2, 0, 0},
	{"mine", 4, 1, {T_DIR}, 0x11, 0, 2, 10, 0, 0},
	{"oneup", 4, 1, {T_DIR}, 0x12, 0, 2, 10, 0, 0},
	{"bomb", 4, 1, {T_DIR}, 0x13, 0, 2, 10, 0, 0}
};

unsigned int	read_unsigned_int(unsigned char *mem, int len)
{
	unsigned char	mem_tmp[4];
	unsigned int	*ptr;
	int				a;
	int				i;

	a = -1;
	while (++a < 4)
		mem_tmp[a] = 0;
	a = 0;
	i = len - 1;
	while (i >= 0)
	{
		mem_tmp[a++] = mem[i % MEM_SIZE];
		i--;
	}
	ptr = (unsigned int *)mem_tmp;
	return (ptr[0]);
}

void			flush_buffer(t_vm *vm)
{
	int i;

	i = 0;
	while (vm->aff_buffer[i] != NULL)
	{
		ft_printf("%s\n", vm->aff_buffer[i]);
		ft_strdel(&vm->aff_buffer[i]);
		i++;
	}
}

int				corewar(char **av)
{
	t_vm vm;

	if (!init_corewar(&vm, av))
	{
		exit_with_error("parse error");
		return (0);
	}
	if (vm.visu)
		if (a_init() == -1)
			vm.visu = 0;
	fight(&vm);
	return (0);
}

int				main(int ac, char **av)
{
	if (ac >= 2)
		corewar(av + 1);
	return (0);
}
