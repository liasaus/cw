
#include "header.h"

void	output_while1_2(t_vm *vm, t_visu *t)
{
	if (t->b_color)
	{
		t->len_maker++;
		if (t->len_maker >= vm->champions[t->b - 1].len_prog)
		{
			a_mode_off();
			t->b_color = 0;
		}
	}
	if (t->oo)
	{
		a_printf("{eoc}");
		if (t->b_color)
			a_mode_video_inverted();
	}
	a_printf(" ");
	t->a++;
}

void	output_while1(t_vm *vm, t_visu *t)
{
	if ((unsigned int)(t->i + t->a) == (t->b * vm->champ_mem_size))
	{
		a_mode_video_inverted();
		t->b++;
		t->b_color = 1;
		t->len_maker = 0;
	}
	t->c = 0;
	t->oo = 0;
	while (t->c < t->j)
	{
		if ((unsigned int)(t->i + t->a) == vm->procs[t->c]->pc)
		{
			a_printf("{green}");
			t->oo = 1;
			break ;
		}
		t->c++;
	}
	a_printf("%-.2x", vm->mem[t->i + t->a]);
	output_while1_2(vm, t);
}

void	output_printinfo(t_vm *vm)
{
	a_printg(200, 4, "cycle to {red}die{eoc}!: %d\n", vm->cycle_of_death);
	a_printg(200, 5, "cycle delta: %d\n", CYCLE_DELTA);
	a_printg(200, 6, "cycle of death: %d\n", vm->cycle_to_die);
	a_printg(200, 7, "nbr of cycle: %d\n", vm->cycle);
	a_printg(200, 8, "nbr of process: %d {cyan}(\'r\' for more info){eoc}\n",
	vm->nb_procs);
	a_printg(200, 9, "champion statistic:\n", vm->cycle);
}

void	output_mode(t_vm *vm)
{
	t_visu t;

	t.i = 0;
	t.b = 0;
	t.oo = 0;
	t.j = vm->nb_procs;
	while (t.i < MEM_SIZE)
	{
		t.a = 0;
		while (t.a < 64 && t.i + t.a < MEM_SIZE)
			output_while1(vm, &t);
		a_printf("\n");
		t.i += t.a;
	}
	output_printinfo(vm);
	t.i = 0;
	while (t.i < (int)vm->nb_champions)
	{
		a_printg(200, 10 + t.i, "-{green}%s{eoc} : nb live %u",
		vm->champions[t.i].name, vm->champions[t.i].live);
		a_printf("{green}%s{eoc}\n",
		((vm->last_to_call_live == (unsigned)t.i) ? " current winner!" : ""));
		t.i++;
	}
}
