
#include "libft.h"
#include <stdlib.h>

t_node			*ft_create_node(void)
{
	t_node	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(*new));
	if (new != NULL)
	{
		while (i < 4)
		{
			new->pos[i].x = 0;
			new->pos[i].y = 0;
			i++;
		}
		new->next = NULL;
	}
	return (new);
}
