
#include "header.h"

void				call_ld(t_vm *vm, int i)
{
	unsigned int	reg;

	if ((vm->procs[i]->instruc.nb_params == 2)
			&& (vm->procs[i]->instruc.type_params[1] == T_REG))
	{
		reg = vm->procs[i]->instruc.params[1] - 1;
		if (vm->procs[i]->instruc.type_params[0] == T_IND)
			copy_from_mem((unsigned char *)vm->procs[i]->reg[reg],
					(unsigned char *)vm->mem,
					(vm->procs[i]->instruc.params[0]) % IDX_MOD);
		else
			put_value_inside_reg((unsigned char *)vm->procs[i]->reg[reg],
			vm->procs[i]->instruc.params[0]);
		vm->procs[i]->carry = ((get_value_inside_reg((unsigned char *)
					vm->procs[i]->reg[reg])
				== 0) ? 1 : 0);
	}
}

void				call_ldi(t_vm *vm, int i)
{
	unsigned int	adress;

	adress = 0;
	if ((vm->procs[i]->instruc.nb_params == 3)
			&& ((vm->procs[i]->instruc.type_params[1] == T_REG
					|| vm->procs[i]->instruc.type_params[1] == T_DIR)
				&& vm->procs[i]->instruc.type_params[2] == T_REG))
	{
		if (vm->procs[i]->instruc.type_params[0] == T_REG)
			adress += (get_value_inside_reg((unsigned char *)
vm->procs[i]->reg[vm->procs[i]->instruc.params[0] - 1]) % IDX_MOD);
		else
			adress += (vm->procs[i]->instruc.params[0]);
		if (vm->procs[i]->instruc.type_params[1] == T_REG)
			adress += (get_value_inside_reg((unsigned char *)
vm->procs[i]->reg[vm->procs[i]->instruc.params[1] - 1]) % IDX_MOD);
		else
			adress += (vm->procs[i]->instruc.params[1]);
		adress = (adress + vm->procs[i]->pc) % MEM_SIZE;
		copy_from_mem((unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[2] - 1], (unsigned char *)vm->mem, adress);
	}
}

void				call_lld(t_vm *vm, int i)
{
	unsigned int	reg;

	if ((vm->procs[i]->instruc.nb_params == 2)
			&& (vm->procs[i]->instruc.type_params[1] == T_REG))
	{
		reg = vm->procs[i]->instruc.params[1] - 1;
		if (vm->procs[i]->instruc.type_params[0] == T_IND)
			copy_from_mem((unsigned char *)vm->procs[i]->reg[reg],
					(unsigned char *)vm->mem,
					(vm->procs[i]->instruc.params[0]) % MEM_SIZE);
		else
			put_value_inside_reg((unsigned char *)vm->procs[i]->reg[reg],
			vm->procs[i]->instruc.params[0]);
		vm->procs[i]->carry = ((get_value_inside_reg((unsigned char *)
					vm->procs[i]->reg[reg])
				== 0) ? 1 : 0);
	}
}

void				call_lldi(t_vm *vm, int i)
{
	int				adress;

	adress = 0;
	if ((vm->procs[i]->instruc.nb_params == 3)
			&& ((vm->procs[i]->instruc.type_params[1] == T_REG
					|| vm->procs[i]->instruc.type_params[1] == T_DIR)
				&& vm->procs[i]->instruc.type_params[2] == T_REG))
	{
		if (vm->procs[i]->instruc.type_params[0] == T_REG)
			adress += (get_value_inside_reg((unsigned char *)
			vm->procs[i]->reg[vm->procs[i]->instruc.params[0] - 1]));
		else
			adress += (vm->procs[i]->instruc.params[0]);
		if (vm->procs[i]->instruc.type_params[1] == T_REG)
			adress += (get_value_inside_reg((unsigned char *)
					vm->procs[i]->reg[vm->procs[i]->instruc.params[1] - 1]));
		else
			adress += (vm->procs[i]->instruc.params[1]);
		adress = (adress + vm->procs[i]->pc) % MEM_SIZE;
		copy_from_mem((unsigned char *)vm->procs[i]->reg[vm->procs[i]->
				instruc.params[2] - 1], (unsigned char *)vm->mem, adress);
		vm->procs[i]->carry = ((get_value_inside_reg((unsigned char *)
						vm->procs[i]->reg[vm->procs[i]->instruc.params[2] - 1])
					== 0) ? 1 : 0);
	}
}
