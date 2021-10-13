#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(const char *str)
{
	long	res;
	int		k;

	if (!str)
		exit(1);
	k = 1;
	res = 0;
	if (*str == '-')
		k = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - 48);
	if (*str)
		exit(1);
	res *= k;
	return ((int)res);
}

int		ft_max(int *lst, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (lst[i] > res)
			res = lst[i];
		i++;
	}
	return (res);
}

int		*ft_init(int len)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * len);
	if (!res)
		exit(1);
	i = 0;
	while (i < len)
		res[i++] = 0;
	return (res); 
}

void	ft_counting_sort(int *lst, int div, int len)
{
	int i;
	int indx;
	int *count;
	int *out;

	count = ft_init(10);
	out = ft_init(len);
	i = 0;
	while (i < len)
	{
		indx = (lst[i++] / div) % 10;
		count[indx]++;
	}
	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];
	i = len - 1;
	while (i >= 0)
	{
		indx = (lst[i] / div) % 10;
		out[count[indx] - 1] = lst[i--];
		count[indx]--;
	}
	i = -1;
	while (++i < len)
		lst[i] = out[i];
	free(count);
	free(out);
}

void	radix_sort(int *lst, int len)
{
	int m;
	int div;

	m = ft_max(lst, len);
	div = 1;
	while (m / div)
	{
		ft_counting_sort(lst, div, len);
		div *= 10;
	}
}

int		main(int ac, char *av[])
{
	int	*lst;
	int	i;

	lst = malloc(sizeof(int) * (ac - 1));
	if (!lst)
		exit(1);
	i = -1;
	while (++i < (ac - 1))
		lst[i] = ft_atoi(av[i+1]);
	radix_sort(lst, ac - 1);
	i = 0;
	while (i < (ac - 1))
	{
		printf("%i", lst[i++]);
		if (i < (ac - 1))
			printf(", ");
	}
	printf("\n");
	free(lst);
	return (0);
}
