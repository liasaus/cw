
#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include "op.h"
# include "acurse.h"

# define AND 1
# define OR 2
# define XOR 3

# define OUTPUT_MODE 1
# define INSTRUCTIONS 19
# define MAGIC_COMMENT 97
# define MEM_SIZEX (MEM_SIZE + 1)
# define READLEN 8096

typedef struct		s_visu
{
	int				i;
	int				a;
	int				b;
	int				b_color;
	unsigned int	len_maker;
	int				j;
	int				c;
	int				oo;
}					t_visu;

typedef struct		s_roc
{
	int				j;
	unsigned char	binary[8];
	int				length;
}					t_roc;

typedef struct		s_champ
{
	unsigned char	comments[COMMENT_LENGTH + 1];
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	*prog;
	unsigned int	len_prog;
	unsigned int	live;
}					t_champ;

typedef struct		s_instruc
{
	int				opcode;
	unsigned int	nb_params;
	unsigned int	params[4];
	unsigned int	type_params[4];
}					t_instruc;

typedef struct		s_proc
{
	unsigned int	pc;
	unsigned int	move_pc;
	char			reg[REG_NUMBER][REG_SIZE];
	int				carry;
	int				wait;
	int				new_born;
	int				call_live;
	int				extra_life;
	t_instruc		instruc;
}					t_proc;

typedef struct		s_vm
{
	t_champ			champions[MAX_PLAYERS + 1];
	unsigned int	nb_champions;
	int				cycle_to_die;
	int				cycle_of_death;
	int				nbr_cycle;
	t_proc			**procs;
	int				visu;
	unsigned int	nb_procs;
	size_t			champ_mem_size;
	unsigned char	mem[MEM_SIZE];
	int				cycle;
	unsigned int	last_to_call_live;
	char			**aff_buffer;
}					t_vm;

typedef struct		s_get_procs
{
	int				state;
	int				p_natural[MAX_PLAYERS + 2];
	int				p_ordonate[MAX_PLAYERS + 2];
	char			*t_ordonate[MAX_PLAYERS + 2];
	int				len_ordonate[MAX_PLAYERS + 2];
	char			*t_natural[MAX_PLAYERS + 2];
	int				len_natural[MAX_PLAYERS + 2];
	int				off1;
	int				off2;
	char			*tmp;
	int				lentmp;
	int				nb;
	int				i;
}					t_get_procs;

typedef struct		s_instruction
{
	char			*name;
	int				len;
	int				nb_param;
	char			param_type[3];
	int				opcode;
	int				codage;
	int				dir_size;
	int				cycle;
	int				idx;
	int				offset;
}					t_instruction;

typedef struct		s_file
{
	int				len_str;
	int				len_buff;
	char			*str;
	char			buffer[READLEN + 1];
}					t_file;

extern t_instruction g_instruction[];

void				show_info(t_vm *vm);
unsigned int		get_value_from_mem(unsigned char *mem, unsigned int i);
void				get_champions_init(t_get_procs *g);
void				dl_champ(t_champ *champ, char *champ_binary,
		unsigned int lc);
int					check_array_have(int *t, int len, int what);
unsigned int		get_prog_length(unsigned char *b, int len);
int					magic_number_is_correct(unsigned char *b, int len);
void				fight(t_vm *vm);
int					init_corew(t_vm *vm, char **av);
int					get_champions(char **av, t_vm *vm);
void				hex_dump(unsigned char *memory, int len);
void				output_mode(t_vm *vm);
void				do_opcode(t_vm *vm, int i);
void				fight(t_vm *vm);
void				put_value_inside_reg(unsigned char *reg,
		unsigned int value);
unsigned int		get_value_inside_reg(unsigned char *reg);
void				add_two_reg(unsigned char *reg_dest,
		unsigned char *reg_a, unsigned char *reg_b);
void				sub_two_reg(unsigned char *reg_dest,
		unsigned char *reg_a, unsigned char *reg_b);
void				call_ldi(t_vm *vm, int i);
void				paste_to_mem(unsigned char *src, unsigned char *mem,
		unsigned int i);
void				copy_from_mem(unsigned char *dest, unsigned char *mem,
		unsigned int i);
void				call_live(t_vm *vm, int i);
void				call_add(t_vm *vm, int i);
void				call_sub(t_vm *vm, int i);
void				call_fork(t_vm *vm, int i);
void				call_lfork(t_vm *vm, int i);
void				call_and(t_vm *vm, int i);
void				call_or(t_vm *vm, int i);
void				call_xor(t_vm *vm, int i);
void				call_ld(t_vm *vm, int i);
void				call_ldi(t_vm *vm, int i);
void				call_lld(t_vm *vm, int i);
void				call_lldi(t_vm *vm, int i);
void				background_fork(t_vm *vm, int i);
void				background_bitwise_op(t_vm *vm, int i, int op);
void				flush_buffer(t_vm *vm);
void				output_mode(t_vm *vm);
void				call_aff(t_vm *vm, int i);
void				call_explosion(t_vm *vm, int i);
void				extra_life(t_vm *vm, unsigned int i);
void				kill_proc(t_vm *vm, int i);
void				output_mode(t_vm *vm);
int					read_instruction(t_vm *vm, int i);
unsigned int		read_unsigned_int(unsigned char *mem, int len);
int					reg_correct(int reg_number);

/*
** open the file, read it, store it in a string and return the string
** return NULL if fail (use errno to see the error)
*/
char				*file_get_contents(char *filename);

/*
** same as file_get_contents, but store the string and his length in the
** given parameters
** example of use:
** char	*str;
** int	len;
** if (file_get_binary("my_binary_file.bin", &str, &len))
**		print_binary(str, len); // show the string contains in the file
** else
**	exit(0);
** return 1 if success, or 0 if fail (use errno to see the error)
*/
int					file_get_binary(char *filename, char **str, int *len);

/*
** print the binary string
*/
void				print_binary(char *str, int len);
void				exit_with_error(char *s);
unsigned char		*join_a_b(unsigned char *s, int a, int b);
char				*binary_cat(char *dest, int len_dest, char *src,
		int len_src);
char				*binary_cpy(char *src, char *dest, int len);
void				cpy_a_b(void *new_s, unsigned char *src, int a, int b);
void				init_mem(t_vm *vm);
void				do_opcode(t_vm *vm, int i);
void				call_zjmp(t_vm *vm, int i);
void				call_st(t_vm *vm, int i);
void				call_sti(t_vm *vm, int i);

#endif
