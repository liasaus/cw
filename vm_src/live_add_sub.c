
#include "header.h"

void				call_live(t_vm *vm, int i)
{
	unsigned int	a;
	unsigned int	nb;

	nb = vm->procs[i]->instruc.params[0];
	vm->procs[i]->call_live = 1;
	a = -1;
	while (++a < vm->nb_champions)
		if (a + 1 == nb * -1)
			break ;
	if (a < vm->nb_champions)
	{
		vm->champions[a].live++;
		vm->last_to_call_live = a;
	}
}

void				call_add(t_vm *vm, int i)
{
	if ((vm->procs[i]->instruc.params[0] > 0 && vm->procs[i]->instruc.params[0]
				<= REG_NUMBER) && (vm->procs[i]->instruc.params[1] > 0
					&& vm->procs[i]->instruc.params[1] <= REG_NUMBER)
			&& (vm->procs[i]->instruc.params[2] > 0
				&& vm->procs[i]->instruc.params[2] <= REG_NUMBER))
	{
		add_two_reg((unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[2] - 1],
				(unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[0] - 1],
				(unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[1] - 1]);
		vm->procs[i]->carry = ((get_value_inside_reg((unsigned char *)
					vm->procs[i]->reg[vm->procs[i]->instruc.params[2] - 1])
				== 0) ? 1 : 0);
	}
}

void				call_sub(t_vm *vm, int i)
{
	if ((vm->procs[i]->instruc.params[0] > 0 && vm->procs[i]->instruc.params[0]
				<= REG_NUMBER) && (vm->procs[i]->instruc.params[1] > 0
					&& vm->procs[i]->instruc.params[1] <= REG_NUMBER)
			&& (vm->procs[i]->instruc.params[2] > 0
				&& vm->procs[i]->instruc.params[2] <= REG_NUMBER))
	{
		sub_two_reg((unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[2] - 1],
				(unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[0] - 1],
				(unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[1] - 1]);
		vm->procs[i]->carry = ((get_value_inside_reg((unsigned char *)
					vm->procs[i]->reg[vm->procs[i]->instruc.params[2] - 1])
				== 0) ? 1 : 0);
	}
}
