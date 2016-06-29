
#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	int fact;

	fact = 0;
	if (nb == 1 || nb == 0)
	{
		fact = 1;
		return (fact);
	}
	else if (nb < 0 || nb > 12)
		return (0);
	else
	{
		fact = nb * ft_recursive_factorial(nb - 1);
		return (fact);
	}
}
