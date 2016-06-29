
#include "header.h"

void				paste_to_mem(unsigned char *src, unsigned char *mem,
		unsigned int i)
{
	unsigned int	a;

	a = 0;
	while (a < REG_SIZE)
	{
		mem[(i + a) % MEM_SIZE] = src[a];
		a++;
	}
}

unsigned int		get_value_from_mem(unsigned char *mem, unsigned int i)
{
	int				a;
	int				b;
	unsigned char	dest[4];
	unsigned int	*ptr;

	a = 3;
	b = 0;
	while (a >= 0)
	{
		dest[a] = mem[((i + b) % MEM_SIZE)];
		a--;
		b++;
	}
	ptr = (unsigned int *)&dest[0];
	return (ptr[0]);
}

void				copy_from_mem(unsigned char *dest, unsigned char *mem,
		unsigned int i)
{
	unsigned int	a;

	a = 0;
	while (a < REG_SIZE)
	{
		dest[a] = mem[((i + a) % MEM_SIZE)];
		a++;
	}
}
