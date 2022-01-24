/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:29:27 by dkramer       #+#    #+#                 */
/*   Updated: 2022/01/19 18:33:41 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	ft_specatoi(const char *st, t_str *str)
{
	long long int	nmb;
	int				i;
	int				a;

	nmb = 0;
	i = 0;
	a = 1;
	while (((st[i] >= 9 && st[i] <= 13) || st[i] == 32) && st[i])
		i++;
	if ((st[i] == '-' || st[i] == '+') && st[i])
	{
		if (st[i] == '-')
			a = a * -1;
		i++;
	}
	if (st[i] == '-' || st[i] == '+')
		str->extraminusorplus = 1;
	while (st[i] != '\0' && st[i] >= '0' && st[i] <= '9' && st[i])
	{
		nmb = (nmb * 10) + st[i] - 48;
		i++;
	}
	return (extrachecks(nmb, a, str));
}

int	*noninteger(char **argv, t_str *str)
{
	int	i;
	int	a;

	i = 1;
	while (i < str->argc)
	{
		a = 0;
		while (argv[i][a])
		{
			if (!ft_strrchr("-+0123456789", argv[i][a]))
				return (returnft(str));
			a++;
		}
		i++;
	}
	return ((int *)1);
}

int	*maxint(int *stacka, char **argv, t_str *str)
{
	int	i;
	int	a;

	a = 1;
	i = 0;
	str->isminusone = 0;
	str->extraminusorplus = 0;
	while (i < str->argc - 1 && a < str->argc)
	{
		stacka[i] = ft_specatoi(argv[a], str);
		if (str->extraminusorplus == 1)
			return (returnft(str));
		if (stacka[i] == -1 && str->isminusone != 1)
			return (returnft(str));
		i++;
		a++;
	}
	return ((int *)1);
}

int	*duplicates(char **argv, t_str *str)
{
	char	*save;
	int		i;
	int		a;

	i = 1;
	while (i < str->argc)
	{
		save = argv[i];
		a = 1;
		while (a < str->argc)
		{
			if (!ft_strncmp(save, argv[a], 11) && a != i)
				return (returnft(str));
			a++;
		}
		i++;
	}
	return ((int *)1);
}

/* some arguments are not integers, some arguments are bigger than an integer,
there are duplicates*/
int	*errors(int *stacka, char **argv, t_str *str)
{
	if (!noninteger(argv, str))
		return (0);
	if (!maxint(stacka, argv, str))
		return (0);
	if (!duplicates(argv, str))
		return (0);
	return ((int *)1);
}
