
#include "libft.h"

size_t		ft_tlen(char **tabs)
{
	size_t i;

	i = 0;
	while (tabs[i] != NULL)
		i++;
	return (i);
}
