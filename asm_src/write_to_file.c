
#include "asm.h"

static void			write_header(t_meta *meta)
{
	union u_param	magic;
	int				i;
	int				padding;

	i = 3;
	padding = 4 - (PROG_NAME_LENGTH + 1) % 4;
	magic.i = meta->header->magic;
	while (i >= 0)
		ft_putchar_fd(magic.tab[i--], meta->fildes);
	i = 0;
	while (i < (PROG_NAME_LENGTH + 1 + padding))
		ft_putchar_fd(meta->header->prog_name[i++], meta->fildes);
	magic.i = g_address;
	i = 3;
	while (i >= 0)
		ft_putchar_fd(magic.tab[i--], meta->fildes);
	i = 0;
	padding = 4 - (COMMENT_LENGTH + 1) % 4;
	while (i < (COMMENT_LENGTH + 1 + padding))
		ft_putchar_fd(meta->header->comment[i++], meta->fildes);
	free(meta->header);
}

static void			write_param(t_cmnd *cmnd, int i, int fd)
{
	int				j;
	int				limit;

	j = 0;
	if (!cmnd->params[i])
		return ;
	if ((cmnd->codage & 0xC0) == (REG_CODE << 6))
		limit = 1;
	else if ((cmnd->codage & 0xC0) == (DIR_CODE << 6))
		limit = g_instruction[cmnd->op_code - 1].dir_size;
	else
		limit = 2;
	while (j < limit)
		ft_putchar_fd(cmnd->params[i][j++], fd);
	cmnd->codage = cmnd->codage << 2;
	free(cmnd->params[i]);
}

void				write_to_file(t_meta *meta_ptr)
{
	t_cmnd			*cmnd;
	t_cmnd			*tmp;
	int				i;

	cmnd = meta_ptr->commands;
	if ((meta_ptr->fildes = open(meta_ptr->file_out, O_RDWR | O_CREAT |
			O_TRUNC, 0666)) < 0)
		put_error(0);
	write_header(meta_ptr);
	while (cmnd)
	{
		i = 0;
		ft_putchar_fd(cmnd->op_code, meta_ptr->fildes);
		if (g_instruction[cmnd->op_code - 1].codage)
			ft_putchar_fd(cmnd->codage, meta_ptr->fildes);
		while (i < g_instruction[cmnd->op_code - 1].nb_param)
			write_param(cmnd, i++, meta_ptr->fildes);
		free(cmnd->params);
		free(cmnd->line);
		tmp = cmnd->next;
		free(cmnd);
		cmnd = tmp;
	}
	close(meta_ptr->fildes);
	ft_printf("Writing output program to %s\n", meta_ptr->file_out);
}
