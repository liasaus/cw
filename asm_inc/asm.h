
#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include <stdio.h>

# define DEBUG	ft_printf("function: %s, line: %d\n", __FUNCTION__, __LINE__);

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define COMMENT_CHAR			"#;"
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREW_EXEC_MAGIC		0xea83f3

typedef struct				s_header
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COMMENT_LENGTH + 1];
}							t_header;

typedef struct				s_cmnd
{
	char					op_code;
	char					codage;
	char					**params;
	int						size;
	int						address;
	char					**label_find;
	char					*line;
	struct s_cmnd			*next;
}							t_cmnd;

typedef struct				s_label
{
	int						address;
	char					*name;
	struct s_label			*next;
	struct s_label			*prev;
}							t_label;

typedef struct				s_meta
{
	t_header				*header;
	char					*file_out;
	int						fd;
	int						fildes;
	t_cmnd					*commands;
}							t_meta;

typedef struct				s_instruction
{
	char					*name;
	int						len;
	int						nb_param;
	char					param_type[3];
	int						opcode;
	int						codage;
	int						dir_size;
}							t_instruction;

union						u_param
{
	int						i;
	char					tab[4];
};

extern t_instruction	g_instruction[];

extern int			g_address;

extern t_label		**g_labels;

extern int			g_line;

void						put_usage(void);
void						put_error(char *msg);
void						parse_file(t_meta **meta);
int							parse_name(char *line, t_meta **meta);
int							parse_comment(char *line, t_meta **meta);
t_header					*init_theader(void);
void						store_header(t_meta **meta, char *line, int i,
								int is_name);
void						parse_operations(t_meta **meta);
t_label						*new_label(char *name);
void						write_to_file(t_meta *meta_ptr);
void						write_option_a(t_meta *meta_ptr);
char						*ft_strepur(char *str);
void						print_command_list(t_cmnd *list);
void						remove_trailing_whitespace(char *line);
void						add_cmnd_to_end(t_cmnd **list_start, t_cmnd *new);
t_cmnd						*cmnd_new(int size_param, char *line);
void						add_label_start(t_label **list, t_label *elem);
char						*fill_label(char *tmp);
t_cmnd						*find_params(char **line, t_instruction select);
char						*add_param(int value, int size);
int							check_label(char *str);
char						*find_label(char **line);
int							check_num(char **line);
void						verif_label(t_cmnd *cmnd);
int							checkflags(char *flags, char **argv);
void						write_flag_a(t_meta *meta_ptr);
void						print_label(void);
void						rewind_labels(void);
void						next_line(t_cmnd *cmnd, int third_line, int cod,
		t_instruction se);
void						print_param_oct(t_cmnd *cmnd, int i, int limit);
void						check_label_find(t_cmnd *tmp);

#endif
