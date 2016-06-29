
#include "header.h"

static char		*allocat(int size)
{
	char *s;

	if ((s = malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	s[0] = '\0';
	return (s);
}

static char		*add_alloc(int fd, int count, t_file *f)
{
	char *tmp;

	f->str = binary_cat(f->str, f->len_str, f->buffer, f->len_buff);
	f->len_str += f->len_buff;
	if ((tmp = allocat(count * READLEN)) == NULL)
	{
		close(fd);
		return (NULL);
	}
	tmp = binary_cpy(tmp, f->str, f->len_str);
	ft_strdel((&f->str));
	tmp[f->len_str] = '\0';
	return (tmp);
}

char			*file_get_contents(char *filename)
{
	int		fd;
	t_file	f;
	int		i;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if ((f.str = allocat(READLEN)) == NULL)
	{
		close(fd);
		return (NULL);
	}
	f.len_str = 0;
	i = 1;
	while ((f.len_buff = read(fd, f.buffer, READLEN)) > 0)
	{
		i++;
		if ((f.str = add_alloc(fd, i, &f)) == NULL)
			return (NULL);
	}
	close(fd);
	return (f.str);
}

int				file_get_binary(char *filename, char **str, int *len)
{
	int		fd;
	t_file	f;
	int		i;

	(*str) = NULL;
	(*len) = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if ((f.str = allocat(READLEN)) == NULL)
	{
		close(fd);
		return (0);
	}
	f.len_str = 0;
	i = 1;
	while ((f.len_buff = read(fd, f.buffer, READLEN)) > 0)
	{
		i++;
		if ((f.str = add_alloc(fd, i, &f)) == NULL)
			return (0);
	}
	close(fd);
	(*str) = f.str;
	(*len) = f.len_str;
	return (1);
}
