
void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap2(int *xdep, int *xfin, int *ydep, int *yfin)
{
	ft_swap(xdep, xfin);
	ft_swap(ydep, yfin);
}
