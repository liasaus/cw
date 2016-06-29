
#include "header.h"

void			kill_proc(t_vm *vm, int i)
{
	if ((unsigned)i >= vm->nb_procs && i < 0)
		return ;
	if (vm->procs[i] != NULL)
		ft_memdel((void **)&vm->procs[i]);
	while (vm->procs[i + 1])
	{
		vm->procs[i] = vm->procs[i + 1];
		i++;
	}
	vm->procs[i] = NULL;
	vm->nb_procs -= (vm->nb_procs == 0) ? 0 : 1;
}

void			do_proc(t_vm *vm, int i)
{
	if ((unsigned)i >= vm->nb_procs || i < 0 || !vm->procs[i])
		return ;
	if (vm->procs[i]->wait)
		vm->procs[i]->wait--;
	if (vm->procs[i]->wait == 0)
	{
		do_opcode(vm, i);
		vm->procs[i]->pc += vm->procs[i]->move_pc;
		if (vm->procs[i]->pc >= MEM_SIZE)
			vm->procs[i]->pc = vm->procs[i]->pc % MEM_SIZE;
		vm->procs[i]->move_pc = read_instruction(vm, i);
		if (!vm->procs[i]->new_born && vm->procs[i]->wait)
		{
			vm->procs[i]->new_born = 1;
			vm->procs[i]->wait--;
		}
	}
}

int				death_cycle(t_vm *vm)
{
	int			i;

	if (vm->nbr_cycle > 0 && vm->cycle >= vm->nbr_cycle)
		return (1);
	if (vm->cycle == vm->cycle_to_die)
	{
		i = 0;
		while (vm->procs[i])
		{
			if (vm->procs[i]->call_live == 0 && vm->procs[i]->extra_life)
				vm->procs[i++]->extra_life = 0;
			else if (vm->procs[i]->call_live == 0)
				kill_proc(vm, i);
			else
				vm->procs[i++]->call_live = 0;
		}
		if (CYCLE_DELTA >= vm->cycle_of_death)
		{
			vm->cycle_of_death = 0;
			return (1);
		}
		vm->cycle_of_death -= CYCLE_DELTA;
		vm->cycle_to_die += vm->cycle_of_death;
	}
	return (0);
}

#define SPACE_JUMP 20

int				low_debug(t_vm *vm)
{
	static int	wait = 0;
	int			r;

	if (wait <= 0)
	{
		output_mode(vm);
		r = a_event();
		if (r == E_ESC)
		{
			a_stop(0);
			return (0);
		}
		if (r == E_SPACE)
			wait += SPACE_JUMP;
		if (r == 'r')
			show_info(vm);
		else
			a_clear();
	}
	else
		wait--;
	return (1);
}

void			fight(t_vm *vm)
{
	int			r;
	int			i;

	vm->cycle_of_death = CYCLE_TO_DIE;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle = 0;
	(vm->visu) ? a_clear() : 0;
	r = 1;
	while (vm->nb_procs > 0)
	{
		i = vm->nb_procs;
		(vm->visu == 1) ? (vm->visu = low_debug(vm)) : 0;
		while (i > 0)
			do_proc(vm, i-- - 1);
		vm->cycle++;
		flush_buffer(vm);
		if (death_cycle(vm))
			break ;
	}
	(vm->visu) ? a_stop(0) : 0;
	if (vm->nbr_cycle > 0)
		hex_dump(vm->mem, MEM_SIZE);
	else
		ft_printf("Winner is... (%d)\"{red}%s{eoc}\" !\n",
		vm->last_to_call_live + 1, vm->champions[vm->last_to_call_live].name);
}
