
#include "header.h"

void	init_new_procs(t_proc ***new_procs, size_t a, t_vm *vm, int i)
{
	size_t b;
	size_t c;

	if (!((*new_procs)[a] = malloc(sizeof(t_proc))))
		exit_with_error("problem of memory...");
	(*new_procs)[a]->carry = vm->procs[i]->carry;
	(*new_procs)[a]->wait = 0;
	(*new_procs)[a]->new_born = 0;
	(*new_procs)[a]->call_live = vm->procs[i]->call_live;
	(*new_procs)[a]->instruc.opcode = 0;
	(*new_procs)[a]->move_pc = 0;
	(*new_procs)[a]->extra_life = 0;
	b = 0;
	while (b < REG_NUMBER)
	{
		c = 0;
		while (c < REG_SIZE)
		{
			(*new_procs)[a]->reg[b][c] = vm->procs[i]->reg[b][c];
			c++;
		}
		b++;
	}
	(*new_procs)[a]->pc = (vm->procs[i]->pc +
			vm->procs[i]->instruc.params[0]) % MEM_SIZE;
}

void	background_fork(t_vm *vm, int i)
{
	t_proc **new_procs;
	size_t len;
	size_t a;

	len = 0;
	while (vm->procs[len] != NULL)
		len++;
	if (!(new_procs = malloc(sizeof(t_proc **) * (len + 2))))
		exit_with_error("problem of memory...");
	a = 0;
	while (a < len)
	{
		new_procs[a] = vm->procs[a];
		a++;
	}
	init_new_procs(&new_procs, a, vm, i);
	new_procs[a + 1] = NULL;
	ft_memdel((void *)&vm->procs);
	vm->procs = new_procs;
	vm->nb_procs++;
}

void	call_fork(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.nb_params == 1)
		background_fork(vm, i);
}

void	call_lfork(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.nb_params == 1)
		background_fork(vm, i);
}
