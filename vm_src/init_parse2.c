
#include "header.h"

int				check_array_have(int *t, int len, int what)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (t[i] == what)
			return (0);
		i++;
	}
	return (1);
}

unsigned int	get_prog_length(unsigned char *b, int len)
{
	unsigned char	mem[4];
	unsigned int	*ptr;
	int				a;
	int				i;

	if (len < 4)
		return (0);
	a = 0;
	i = 3;
	while (i >= 0)
	{
		mem[a++] = b[i];
		i--;
	}
	ptr = (unsigned int *)mem;
	return (ptr[0]);
}

int				magic_number_is_correct(unsigned char *b, int len)
{
	unsigned char	mem[4];
	unsigned int	*ptr;
	int				a;
	int				i;

	if (len < 4)
		return (0);
	a = 0;
	i = 3;
	while (i >= 0)
	{
		mem[a++] = b[i];
		i--;
	}
	ptr = (unsigned int *)mem;
	return ((ptr[0] == COREW_EXEC_MAGIC) ? 1 : 0);
}

void			dl_champ(t_champ *champ, char *champ_binary, unsigned int lc)
{
	int i;

	i = 0;
	if (!magic_number_is_correct((unsigned char *)champ_binary, lc))
		exit_with_error("one of you're file have the bad magic number");
	cpy_a_b((void *)(champ->name), (unsigned char *)champ_binary, 4, 4
			+ PROG_NAME_LENGTH);
	cpy_a_b((void *)(champ->comments), (unsigned char *)champ_binary, 4
	+ PROG_NAME_LENGTH + 4 + 4, 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH);
	champ->len_prog = get_prog_length((unsigned char *)champ_binary +
		4 + PROG_NAME_LENGTH + 4, lc - 4 - PROG_NAME_LENGTH);
	if (!(4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH
			+ 4 + champ->len_prog == lc))
	{
		ft_printf("%d vs %d\n", 4 + PROG_NAME_LENGTH +
		4 + 4 + COMMENT_LENGTH + 4 + champ->len_prog, lc);
		exit_with_error("you indicate the wrong prog length! dummie!");
	}
	champ->prog = join_a_b((unsigned char *)champ_binary,
		4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4, lc);
	champ->live = 0;
}

void			get_champions_init(t_get_procs *g)
{
	int i;

	g->off1 = 0;
	g->off2 = 0;
	g->state = 0;
	i = 0;
	while (i <= MAX_PLAYERS)
	{
		g->p_natural[i] = -1;
		g->t_natural[i] = NULL;
		g->p_ordonate[i] = -1;
		g->t_ordonate[i] = NULL;
		i++;
	}
	g->p_natural[MAX_PLAYERS + 1] = -2;
	g->p_ordonate[MAX_PLAYERS + 1] = -2;
	g->nb = -1;
}
