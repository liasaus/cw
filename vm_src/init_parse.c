
#include "header.h"

int		set_champions1(t_get_procs *g, t_vm *vm, int l1, int l2)
{
	int b;

	if (g->p_ordonate[l2] > g->off1 + g->off2)
		exit_with_error("you can't set the pos over the number of player!");
	if ((g->p_ordonate[l2] == g->p_natural[l1]) ||
			(g->p_ordonate[l2] == g->i + 1))
	{
		if (g->p_ordonate[l2] == g->p_natural[l1])
		{
			b = l1 - 1;
			while (b < g->off1)
			{
				g->p_natural[b] += 1;
				b++;
			}
		}
		dl_champ(&vm->champions[g->i++], g->t_ordonate[l2],
				(unsigned)g->len_ordonate[l2]);
		return (1);
	}
	return (0);
}

int		set_champions(t_get_procs g, t_vm *vm, int l1, int l2)
{
	while (g.i < g.off1 + g.off2)
	{
		l2 = 0;
		while (l2 < g.off2)
		{
			if (set_champions1(&g, vm, l1, l2))
				break ;
			l2++;
		}
		if (l2 >= g.off2)
		{
			dl_champ(&vm->champions[g.i++], g.t_natural[l1],
					(unsigned)g.len_natural[l1]);
			l1++;
		}
	}
	vm->nb_champions = g.off1 + g.off2;
	return (0);
}

int		get_champions_while1(t_get_procs *g, int *i, char **av, t_vm *vm)
{
	if (ft_strcmp(av[*i], "-dump") == 0 && av[*i + 1] != NULL)
	{
		if (!ft_isdigit(av[*i + 1][0]))
			exit_with_error("Give us a good number for the dump, dummie!");
		if (g->state == 0)
			vm->nbr_cycle = ft_atoi(av[++(*i)]);
		else
			exit_with_error("I don't want to read two times the dump!");
		g->state = 1;
		return (1);
	}
	else if (ft_strcmp(av[*i], "-v") == 0)
	{
		vm->visu = 1;
		return (1);
	}
	else if (ft_strcmp(av[*i], "-n") == 0 && av[*i + 1] != NULL)
	{
		if (av[*i + 2] == NULL)
			exit_with_error("flag \'-n\': usage: -n number champion1.cor");
		g->nb = ft_atoi(av[++(*i)]);
		return (1);
	}
	return (0);
}

void	get_champions_while2(t_get_procs *g, int i, char **av)
{
	if (!file_get_binary(av[i], &g->tmp, &g->lentmp))
		exit_with_error("problem with the file");
	if (g->nb != -1)
	{
		if (g->nb <= 0 || g->nb > MAX_PLAYERS)
			exit_with_error("error whith the -n");
		if (!check_array_have(g->p_ordonate, g->off2, g->nb))
			exit_with_error("I don't want doublon");
		g->p_ordonate[g->off2] = g->nb;
		g->t_ordonate[g->off2] = g->tmp;
		g->len_ordonate[g->off2] = g->lentmp;
		g->off2++;
		g->nb = -1;
	}
	else
	{
		g->p_natural[g->off1] = g->off1 + 1;
		g->t_natural[g->off1] = g->tmp;
		g->len_natural[g->off1] = g->lentmp;
		g->off1++;
	}
}

int		get_champions(char **av, t_vm *vm)
{
	t_get_procs	g;
	int			i;

	get_champions_init(&g);
	i = 0;
	while (av[i] != NULL)
	{
		if (get_champions_while1(&g, &i, av, vm))
			;
		else if (g.off1 + g.off2 < MAX_PLAYERS)
			get_champions_while2(&g, i, av);
		else
			exit_with_error("too many players!");
		i++;
	}
	g.i = 0;
	return (set_champions(g, vm, 0, 0));
}
