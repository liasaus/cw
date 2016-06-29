
#include "header.h"

unsigned int		get_v1(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.type_params[0] == T_REG
		&& reg_correct(vm->procs[i]->instruc.params[0]))
		return (get_value_inside_reg((unsigned char *)
				vm->procs[i]->reg[vm->procs[i]->instruc.params[0] - 1]));
	else if (vm->procs[i]->instruc.type_params[0] == T_IND)
		return (get_value_from_mem((unsigned char *)vm->mem,
				vm->procs[i]->instruc.params[0]));
	else
		return (vm->procs[i]->instruc.params[0]);
}

unsigned int		get_v2(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.type_params[1] == T_REG
			&& reg_correct(vm->procs[i]->instruc.params[1]))
		return (get_value_inside_reg((unsigned char *)
				vm->procs[i]->reg[vm->procs[i]->instruc.params[1] - 1]));
	else if (vm->procs[i]->instruc.type_params[1] == T_IND)
		return (get_value_from_mem((unsigned char *)vm->mem,
				vm->procs[i]->instruc.params[1]));
	else
		return (vm->procs[i]->instruc.params[1]);
}

void				background_bitwise_op(t_vm *vm, int i, int op)
{
	unsigned int	v1;
	unsigned int	v2;

	v1 = get_v1(vm, i);
	v2 = get_v2(vm, i);
	if (vm->procs[i]->instruc.nb_params == 3 &&
			vm->procs[i]->instruc.type_params[2] == T_REG &&
			(vm->procs[i]->instruc.params[2] <= REG_NUMBER)
			&& (vm->procs[i]->instruc.params[2] > 0))
	{
		if (op == AND)
			put_value_inside_reg((unsigned char *)vm->procs[i]->
					reg[vm->procs[i]->instruc.params[2] - 1], v1 & v2);
		else if (op == OR)
			put_value_inside_reg((unsigned char *)vm->procs[i]->
					reg[vm->procs[i]->instruc.params[2] - 1], v1 | v2);
		else
			put_value_inside_reg((unsigned char *)vm->procs[i]->
					reg[vm->procs[i]->instruc.params[2] - 1], v1 ^ v2);
		vm->procs[i]->carry = ((get_value_inside_reg(
						(unsigned char *)vm->procs[i]->reg[vm->procs[i]->
						instruc.params[2] - 1]) == 0) ? 1 : 0);
	}
}
