
#include "header.h"

void		call_st(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.nb_params == 2)
	{
		if (vm->procs[i]->instruc.type_params[1] == T_IND)
			paste_to_mem((unsigned char *)vm->procs[i]->reg[vm->procs[i]->
					instruc.params[0] - 1], (unsigned char *)vm->mem,
					(vm->procs[i]->instruc.params[1]));
		else if (vm->procs[i]->instruc.type_params[1] == T_REG)
			put_value_inside_reg((unsigned char *)vm->procs[i]->
					reg[vm->procs[i]->instruc.params[1] - 1],
					get_value_inside_reg((unsigned char *)vm->procs[i]->
						reg[vm->procs[i]->instruc.params[0] - 1]));
	}
}

void		call_sti(t_vm *vm, int i)
{
	short	adress;

	adress = (short)vm->procs[i]->pc;
	if (vm->procs[i]->instruc.nb_params == 3)
	{
		if (vm->procs[i]->instruc.type_params[1] == T_REG)
			adress += get_value_inside_reg((unsigned char *)vm->procs[i]->
					reg[vm->procs[i]->instruc.params[1] - 1]) % IDX_MOD;
		else
			adress += (short)vm->procs[i]->instruc.params[1] % IDX_MOD;
		if (vm->procs[i]->instruc.type_params[2] == T_REG)
			adress += get_value_inside_reg((unsigned char *)vm->procs[i]->
					reg[vm->procs[i]->instruc.params[2] - 1]) % IDX_MOD;
		else
			adress += ((short)vm->procs[i]->instruc.params[2] % IDX_MOD);
		paste_to_mem((unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[0] - 1], (unsigned char *)vm->mem,
				(unsigned int)adress % MEM_SIZE);
	}
}
