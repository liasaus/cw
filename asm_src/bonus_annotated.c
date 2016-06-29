
#include "asm.h"

void			rewind_labels(void)
{
	t_label	*ptr;

	ptr = *g_labels;
	while (ptr && ptr->next)
		ptr = ptr->next;
	*g_labels = ptr;
}

void			print_label(void)
{
	t_label *ptr;
	t_label	*tmp;

	ptr = *g_labels;
	ft_printf("\n%d\t   :\t%s:", ptr->address, ptr->name);
	free(ptr->name);
	tmp = ptr->prev;
	free(*g_labels);
	*g_labels = tmp;
}

static void		print_param_third_line(t_cmnd *cmnd, int i, int limit)
{
	union u_param	un;
	int				j;
	int				k;

	j = 0;
	ft_bzero(&un.tab, 4);
	k = limit - 1;
	while (k >= 0)
	{
		un.tab[k] = cmnd->params[i][j];
		k--;
		j++;
	}
	if (limit == 1)
		ft_printf("%-4hhd ", un.i);
	else if (limit == 2)
		ft_printf("%-4hd ", un.i);
	else
		ft_printf("%-4d ", un.i);
	ft_printf("\t");
}

static void		param_next_line(t_cmnd *cmnd, int i, int third_line)
{
	int	limit;
	int	j;

	j = 0;
	if (!cmnd->params[i])
		return ;
	ft_printf("\t");
	if ((cmnd->codage & 0xC0) == (REG_CODE << 6))
		limit = 1;
	else if ((cmnd->codage & 0xC0) == (DIR_CODE << 6))
		limit = g_instruction[cmnd->op_code - 1].dir_size;
	else
		limit = 2;
	if (third_line)
		print_param_third_line(cmnd, i, limit);
	else
		print_param_oct(cmnd, i, limit);
	cmnd->codage = cmnd->codage << 2;
	if (third_line)
		free(cmnd->params[i]);
}

void			next_line(t_cmnd *cmnd, int third, int cod, t_instruction se)
{
	int	i;

	ft_printf("\n\t\t%-4d", cmnd->op_code);
	if (cod)
		ft_printf("%-4hhu", cod);
	else
		ft_printf("\t");
	i = 0;
	while (i < se.nb_param)
		param_next_line(cmnd, i++, third);
}
