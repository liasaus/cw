
#include "libft.h"

void	ft_putnbr(int n)
{
	char	*tmp;

	if (!(tmp = ft_itoa(n)))
		return ;
	ft_putstr(tmp);
	free(tmp);
}
