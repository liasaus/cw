
#include <unistd.h>

void	ft_putaddr(void *addr)
{
	long int			base;
	char				c;
	unsigned long int	n;

	n = (unsigned long int)addr;
	base = 16;
	write(1, "0x", 2);
	while (n / base >= 16)
		base *= 16;
	while (base > 0)
	{
		c = '0' + n / base;
		if (c > '9')
		{
			c += 39;
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		n %= base;
		base /= 16;
	}
}
