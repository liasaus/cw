
#include "asm.h"

t_instruction	g_instruction[] =
{
	{"live", 4, 1, {T_DIR}, 0x1, 0, 4},
	{"ld", 2, 2, {T_DIR | T_IND, T_REG}, 0x2, 1, 4},
	{"st", 2, 2, {T_REG, T_IND | T_REG}, 0x3, 1, 0},
	{"add", 3, 3, {T_REG, T_REG, T_REG}, 0x4, 1, 0},
	{"sub", 3, 3, {T_REG, T_REG, T_REG}, 0x5, 1, 0},
	{"and", 3, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		0x6, 1, 4},
	{"or", 2, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		0x7, 1, 4},
	{"xor", 3, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		0x8, 1, 4},
	{"zjmp", 4, 1, {T_DIR}, 0x9, 0, 2},
	{"ldi", 3, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0xA, 1, 2},
	{"sti", 3, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 0xB, 1, 2},
	{"fork", 4, 1, {T_DIR}, 0xC, 0, 2},
	{"lld", 3, 2, {T_DIR | T_IND, T_REG}, 0xD, 1, 4},
	{"lldi", 4, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0xE, 1, 2},
	{"lfork", 5, 1, {T_DIR}, 0xF, 0, 2},
	{"aff", 3, 1, {T_REG}, 0x10, 1, 0},
	{"mine", 4, 1, {T_DIR}, 0x11, 0, 2},
	{"oneup", 5, 1, {T_DIR}, 0x12, 0, 2},
	{"bomb", 4, 1, {T_DIR}, 0x13, 0, 2}
};

int				g_address = 0x0;

t_label			**g_labels;

int				g_line = 0;

void			put_usage(void)
{
	ft_putstr_fd("Usage: ./asm [-a] <sourcefile.s>\n\t-a : ", 2);
	ft_putstr_fd("Instead of creating a .cor file, outputs a stripped and ", 2);
	ft_putstr_fd("annotated version of the code to the standard output\n", 2);
	exit(0);
}

void			put_error(char *msg)
{
	if (msg)
	{
		ft_putstr_fd("line ", 2);
		ft_putnbr_fd(g_line, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	else
		perror(0);
	exit(0);
}

static char		*return_oname(char *iname)
{
	char	*ptr;
	char	*ret;
	char	*freed;

	ret = 0;
	ptr = &iname[ft_strlen(iname) - 2];
	if (ptr[0] == '.' && ptr[1] == 's')
	{
		freed = ft_strsub(iname, 0, ptr - iname);
		ret = ft_strjoin(freed, ".cor");
		free(freed);
	}
	else
		put_error("bad champion file name\n");
	return (ret);
}

static void		stock_meta(t_meta **meta_ptr, char *iname)
{
	t_meta		*meta;

	meta = *meta_ptr;
	if (meta)
	{
		if (meta->fd != 0)
			meta->file_out = return_oname(iname);
		else
			meta->file_out = ft_strdup("out.cor");
		meta->commands = NULL;
		meta->header = init_theader();
	}
}

int				main(int argc, char **argv)
{
	t_meta		*meta;
	char		flags[38];
	int			i;

	if (argc <= 1)
		put_usage();
	ft_bzero(flags, 38);
	i = checkflags(flags, argv);
	if (!(meta = malloc(sizeof(*meta))))
		return (0);
	meta->fildes = 0;
	if (ft_strchr(flags, 'i'))
		meta->fd = 0;
	else if ((meta->fd = open(argv[i], O_RDONLY)) < 0)
		put_error(0);
	stock_meta(&meta, argv[i]);
	if (!(g_labels = malloc(sizeof(*g_labels))))
		put_error(0);
	*g_labels = NULL;
	parse_file(&meta);
	close(meta->fd);
	(ft_strchr(flags, 'a')) ? write_option_a(meta) : write_to_file(meta);
	free(meta->file_out);
	free(meta);
	return (0);
}
