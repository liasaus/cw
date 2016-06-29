
#include "asm.h"

#define NAME_OK		0x1
#define COMMENT_OK	0x2

static void		check_name_comment(int h)
{
	if (!(h & NAME_OK))
		put_error("champion name missing\n");
	if (!(h & COMMENT_OK))
		put_error("champion comment missing\n");
}

void			parse_file(t_meta **meta_ptr)
{
	t_meta		*meta;
	int			h;
	char		*line;
	char		*tmp;

	h = 0;
	meta = *meta_ptr;
	while (h != (NAME_OK | COMMENT_OK) && get_next_line(meta->fd, &line) > 0)
	{
		if ((tmp = ft_strchr(line, '#')))
			*tmp = '\0';
		if ((tmp = ft_strchr(line, ';')))
			*tmp = '\0';
		g_line++;
		if (ft_strstr(line, NAME_CMD_STRING))
			h += parse_name(line, &meta);
		else if (ft_strstr(line, COMMENT_CMD_STRING))
			h += parse_comment(line, &meta);
		else if (*line && !ft_isspace(*line))
			break ;
		free(line);
	}
	check_name_comment(h);
	parse_operations(&meta);
	(meta->fd != 1) ? close(meta->fd) : 0;
}

void			store_header(t_meta **meta, char *line, int i, int is_name)
{
	int			j;

	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
		{
			i++;
			while (ft_isspace(line[i]))
				i++;
			if (line[i] != '\0')
				put_error("invalid chars\n");
			break ;
		}
		if (is_name)
			(*meta)->header->prog_name[j++] = line[i++];
		else
			(*meta)->header->comment[j++] = line[i++];
	}
}

int				parse_name(char *line, t_meta **meta)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((*meta)->header->prog_name[0])
		put_error("already have .name\n");
	if (ft_strlen(line) > PROG_NAME_LENGTH)
		put_error("name too long\n");
	while (ft_isspace(line[i]))
		i++;
	if (!(&(line[i]) == ft_strstr(line, NAME_CMD_STRING)))
		put_error(".name line does not begin with proper cmd\n");
	while (line[i] == NAME_CMD_STRING[j++])
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i++] != '\"')
		put_error("not proper string\n");
	store_header(meta, line, i, 1);
	return (NAME_OK);
}

int				parse_comment(char *line, t_meta **meta)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((*meta)->header->comment[0])
		put_error("already have .comment\n");
	if (ft_strlen(line) > COMMENT_LENGTH)
		put_error("comment too long\n");
	while (ft_isspace(line[i]))
		i++;
	if (!(&(line[i]) == ft_strstr(line, COMMENT_CMD_STRING)))
		put_error(".comment line does not begin with proper cmd\n");
	while (line[i] == COMMENT_CMD_STRING[j++])
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i++] != '\"')
		put_error("not proper string\n");
	store_header(meta, line, i, 0);
	return (COMMENT_OK);
}
