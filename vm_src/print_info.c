
#include "header.h"

int				print_arg(t_vm *vm, int page, int i)
{
	int e;

	a_printf("\nnumber of parameters: {red}%d{eoc}",
			vm->procs[i + (page * 10)]->instruc.nb_params);
	e = 0;
	if (vm->procs[i + (page * 10)]->instruc.nb_params)
		a_printf(" opcode : %x\n", vm->procs[i + (page * 10)]->instruc.opcode);
	else
		a_printf("\n", vm->procs[i + (page * 10)]->instruc.opcode);
	while ((unsigned)e < vm->procs[i + (page * 10)]->instruc.nb_params && e < 4)
	{
		a_printf("inside parameter %d -> value: |%u| type: ",
				e, vm->procs[i + (page * 10)]->instruc.params[e]);
		if (vm->procs[i]->instruc.type_params[e] == T_REG)
			a_printf("{green}%s{eoc}\n", "register");
		if (vm->procs[i]->instruc.type_params[e] == T_DIR)
			a_printf("{yellow}%s{eoc}\n", "direct");
		if (vm->procs[i]->instruc.type_params[e] == T_IND)
			a_printf("{red}%s{eoc}\n", "indirect");
		e++;
	}
	return (e + 1);
}

void			print_regs(t_vm *vm, int page, int i)
{
	int j;
	int k;

	j = -1;
	while (++j < REG_NUMBER)
	{
		a_printf("{green}r%d{eoc}:", j + 1);
		k = -1;
		while (++k < REG_SIZE)
		{
			a_printf("%-.2hhx", vm->procs[i + (page * 10)]->reg[j][k]);
			(k + 1 >= REG_SIZE) ? 0 : a_printf("{blue}|{eoc}");
		}
		a_printf(" ");
	}
}

void			print_info(t_vm *vm, int page)
{
	int			i;
	int			offset;

	i = 0;
	offset = 0;
	while (vm->procs[i + (page * 10)] && i < 10)
	{
		a_printg(0, i * 3 + offset,
				"processus {yellow}%d{eoc}: | call live during last cycle? ",
				i + (page * 10) + 1);
		if (vm->procs[i + (page * 10)]->call_live)
			a_printf("{green}yes {eoc}");
		else
			a_printf("{red}no {eoc}");
		a_printf("| position of the pc: %d\n", vm->procs[i + (page * 10)]->pc);
		print_regs(vm, page, i);
		offset += print_arg(vm, page, i);
		i++;
	}
	a_printg(0, a_getscreen_y() - 1,
	"%d / %d pages (use left or right keypad to switch page)",
	page + 1, (vm->nb_procs / 10 + 1) - ((vm->nb_procs % 10 == 0) ? 1 : 0));
}

void			show_info(t_vm *vm)
{
	int r;
	int page;

	r = 0;
	page = 0;
	a_clear();
	while (42)
	{
		print_info(vm, page);
		r = a_event();
		a_clear();
		if ((r == E_KEY_LEFT) && !(page - 1 < 0))
			page -= 1;
		if ((r == E_KEY_RIGHT) && !((unsigned)((page + 1) * 10) > vm->nb_procs))
			page += 1;
		if (r == E_ESC)
			break ;
	}
}
