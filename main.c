/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:08:53 by dkramer       #+#    #+#                 */
/*   Updated: 2022/01/19 18:33:52 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	*returnft(t_str *str)
{
	ft_putstr_fd("Error\n", 2);
	str->error = 1;
	return (0);
}

int	extrachecks(long long int nmb, int a, t_str *str)
{
	if ((nmb * a == -1))
		str->isminusone = 1;
	if ((nmb * a) > 2147483647)
		return (-1);
	if ((nmb * a) < -2147483648)
		return (-1);
	return (nmb * a);
}

int	issorted(t_str *str, int *stacka)
{
	int	i;
	int	notsorted;

	i = 0;
	notsorted = 0;
	while (i < str->argc - 2)
	{
		if (stacka[i] > stacka[i + 1])
			notsorted = 1;
		i++;
	}
	if (notsorted == 1)
		return (0);
	return (1);
}

int	mainfunction(int **stacka, int *stackb, t_str *str, char **argv)
{
	*stacka = malloc(sizeof(int) * str->argc - 1);
	if (!*stacka)
	{
		returnft(str);
		return (0);
	}
	if (!errors(*stacka, argv, str))
		return (0);
	*stacka = indexing(str, *stacka, str->argc - 1);
	if (str->error == 1)
		return (0);
	if (issorted(str, *stacka))
		return (0);
	if (str->argc - 1 <= 3)
		*stacka = sort_under3(*stacka, str, str->lena);
	else if (str->argc - 1 <= 5)
		*stacka = sort_under5(*stacka, stackb, str);
	else
		*stacka = ft_radixsort(stackb, *stacka, str);
	if (str->error == 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*stacka;
	int		*stackb;
	t_str	str;

	str.error = 0;
	str.argc = argc;
	stacka = NULL;
	stackb = NULL;
	str.lenb = 0;
	str.lena = str.argc - 1;
	if (argc >= 2)
	{
		if (!mainfunction(&stacka, stackb, &str, argv))
			return (0);
	}
	else
		return (0);
	return (1);
}
