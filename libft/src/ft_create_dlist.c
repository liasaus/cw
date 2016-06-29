
#include <stdlib.h>
#include "libft.h"

t_dlist			*ft_create_list(void)
{
	t_dlist	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	else
	{
		new->first = NULL;
		new->last = NULL;
		new->lenght = 0;
	}
	return (new);
}
