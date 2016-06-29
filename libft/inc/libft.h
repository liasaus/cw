#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# define BUFF_SIZE 100

typedef struct	s_info
{
	int			fd;
	char		*info;
}				t_info;

typedef struct	s_type
{
	int						n;
	long int				ln;
	long long int			lln;
	unsigned long int		lu;
	unsigned long long int	llu;
	char					*str;
	wchar_t					*wstr;
	uintmax_t				ju;
	intmax_t				j;
	char					c;
	size_t					z;
	double					f;
	unsigned int			octal;
	unsigned int			u;
	unsigned int			x;
	void					*ptr;
}				t_type;

typedef struct	s_flag
{
	int		sp_b;
	int		less_b;
	int		sign_b;
	int		zero_b;
	int		diese_b;
	int		end;
	int		preci;
	int		preci_b;
	int		p_b;
	int		mini;
	int		bonus_base;
	char	modif[2];
}				t_flag;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_conteneur
{
	int				i;
	int				y;
	int				tabs[33];
	char			*s;
	long			r;
}				t_conteneur;

typedef struct	s_conteneur4
{
	size_t	i;
	int		d;
	char	*s2;
}				t_conteneur4;

typedef struct	s_conteneur3
{
	int		i;
	long	res;
	int		coef;
}				t_conteneur3;

void			writex(char *str, size_t length, int print);
size_t			ft_tlen(char **tabs);
char			*ft_dela_to_b(char *s, int a, int b);
char			*ft_litoa(unsigned long long nb);
char			*ft_itoa_base(unsigned long long nb, char base, int size);
int				ft_printf(const char *restrict format, ...);
int				ft_addmodif(const char *restrict pf, t_flag *f);
int				ft_findflag3(const char *restrict pf, t_flag *f);
int				ft_findbonus(const char *restrict format);
int				ft_print_wc(unsigned int c, t_flag *f);
int				ft_print_char(char c, t_flag *f);
int				ft_print_s(char *s, t_flag *f);
int				ft_print_ws(wchar_t *s, t_flag *f);
int				ft_print_valu(unsigned long long int n, t_flag *f, int base);
int				ft_print_val(long long int n, t_flag *f);
void			ft_putnorme(int base, t_flag *f, int upper);
void			ft_mini(int longueur, t_flag *f, long long int *nb);
void			ft_miniu(int longueur, t_flag *f, int b);
void			ft_putns(char *s, int n);
void			ft_putc_r(int q, char c);
int				ret_val(int val, int first);
void			ft_putc(char c);
void			ft_puts(char *s);
void			ft_putnws(wchar_t *s, size_t len);
void			ft_putwchar(unsigned int c);
size_t			ft_wwlen(wchar_t c);
size_t			ft_wwstrlen(wchar_t *s);
size_t			ft_wwstrlen(wchar_t *s);
int				find_ubase(char type, t_flag *f);
int				tbase(char type);
int				utbase(char type);
int				find_dioux(char type, va_list pa, t_flag *f, t_type *t);
int				find_scp(char type, va_list pa, t_flag *flag, t_type *t);
int				ft_findflag(const char *restrict pf, t_flag *f, va_list pa);
void			ft_initflag(t_flag *flag);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *nptr);
long			ft_latoi(const char *s);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
void			*ft_memalloc(size_t size);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset (void *s, int c, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *meule_de_foin, const char *aiguille);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_puttab(char **tabs);
void			ft_putstr_dbcote(const char *s);
int				get_fd(int fd);
int				find_bonus(char type);
int				get_next_line(int const fd, char **line);
int				ft_isspace(int c);

#endif
