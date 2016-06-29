
#include "header.h"

void			copy_champ(t_vm *vm, int champ)
{
	unsigned	i;
	int			start;
	unsigned	end;
	int			write;

	i = 0;
	if (vm->champ_mem_size > vm->champions[champ].len_prog)
		end = vm->champ_mem_size;
	else
		end = vm->champions[champ].len_prog;
	start = champ * vm->champ_mem_size;
	while (i < end)
	{
		if (start + i < MEM_SIZE)
			write = start + i;
		else
			write = (start + i) % MEM_SIZE;
		if (i < vm->champions[champ].len_prog)
			vm->mem[write] = vm->champions[champ].prog[i];
		else
			vm->mem[write] = 0;
		i++;
	}
}

void			init_mem(t_vm *vm)
{
	int			i;

	i = 0;
	vm->champ_mem_size = MEM_SIZE / vm->nb_champions;
	while (i < (int)vm->nb_champions)
	{
		copy_champ(vm, i);
		i++;
	}
	i = i * vm->champ_mem_size;
	while (i < MEM_SIZE)
		vm->mem[i++] = 0;
}
