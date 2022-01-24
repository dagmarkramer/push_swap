/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radixsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:46:37 by dkramer       #+#    #+#                 */
/*   Updated: 2022/01/19 18:24:27 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	*sort_under3(int *stacka, t_str *str, int len)
{
	if (stacka[0] + 2 == stacka[1])
		rotateames(stacka, str);
	if (stacka[0] == stacka[1] + 2)
		rotateames(stacka, str);
	if (stacka[0] == stacka[1] + 1)
		swapames(stacka, str);
	if (len >= 3 && stacka[2] == 0)
		revrotateames(stacka, str);
	return (stacka);
}

int	*sort(int *stacka, int *stackb, t_str *str)
{
	int	lenb;
	int	i;

	i = 0;
	stacka = indexing(str, stacka, str->lena);
	if (str->error == 1)
		return (0);
	stacka = sort_under3(stacka, str, str->lena);
	if (str->error == 1)
		return (0);
	lenb = str->lenb;
	if (lenb > 1 && stackb[0] < stackb[1])
		swapbmes(stackb, str);
	while (i < lenb)
	{
		stackb = pusha(stackb, &stacka, str);
		if (str->error == 1)
			return (0);
		i++;
	}
	return (stacka);
}

int	*sort_under5(int *stacka, int *stackb, t_str *str)
{
	int	x;
	int	lena;

	lena = str->lena;
	x = 0;
	while (x < lena)
	{
		if (stacka[0] <= 1)
		{
			stacka = pushb(stacka, &stackb, str);
			if (str->error == 1)
				return (0);
		}
		else
			rotateames(stacka, str);
		if (str->lenb == 0 && issorted(str, stacka))
			return (stacka);
		x++;
	}
	return (sort(stacka, stackb, str));
}

void	radixsorting(int *stackb, int **stacka, t_str *str, int i)
{
	int	x;

	x = 0;
	str->beforelena = str->lena;
	while (x < str->beforelena)
	{
		if ((*stacka[0] >> i & 1) == 1)
			rotateames(*stacka, str);
		else
		{
			*stacka = pushb(*stacka, &stackb, str);
			if (str->error == 1)
				return ;
		}
		x++;
	}
	x = 0;
	str->beforelenb = str->lenb;
	while (x < str->beforelenb)
	{
		stackb = pusha(stackb, stacka, str);
		if (str->error == 1)
			return ;
		x++;
	}
}

int	*ft_radixsort(int *stackb, int *stacka, t_str *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str->highestnr)
	{
		str->highestnr = str->highestnr >> 1;
		a++;
	}
	while (i < a && !issorted(str, stacka))
	{
		radixsorting(stackb, &stacka, str, i);
		if (str->error == 1)
			return (0);
		i++;
	}
	return (stacka);
}
