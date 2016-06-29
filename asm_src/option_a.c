
#include "asm.h"

static void		write_header(t_meta *meta)
{
	ft_putstr("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", g_address);
	ft_printf("Name : \"%s\"\n", meta->header->prog_name);
	ft_printf("Comment : \"%s\"\n", meta->header->comment);
	free(meta->header);
}

static void		write_param(t_cmnd *cmnd)
{
	char	**tab;
	int		i;
	char	*tmp;

	i = 0;
	tab = ft_strsplit(cmnd->line, ',');
	while (tab[i])
	{
		tmp = ft_strtrim(tab[i]);
		ft_printf("\t\t%s", tmp);
		free(tmp);
		free(tab[i]);
		i++;
	}
	free(tab);
}

void			print_param_oct(t_cmnd *cmnd, int i, int limit)
{
	int	j;
	int	ret;

	j = 0;
	while (j < limit)
	{
		ret = cmnd->params[i][j++];
		ft_printf("%-3hhu ", ret);
	}
	if (limit <= 1)
		ft_printf("\t");
}

static void		write_annotated(t_cmnd *cmnd)
{
	t_instruction	select;
	int				codage;
	int				tmp;

	select = g_instruction[cmnd->op_code - 1];
	codage = 0;
	if (select.codage)
		codage = cmnd->codage;
	tmp = cmnd->codage;
	next_line(cmnd, 0, codage, select);
	cmnd->codage = tmp;
	next_line(cmnd, 1, codage, select);
	ft_printf("\n");
}

void			write_option_a(t_meta *meta)
{
	t_cmnd	*tmp;
	t_cmnd	*cmnd;
	int		count;

	count = 0;
	cmnd = meta->commands;
	write_header(meta);
	rewind_labels();
	while (cmnd)
	{
		while ((*g_labels) && count == (*g_labels)->address)
			print_label();
		count += cmnd->size;
		ft_printf("\n%-4d ", cmnd->address);
		ft_printf("(%-3d) :\t", cmnd->size);
		ft_putstr(g_instruction[cmnd->op_code - 1].name);
		write_param(cmnd);
		write_annotated(cmnd);
		free(cmnd->params);
		free(cmnd->line);
		tmp = cmnd->next;
		free(cmnd);
		cmnd = tmp;
	}
}
