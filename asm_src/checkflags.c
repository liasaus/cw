
#include "asm.h"

int		checkflags(char *flags, char **argv)
{
	const char	flags_r[] = "ia";
	int			i;
	int			j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		if (!(ft_strcmp(argv[i], "--")))
			return (i);
		if (argv[i][0] != '-' || (argv[i][0] == '-' && !argv[i][j]))
			return (i);
		while (argv[i][j] && ft_strchr(flags_r, argv[i][j]))
		{
			if (!(ft_strchr(flags, argv[i][j])))
				flags[ft_strlen(flags)] = argv[i][j];
			j++;
		}
		if (argv[i][j])
			return (i);
		i++;
	}
	return (i);
}
