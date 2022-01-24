/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:50:19 by dkramer       #+#    #+#                 */
/*   Updated: 2022/01/19 18:32:39 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

void	sortsmalltobig(int *p, int *stacka, t_str *str, int len)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	p[a] = stacka[i];
	while (a < len)
	{
		i = 0;
		while (i < len)
		{
			if (stacka[i] < p[a] && a == 0)
				p[a] = stacka[i];
			else if (stacka[i] < p[a] && (a > 0 && stacka[i] > p[a - 1]))
				p[a] = stacka[i];
			i++;
		}
		a++;
		if (a < len)
			p[a] = 2147483647;
	}
	str->highestnr = a - 1;
}

int	*indexing(t_str *str, int *stacka, int len)
{
	str->cstacka = ft_calloc(sizeof(int) * len, 1);
	if (!str->cstacka)
		return (returnft(str));
	str->p = malloc(sizeof(int) * len);
	if (!str->p)
		return (returnft(str));
	sortsmalltobig(str->p, stacka, str, len);
	str->a = 0;
	while (str->a < len)
	{
		str->i = 0;
		while (str->i < len)
		{
			if (stacka[str->i] == str->p[str->a])
			{
				str->cstacka[str->i] = str->a;
				break ;
			}
			str->i++;
		}
		str->a++;
	}
	free (stacka);
	free (str->p);
	return (str->cstacka);
}
