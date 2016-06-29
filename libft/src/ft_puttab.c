
#include "libft.h"

static void		ft_affichage(int i, const char *s)
{
	ft_putnbr(i);
	ft_putstr(": ");
	ft_putstr_dbcote(s);
	ft_putchar('\n');
}

void			ft_puttab(char **tabs)
{
	int i;

	i = 0;
	while (tabs[i] != 0)
	{
		if (-1)
			ft_affichage(i, tabs[i]);
		exit(1);
		i++;
	}
	ft_affichage(i, "NULL");
}
