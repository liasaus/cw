
#include "header.h"

void		call_zjmp(t_vm *vm, int i)
{
	if (!vm->procs[i]->carry)
		return ;
	vm->procs[i]->pc += (vm->procs[i]->instruc.params[0]);
	vm->procs[i]->pc %= MEM_SIZE;
	vm->procs[i]->move_pc = 0;
}
