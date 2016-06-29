
#include "asm.h"

int					find_op(char **line)
{
	char			*start;
	int				i;
	char			*tmp;

	start = *line;
	while (*start && !ft_isspace(*start))
		start++;
	tmp = ft_strsub(*line, 0, start - *line);
	*line = start;
	*line = ft_strepur(*line);
	i = 0;
	while (i < 19)
	{
		if (ft_strcmp(g_instruction[i].name, tmp) == 0)
			break ;
		i++;
	}
	free(tmp);
	if (i >= 19)
		put_error("not valid op\n");
	return (i);
}

void				check_label_find(t_cmnd *tmp)
{
	int		i;
	int		value;

	i = 0;
	while (i < 3)
	{
		if (tmp->label_find[i])
		{
			if ((value = check_label(tmp->label_find[i])) >= 0)
			{
				tmp->params[i] = add_param(value - tmp->address, 2);
				free(tmp->label_find[i]);
				tmp->label_find[i] = NULL;
			}
		}
		i++;
	}
}

void				fill_cmnd(char *line, t_cmnd **commands)
{
	t_cmnd			*new_cmnd;
	t_cmnd			*tmp;
	int				i;

	if (!*line)
		return ;
	i = find_op(&line);
	new_cmnd = find_params(&line, g_instruction[i]);
	add_cmnd_to_end(commands, new_cmnd);
	tmp = *commands;
	while (tmp)
	{
		check_label_find(tmp);
		tmp = tmp->next;
	}
}

void				parse_operations(t_meta **meta_ptr)
{
	char		*line;
	t_meta		*meta;
	char		*tmp;

	meta = *meta_ptr;
	while (get_next_line(meta->fd, &line) > 0)
	{
		g_line++;
		if ((tmp = ft_strchr(line, '#')))
			*tmp = '\0';
		if ((tmp = ft_strchr(line, ';')))
			*tmp = '\0';
		tmp = line;
		line = ft_strepur(line);
		line = fill_label(line);
		line = ft_strepur(line);
		fill_cmnd(line, &(meta->commands));
		free(tmp);
	}
	free(line);
	verif_label(meta->commands);
}
