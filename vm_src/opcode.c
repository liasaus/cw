
#include "header.h"

#define AND 1
#define OR 2
#define XOR 3

int			do_check(t_vm *vm, int i, int op, unsigned int a)
{
	int		not_well;

	a = 0;
	while (a < vm->procs[i]->instruc.nb_params)
	{
		not_well = 1;
		if ((g_instruction[op].param_type[a] & T_REG)
			!= 0 && vm->procs[i]->instruc.type_params[a] == T_REG &&
			reg_correct(vm->procs[i]->instruc.params[a]))
		{
			not_well = 0;
			if (!(vm->procs[i]->instruc.params[a] > 0
				&& vm->procs[i]->instruc.params[a] <= REG_NUMBER))
				return (0);
		}
		if (((g_instruction[op].param_type[a] & T_DIR) != 0
				&& vm->procs[i]->instruc.type_params[a] == T_DIR)
			|| ((g_instruction[op].param_type[a] & T_IND) != 0
				&& vm->procs[i]->instruc.type_params[a] == T_IND))
			not_well = 0;
		if (not_well)
			return (0);
		a++;
	}
	return (1);
}

int			check_params(t_vm *vm, int i)
{
	int		op;

	if ((vm->procs[i]->instruc.opcode < 0 && vm->procs[i]->instruc.opcode >
				INSTRUCTIONS) || (vm->procs[i]->instruc.nb_params <= 0)
			|| (vm->procs[i]->instruc.nb_params > 3))
		return (0);
	op = vm->procs[i]->instruc.opcode - 1;
	return (do_check(vm, i, op, 0));
}

void		lower_opcode(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.opcode == 1)
		call_live(vm, i);
	if (vm->procs[i]->instruc.opcode == 2)
		call_ld(vm, i);
	if (vm->procs[i]->instruc.opcode == 3)
		call_st(vm, i);
	if (vm->procs[i]->instruc.opcode == 4)
		call_add(vm, i);
	if (vm->procs[i]->instruc.opcode == 5)
		call_sub(vm, i);
	if (vm->procs[i]->instruc.opcode == 6)
		call_and(vm, i);
	if (
			vm->procs[i]->instruc.opcode == 7)
		call_or(vm, i);
	if (vm->procs[i]->instruc.opcode == 8)
		call_xor(vm, i);
	if (vm->procs[i]->instruc.opcode == 9)
		call_zjmp(vm, i);
	if (vm->procs[i]->instruc.opcode == 10)
		call_ldi(vm, i);
}

void		higher_opcode(t_vm *vm, int i)
{
	if (vm->procs[i]->instruc.opcode == 11)
		call_sti(vm, i);
	if (vm->procs[i]->instruc.opcode == 12)
		call_fork(vm, i);
	if (vm->procs[i]->instruc.opcode == 13)
		call_lld(vm, i);
	if (vm->procs[i]->instruc.opcode == 14)
		call_lldi(vm, i);
	if (vm->procs[i]->instruc.opcode == 15)
		call_lfork(vm, i);
	if (vm->procs[i]->instruc.opcode == 16)
		call_aff(vm, i);
	if (vm->procs[i]->instruc.opcode == 17)
	{
		if (vm->procs[i]->extra_life)
			vm->procs[i]->extra_life = 0;
		else
			kill_proc(vm, i);
	}
	if (vm->procs[i]->instruc.opcode == 18)
		extra_life(vm, 0);
	if (vm->procs[i]->instruc.opcode == 19)
		call_explosion(vm, i);
}

void		do_opcode(t_vm *vm, int i)
{
	unsigned int b;

	if (vm->procs[i] == NULL)
		return ;
	if (check_params(vm, i) && vm->procs[i])
	{
		if (vm->procs[i]->instruc.opcode > 0 &&
				vm->procs[i]->instruc.opcode < 11)
			lower_opcode(vm, i);
		else
			higher_opcode(vm, i);
	}
	b = 0;
	while (b < 3)
	{
		vm->procs[i]->instruc.nb_params = 0;
		vm->procs[i]->instruc.opcode = 0;
		vm->procs[i]->instruc.params[b] = 0;
		vm->procs[i]->instruc.type_params[b] = 0;
		b++;
	}
	vm->procs[i]->instruc.nb_params = 0;
	vm->procs[i]->instruc.opcode = 0;
}
