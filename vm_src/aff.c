
#include "header.h"

char				*ft_dup(char *src, unsigned int value)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	if (!(tmp = malloc(sizeof(char *) * (len + 3))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = value;
	tmp[i + 1] = '\0';
	return (tmp);
}

void				call_aff(t_vm *vm, int i)
{
	ft_printf("Aff: %c\n", get_value_inside_reg((unsigned char *)vm->
				procs[i]->reg[vm->procs[i]->instruc.params[0] - 1]));
}
