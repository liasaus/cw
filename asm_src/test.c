
#include "../libft/inc/libft.h"

int		main(int argc, char **argv)
{
	int					fd;
	int					i;
	char				buf[BUFF_SIZE + 1];
	int					ret;
	int					count;

	argc--;
	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		i = 0;
		while (i < ret)
		{
			if (count == 4 || count == 136 || count == 140 || count == 2192)
				ft_putchar('\n');
			ft_printf("0x%2.2hhx\t", buf[i]);
			i++;
			count++;
		}
	}
	ft_putchar('\n');
	return (0);
}
