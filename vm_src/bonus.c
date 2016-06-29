
#include "header.h"

void			extra_life(t_vm *vm, unsigned int i)
{
	static int	extra_life = 1;

	if (!extra_life)
		return ;
	else
	{
		extra_life = 0;
		while (i < vm->nb_procs)
		{
			vm->procs[i]->extra_life = 1;
			i++;
		}
	}
}

void			explode(t_vm *vm, int a, int b)
{
	int			j;
	int			k;
	int			mem;

	j = 0;
	while (j < 5)
	{
		k = 0;
		while (k < 5)
		{
			mem = ((b + j) * 64) + (a + k);
			vm->mem[mem] = 0;
			k++;
		}
		j++;
	}
}

void			call_explosion(t_vm *vm, int i)
{
	int			a;
	int			b;

	if (vm->procs[i]->pc % 64 < 2)
		a = 0;
	else if (vm->procs[i]->pc % 64 > 61)
		a = 59;
	else
		a = (vm->procs[i]->pc % 64) - 2;
	if (vm->procs[i]->pc / 64 < 2)
		b = 0;
	else if (vm->procs[i]->pc / 64 > 61)
		b = 59;
	else
		b = (vm->procs[i]->pc / 64) - 2;
	explode(vm, a, b);
}
