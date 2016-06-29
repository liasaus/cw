
#include "header.h"

void				add_two_reg(unsigned char *reg_dest, unsigned char *reg_a,
		unsigned char *reg_b)
{
	int			i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		reg_dest[i] = reg_a[i] + reg_b[i];
		i--;
	}
}

void				sub_two_reg(unsigned char *reg_dest, unsigned char *reg_a,
		unsigned char *reg_b)
{
	int				i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		reg_dest[i] = reg_a[i] - reg_b[i];
		i--;
	}
}

unsigned int		get_value_inside_reg(unsigned char *reg)
{
	int				a;
	unsigned int	ret;
	unsigned int	zup;

	a = REG_SIZE - 1;
	zup = 1;
	ret = 0;
	if (!reg)
		return (0);
	while (a >= 0)
	{
		ret += reg[a] * zup;
		zup *= 256;
		a--;
	}
	return (ret);
}

void				put_value_inside_reg(unsigned char *reg, unsigned int value)
{
	int				i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		reg[i] = value % 256;
		value /= 256;
		i--;
	}
}

void				exit_with_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}
