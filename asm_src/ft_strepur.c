
#include "asm.h"

char			*ft_strepur(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (str);
		str++;
	}
	return (str);
}

t_header		*init_theader(void)
{
	t_header	*header;
	int			padding;

	if (!(header = malloc(sizeof(*header))))
		put_error(0);
	header->magic = COREWAR_EXEC_MAGIC;
	padding = 4 - (PROG_NAME_LENGTH + 1) % 4;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1 + padding);
	padding = 4 - (COMMENT_LENGTH + 1) % 4;
	ft_bzero(header->comment, COMMENT_LENGTH + 1 + padding);
	return (header);
}
