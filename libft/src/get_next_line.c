
#include "libft.h"

t_info			*get_info(int fd, t_list **alst)
{
	t_list	*tmplst;
	t_info	tmpinfo;

	tmplst = *alst;
	while (tmplst)
	{
		if (((t_info*)(tmplst->content))->fd == fd)
			return (tmplst->content);
		tmplst = tmplst->next;
	}
	tmpinfo.fd = fd;
	if (!(tmpinfo.info = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(tmplst = ft_lstnew(&tmpinfo, sizeof(tmpinfo))))
	{
		free(tmpinfo.info);
		return (NULL);
	}
	ft_lstadd(alst, tmplst);
	return ((t_info*)tmplst->content);
}

int				read_info(t_info *info, char **line)
{
	int		res;
	char	*str;

	res = 0;
	if ((str = ft_strchr(info->info, '\n')))
	{
		*str = '\0';
		str++;
		res = 1;
	}
	if (!(*line = ft_strdup(info->info)))
		return (-1);
	if (res)
		ft_strcpy(info->info, str);
	else
		ft_strclr(info->info);
	return (res);
}

int				read_buf(char *buf, char **line, t_info *info)
{
	int		res;
	char	*str;

	res = 0;
	if ((str = ft_strchr(buf, '\n')))
	{
		*str = '\0';
		str++;
		ft_strcpy(info->info, str);
		res = 1;
	}
	str = *line;
	*line = ft_strjoin(*line, buf);
	free(str);
	if (!*line)
		return (-1);
	return (res);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_info			*info;

	if (!line || BUFF_SIZE <= 0 || !(info = get_info(fd, &lst)))
		return (-1);
	if (!(ret = read_info(info, line)))
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (-1);
			buf[ret] = '\0';
			if ((ret = read_buf(buf, line, info)))
				return (ret);
		}
		if (**line)
			return (1);
		return (0);
	}
	return (ret);
}
