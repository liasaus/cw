
#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (2);
	while (i < nb / i || nb == 4)
	{
		if (nb % i == 0)
			return (ft_find_next_prime(nb + 1));
		else
			i++;
	}
	return (nb);
}
