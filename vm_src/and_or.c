
#include "header.h"

#define AND 1
#define OR 2
#define XOR 3

void	call_and(t_vm *vm, int i)
{
	background_bitwise_op(vm, i, AND);
}

void	call_or(t_vm *vm, int i)
{
	background_bitwise_op(vm, i, OR);
}

void	call_xor(t_vm *vm, int i)
{
	background_bitwise_op(vm, i, XOR);
}
