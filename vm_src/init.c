
#include "header.h"

void	hex_dump(unsigned char *memory, int len)
{
	int i;
	int a;

	i = 0;
	while (i < len)
	{
		a = 0;
		ft_printf("0x%.4x : ", i);
		while (a < 64 && i + a < len)
		{
			ft_printf("%-.2hhx", (unsigned char)memory[i + a], i + a);
			if (!(a + 1 >= 64 || a + 1 >= len))
				ft_printf(" ");
			a++;
		}
		ft_printf("\n");
		i += a;
	}
}

void	present_champion(t_champ *champ, int n)
{
	ft_printf("* Player %d, weighing %u bytes, \"%.*s\" (\"%.*s\") !\n",
			n + 1, champ->len_prog,
			PROG_NAME_LENGTH, champ->name, COMMENT_LENGTH, champ->comments);
}

void	introduce_champion(t_vm *vm)
{
	int i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < (int)vm->nb_champions)
	{
		present_champion(&vm->champions[i], i);
		i++;
	}
}

int		init_procs(t_vm *vm, int i, int i2, int i3)
{
	while (i < (int)vm->nb_champions)
	{
		if (!(vm->procs[i] = malloc(sizeof(t_proc))))
			return (0);
		i2 = 0;
		vm->procs[i]->carry = 1;
		vm->procs[i]->new_born = 0;
		vm->procs[i]->wait = 0;
		vm->procs[i]->call_live = 0;
		vm->procs[i]->instruc.opcode = 0;
		vm->procs[i]->move_pc = 0;
		vm->procs[i]->pc = (i * vm->champ_mem_size) % MEM_SIZE;
		vm->procs[i]->extra_life = 0;
		put_value_inside_reg((unsigned char *)vm->procs[i]->reg[i2++],
				(unsigned)(i + 1) * -1);
		while (i2 < REG_NUMBER)
		{
			i3 = 0;
			while (i3 < REG_SIZE)
				vm->procs[i]->reg[i2][i3++] = 0;
			i2++;
		}
		i++;
	}
	return (1);
}

int		init_corew(t_vm *vm, char **av)
{
	vm->nbr_cycle = -1;
	vm->visu = 0;
	get_champions(av, vm);
	init_mem(vm);
	introduce_champion(vm);
	if (REG_NUMBER <= 0 || REG_SIZE <= 0)
		exit_with_error("the define REG_NUMBER or REG_SIZE IS UNDER OR EQUAL \
				to 0: REGISTERS ARE USELESS");
	if (!(vm->procs = malloc(sizeof(t_proc *) * (vm->nb_champions + 1))) ||
			(!init_procs(vm, 0, 0, 0)) ||
			(!(vm->aff_buffer = malloc(sizeof(unsigned char **) * 2))))
		return (0);
	vm->procs[vm->nb_champions] = NULL;
	vm->aff_buffer[0] = NULL;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_to_call_live = vm->nb_champions - 1;
	vm->nb_procs = vm->nb_champions;
	return (1);
}
