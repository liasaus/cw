
#include "libft.h"

int			ft_addmodif(const char *restrict pf, t_flag *f)
{
	char modif;

	modif = *pf;
	f->modif[0] = modif;
	pf++;
	if (*pf == modif && modif != 'j' && modif != 'z')
	{
		f->modif[1] = modif;
		return (2);
	}
	else
		f->modif[1] = 0;
	return (1);
}

int			ft_findflag3(const char *restrict pf, t_flag *f)
{
	int ret;

	if (*pf == '=')
	{
		pf++;
		if (ft_atoi(pf) >= 2 && ft_atoi(pf) <= 16 && *pf >= '2' && *pf <= '9')
		{
			ret = 1;
			f->bonus_base = ft_atoi(pf);
			while (*pf >= '0' && *pf <= '9')
			{
				pf++;
				ret++;
			}
			return (ret);
		}
	}
	return (0);
}
